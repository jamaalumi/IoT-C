#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void print_numbers(const int *array, int count) {
    for (int i = 0; i < count; i++) {
        cout.width(8);
        cout << array[i] << endl;
    }
}

int main() {
    const int size = 15;
    int numbers[size];

    srand(time(0)); // Seed random number generator

    // Fill array with random numbers
    for (int i = 0; i < size; i++) {
        numbers[i] = rand() % 100; // Random numbers between 0 and 99
    }

    // Print the array contents
    print_numbers(numbers, size);

    return 0;
}

