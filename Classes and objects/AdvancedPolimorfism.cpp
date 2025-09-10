#include <type_traits>
#include <memory>
#include <utility>
#include <iostream>
#include <vector>

class Any {
private:
    struct Base {
        virtual ~Base() = default;
        virtual std::unique_ptr<Base> clone() const = 0;
        virtual const std::type_info& type() const = 0;
    };

    template<typename T>
    struct Derived : Base {
        T value;

        template<typename U>
        Derived(U&& v) : value(std::forward<U>(v)) {}

        std::unique_ptr<Base> clone() const override {
            return std::make_unique<Derived<T>>(value);
        }

        const std::type_info& type() const override {
            return typeid(T);
        }
    };

    std::unique_ptr<Base> ptr_;

public:
    // Default constructor
    Any() noexcept = default;

    // Copy constructor
    Any(const Any& other) : ptr_(other.ptr_ ? other.ptr_->clone() : nullptr) {}

    // Move constructor
    Any(Any&& other) noexcept : ptr_(std::move(other.ptr_)) {}

    // Template constructor for any type
    template<typename T>
    Any(T&& value) : ptr_(std::make_unique<Derived<std::decay_t<T>>>(std::forward<T>(value))) {}

    // Copy assignment
    Any& operator=(const Any& other) {
        if (this != &other) {
            ptr_ = other.ptr_ ? other.ptr_->clone() : nullptr;
        }
        return *this;
    }

    // Move assignment
    Any& operator=(Any&& other) noexcept {
        if (this != &other) {
            ptr_ = std::move(other.ptr_);
        }
        return *this;
    }

    // Template assignment for any type
    template<typename T>
    Any& operator=(T&& value) {
        ptr_ = std::make_unique<Derived<std::decay_t<T>>>(std::forward<T>(value));
        return *this;
    }

    // Type checking
    template<typename T>
    bool is() const {
        return ptr_ && ptr_->type() == typeid(T);
    }

    // Safe casting
    template<typename T>
    T& as() {
        if (!is<T>()) {
            throw std::bad_cast();
        }
        return static_cast<Derived<T>*>(ptr_.get())->value;
    }

    template<typename T>
    const T& as() const {
        if (!is<T>()) {
            throw std::bad_cast();
        }
        return static_cast<const Derived<T>*>(ptr_.get())->value;
    }

    // Unsafe casting (for performance)
    template<typename T>
    T& unsafe_as() {
        return static_cast<Derived<T>*>(ptr_.get())->value;
    }

    bool has_value() const { return ptr_ != nullptr; }
    void reset() { ptr_.reset(); }
};

// Usage example
void demonstrateTypeErasure() {
    Any a = 42;
    Any b = std::string("Hello, World!");
    Any c = std::vector<int>{1, 2, 3, 4, 5};

    std::cout << "a is int: " << a.is<int>() << "\n";
    std::cout << "b is string: " << b.is<std::string>() << "\n";

    try {
        std::cout << "a as int: " << a.as<int>() << "\n";
        std::cout << "b as string: " << b.as<std::string>() << "\n";

        for (const auto& elem : c.as<std::vector<int>>()) {
            std::cout << elem << " ";
        }
        std::cout << "\n";
    } catch (const std::bad_cast& e) {
        std::cout << "Bad cast: " << e.what() << "\n";
    }
}
