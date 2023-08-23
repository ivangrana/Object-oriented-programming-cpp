#include <iostream>

class Person {
public:
    // Constructor with parameters
    Person(int value) {
        data = value;
        std::cout << "Constructor called with value: " << value << std::endl;
    }

    void display() { //only this method can access private
        std::cout << "Data: " << data << std::endl;
    }

private:
    int data;
};

int main() {
    // Creating objects using the constructor
    Person obj1(42);
    Person obj2(123);

    // Calling member function
    // cout << obj1.data << endl; would cause an error due to private access.
    obj1.display();
    obj2.display();
}
