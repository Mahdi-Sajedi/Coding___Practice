#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono> // Include chrono for time measurement

const int SIZE = 1000000; // Number of elements to add

int main() {
    // Seed the random number generator
    std::srand(std::time(0));

    // Create two vectors to hold the numbers
    std::vector<int> array1(SIZE);
    std::vector<int> array2(SIZE);
    std::vector<int> sum(SIZE);

    // Fill the arrays with random numbers
    for (int i = 0; i < SIZE; ++i) {
        array1[i] = std::rand() % 100; // Random numbers between 0 and 99
        array2[i] = std::rand() % 100;
    }

    // Start the timer
    auto start = std::chrono::high_resolution_clock::now();

    // Add the two arrays
    for (int i = 0; i < SIZE; ++i) {
        sum[i] = array1[i] + array2[i];
    }

    // Stop the timer
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start; // Calculate duration

    // Optional: Print the first 10 results for verification
    std::cout << "Sum of first 10 pairs:\n";
    for (int i = 0; i < 10; ++i) {
        std::cout << "array1[" << i << "] + array2[" << i << "] = " << sum[i] << "\n";
    }

    // Print the time taken
    std::cout << "Time taken to add " << SIZE << " numbers: " << duration.count() << " seconds.\n";

    return 0;
}
