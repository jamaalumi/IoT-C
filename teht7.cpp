#include <iostream>
#include <limits>

using namespace std;

bool read_positive(int *value) {
    int temp;
    cout << "Enter a positive number: ";
    if (cin >> temp && temp > 0) {
        *value = temp;
        return true;
    } else {
        cout << "Incorrect input" << endl;
        cin.clear(); // Clear error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        return false;
    }
}

int main() {
    int attempts = 0;
    const int max_attempts = 3;
    int guess;

    cout << "Guess how much money I have!" << endl;

    while (attempts < max_attempts) {
        if (read_positive(&guess)) {
            int actual_amount = 2 * guess + 20;
            cout << "You didn’t get it right. I have " << actual_amount << " euros." << endl;
            cout << "Guess how much money I have!" << endl;
        } else {
            attempts++;
        }
    }

    cout << "I give up! See you later!" << endl;
    return 0;
}
