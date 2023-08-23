#include <iostream>

class Animal {
public:
    void eat() {
        std::cout << "Animal is eating." << std::endl;
    }
};

class Dog : public Animal {  // Dog inherits from Animal
public:
    void bark() {
        std::cout << "Dog is barking." << std::endl;
    }
};

int main() {
    Dog myDog;
    myDog.eat();  // Inherited method from Animal class
    myDog.bark(); // Method from Dog class
    
    return 0;
}
