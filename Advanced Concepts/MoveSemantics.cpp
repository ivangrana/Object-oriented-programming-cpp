#include <iostream>
#include <vector>
#include <string>

class MyResource {
public:
    // Default constructor
    MyResource() : data(new int[100]) {
        std::cout << "Resource acquired." << std::endl;
    }

    // Copy constructor
    MyResource(const MyResource& other) : data(new int[100]) {
        std::cout << "Resource copied." << std::endl;
        std::copy(other.data, other.data + 100, data);
    }

    // Move constructor
    MyResource(MyResource&& other) noexcept : data(other.data) {
        std::cout << "Resource moved." << std::endl;
        other.data = nullptr; // Leave the moved-from object in a valid state
    }

    // Destructor
    ~MyResource() {
        if (data) {
            std::cout << "Resource released." << std::endl;
            delete[] data;
        }
    }

private:
    int* data;
};

int main() {
    std::cout << "--- Demonstrating Move Semantics ---" << std::endl;

    // Create a vector of MyResource objects
    std::vector<MyResource> resources;

    // The vector will grow, and MyResource objects will be moved instead of copied
    resources.push_back(MyResource());
    resources.push_back(MyResource());
    resources.push_back(MyResource());

    return 0;
}
