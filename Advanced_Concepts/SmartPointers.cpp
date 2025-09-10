#include <iostream>
#include <memory>
#include <string>

// A sample class to demonstrate smart pointers
class MyClass {
public:
    MyClass(const std::string& name) : name_(name) {
        std::cout << "MyClass " << name_ << " created." << std::endl;
    }

    ~MyClass() {
        std::cout << "MyClass " << name_ << " destroyed." << std::endl;
    }

    void greet() const {
        std::cout << "Hello from MyClass " << name_ << "!" << std::endl;
    }

private:
    std::string name_;
};

void demonstrate_unique_ptr() {
    std::cout << "--- Demonstrating std::unique_ptr ---" << std::endl;

    // Create a unique_ptr that owns a MyClass object
    std::unique_ptr<MyClass> unique_ptr1 = std::make_unique<MyClass>("unique_ptr1");
    unique_ptr1->greet();

    // Transfer ownership to another unique_ptr
    std::unique_ptr<MyClass> unique_ptr2 = std::move(unique_ptr1);
    if (!unique_ptr1) {
        std::cout << "unique_ptr1 is now null." << std::endl;
    }
    unique_ptr2->greet();

    // unique_ptr2 goes out of scope here, and the MyClass object is automatically destroyed.
}

void demonstrate_shared_ptr() {
    std::cout << "\n--- Demonstrating std::shared_ptr ---" << std::endl;

    // Create a shared_ptr that owns a MyClass object
    std::shared_ptr<MyClass> shared_ptr1 = std::make_shared<MyClass>("shared_ptr1");
    std::cout << "shared_ptr1 use count: " << shared_ptr1.use_count() << std::endl;

    {
        // Create another shared_ptr that shares ownership
        std::shared_ptr<MyClass> shared_ptr2 = shared_ptr1;
        std::cout << "shared_ptr1 use count: " << shared_ptr1.use_count() << std::endl;
        std::cout << "shared_ptr2 use count: " << shared_ptr2.use_count() << std::endl;
        shared_ptr2->greet();
    } // shared_ptr2 goes out of scope here, but the MyClass object is not destroyed yet.

    std::cout << "shared_ptr1 use count: " << shared_ptr1.use_count() << std::endl;

    // shared_ptr1 goes out of scope here, and the MyClass object is automatically destroyed.
}

class B; // Forward declaration

class A {
public:
    std::shared_ptr<B> b_ptr;
    ~A() { std::cout << "A destroyed\n"; }
};

class B {
public:
    std::weak_ptr<A> a_ptr; // Use weak_ptr to break the circular reference
    ~B() { std::cout << "B destroyed\n"; }
};

void demonstrate_weak_ptr() {
    std::cout << "\n--- Demonstrating std::weak_ptr for circular references ---" << std::endl;
    std::shared_ptr<A> a = std::make_shared<A>();
    std::shared_ptr<B> b = std::make_shared<B>();
    a->b_ptr = b;
    b->a_ptr = a;
}


int main() {
    demonstrate_unique_ptr();
    demonstrate_shared_ptr();
    demonstrate_weak_ptr();

    return 0;
}
