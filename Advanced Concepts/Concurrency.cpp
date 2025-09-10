#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

// A shared variable
int shared_counter = 0;

// A mutex to protect the shared variable
std::mutex mtx;

// Function to be executed by threads
void increment_counter() {
    for (int i = 0; i < 1000; ++i) {
        // Lock the mutex before accessing the shared variable
        std::lock_guard<std::mutex> lock(mtx);
        shared_counter++;
    }
}

int main() {
    // Create a vector of threads
    std::vector<std::thread> threads;

    // Create and start 10 threads
    for (int i = 0; i < 10; ++i) {
        threads.push_back(std::thread(increment_counter));
    }

    // Wait for all threads to finish
    for (auto& th : threads) {
        th.join();
    }

    // Print the final value of the shared counter
    std::cout << "Final counter value: " << shared_counter << std::endl;

    return 0;
}
