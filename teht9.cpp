#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int find_first(const unsigned int *array, unsigned int what) {
    for (int i = 0; array[i] != 0; i++) {
        if (array[i] == what) {
            return i;
        }
    }
    return -1;
}

int main() {
    const int size = 20;
    unsigned int numbers[size];

    srand(time(0)); // Seed random number generator

    // Fill array with random numbers between 1 and 20
    for (int i = 0; i < size - 1; i++) {
        numbers[i] = rand() % 20 + 1;
    }
    numbers[size - 1] = 0; // Zero as the end marker

    // Print the array
    for (int i = 0; i < size; i++) {
        cout << numbers[i] << endl;
    }

    unsigned int search_value;
    while (true) {
        cout << "Enter number to search for (0 to stop): ";
        cin >> search_value;

        if (search_value == 0) {
            break;
        }

        int index = find_first(numbers, search_value);
        if (index != -1) {
            cout << "Number found at index: " << index << endl;
        } else {
            cout << "Not found" << endl;
        }
    }

    return 0;
}
