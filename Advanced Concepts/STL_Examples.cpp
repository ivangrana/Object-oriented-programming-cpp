#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <string>

// A simple struct for demonstration
struct Person {
    std::string name;
    int age;

    // Overload operator< for set ordering
    bool operator<(const Person& other) const {
        return age < other.age;
    }
};

void demonstrate_vector() {
    std::cout << "--- std::vector demonstration ---" << std::endl;
    std::vector<int> numbers = {5, 2, 8, 1, 9};

    std::cout << "Original vector: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Using an STL algorithm
    std::sort(numbers.begin(), numbers.end());

    std::cout << "Sorted vector:   ";
    std::for_each(numbers.begin(), numbers.end(), [](int num) {
        std::cout << num << " ";
    });
    std::cout << std::endl << std::endl;
}

void demonstrate_map() {
    std::cout << "--- std::map demonstration ---" << std::endl;
    std::map<std::string, int> word_counts;

    word_counts["hello"] = 1;
    word_counts["world"] = 2;
    word_counts["hello"]++;

    std::cout << "Word counts:" << std::endl;
    for (const auto& pair : word_counts) {
        std::cout << "'" << pair.first << "': " << pair.second << std::endl;
    }
    std::cout << std::endl;
}

void demonstrate_set() {
    std::cout << "--- std::set demonstration ---" << std::endl;
    std::set<Person> people = {{"Alice", 30}, {"Bob", 25}, {"Charlie", 30}};

    // Note: Charlie will not be inserted because a Person with age 30 already exists
    // and the custom `<` operator only compares age.

    std::cout << "People in the set (ordered by age):" << std::endl;
    for (const auto& person : people) {
        std::cout << person.name << " (" << person.age << ")" << std::endl;
    }
    std::cout << std::endl;
}


int main() {
    demonstrate_vector();
    demonstrate_map();
    demonstrate_set();

    return 0;
}
