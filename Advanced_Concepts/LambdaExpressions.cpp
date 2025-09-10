#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::cout << "--- Demonstrating Lambda Expressions ---" << std::endl;

    // Create a vector of integers
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // Use a lambda expression with std::for_each to print each element
    std::cout << "Numbers:";
    std::for_each(numbers.begin(), numbers.end(), [](int n) {
        std::cout << " " << n;
    });
    std::cout << std::endl;

    // Use a lambda expression with std::find_if to find the first even number
    auto it = std::find_if(numbers.begin(), numbers.end(), [](int n) {
        return n % 2 == 0;
    });

    if (it != numbers.end()) {
        std::cout << "First even number found: " << *it << std::endl;
    }

    // A lambda with a capture clause
    int factor = 2;
    std::for_each(numbers.begin(), numbers.end(), [factor](int& n) {
        n *= factor;
    });

    std::cout << "Numbers multiplied by " << factor << ":";
    std::for_each(numbers.begin(), numbers.end(), [](int n) {
        std::cout << " " << n;
    });
    std::cout << std::endl;


    return 0;
}
