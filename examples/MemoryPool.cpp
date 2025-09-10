#include <cstddef>
#include <new>
#include <stdexcept>
#include <cstring>
#include <iostream>

class AdvancedMemoryPool {
private:
    void* memory_block_;
    size_t block_size_;
    size_t used_memory_;
    size_t alignment_;

public:
    explicit AdvancedMemoryPool(size_t size, size_t alignment = alignof(std::max_align_t))
        : block_size_(size), used_memory_(0), alignment_(alignment) {
        if (alignment_ == 0 || (alignment_ & (alignment_ - 1)) != 0) {
            throw std::invalid_argument("Alignment must be a power of 2");
        }
        memory_block_ = std::aligned_alloc(alignment_, block_size_);
        if (!memory_block_) {
            throw std::bad_alloc();
        }
    }

    ~AdvancedMemoryPool() {
        std::free(memory_block_);
    }

    template<typename T, typename... Args>
    T* construct(Args&&... args) {
        static_assert(std::is_constructible_v<T, Args...>, "Type T must be constructible with given arguments");

        size_t aligned_size = align_size(sizeof(T), alignof(T));
        if (used_memory_ + aligned_size > block_size_) {
            throw std::bad_alloc();
        }

        void* ptr = static_cast<char*>(memory_block_) + used_memory_;
        ptr = std::align(alignof(T), sizeof(T), ptr, block_size_ - used_memory_);

        if (!ptr) {
            throw std::bad_alloc();
        }

        T* object = new(ptr) T(std::forward<Args>(args)...);
        used_memory_ = static_cast<char*>(ptr) - static_cast<char*>(memory_block_) + aligned_size;

        return object;
    }

    template<typename T>
    void destroy(T* ptr) {
        if (ptr && is_within_pool(ptr)) {
            ptr->~T();
        }
    }

    void reset() {
        used_memory_ = 0;
    }

    size_t available_memory() const {
        return block_size_ - used_memory_;
    }

    bool is_within_pool(void* ptr) const {
        char* start = static_cast<char*>(memory_block_);
        char* end = start + block_size_;
        char* p = static_cast<char*>(ptr);
        return p >= start && p < end;
    }

private:
    size_t align_size(size_t size, size_t alignment) const {
        return (size + alignment - 1) & ~(alignment - 1);
    }
};

// Usage example
class ComplexObject {
public:
    ComplexObject(int a, double b, const std::string& c)
        : a_(a), b_(b), str_(c) {
        std::cout << "ComplexObject constructed: " << a_ << ", " << b_ << ", " << str_ << "\n";
    }

    ~ComplexObject() {
        std::cout << "ComplexObject destroyed: " << a_ << ", " << b_ << ", " << str_ << "\n";
    }

    void print() const {
        std::cout << "ComplexObject: " << a_ << ", " << b_ << ", " << str_ << "\n";
    }

private:
    int a_;
    double b_;
    std::string str_;
};

void demonstrateMemoryPool() {
    try {
        AdvancedMemoryPool pool(1024); // 1KB pool

        std::cout << "Available memory: " << pool.available_memory() << " bytes\n";

        auto obj1 = pool.construct<ComplexObject>(42, 3.14, "Hello");
        auto obj2 = pool.construct<ComplexObject>(100, 2.71, "World");

        obj1->print();
        obj2->print();

        std::cout << "Available memory after allocation: " << pool.available_memory() << " bytes\n";

        pool.destroy(obj1);
        pool.destroy(obj2);

        pool.reset();
        std::cout << "Available memory after reset: " << pool.available_memory() << " bytes\n";

    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << "\n";
    }
}
