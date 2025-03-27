#include <stdio.h>

    int read_range(int low, int high) {
    int num;
    while (1) {
        printf("Enter a number between %d and %d: ", low, high);
        if (scanf("%d", &num) == 1 && num >= low && num <= high)
            return num;
        else {
            while (getchar() != '\n');
            printf("Invalid input!\n");
        }
    }
}

int main() {
    printf("Let's play!\n");

    for (int i = 0; i < 3; i++) {
        printf("Roll a die and enter your result.\n");
        int roll = read_range(1, 6);
        if (roll == 6)
            printf("I got 6. It is a tie!\n");
        else
            printf("I got %d. I win!\n", roll + 1);
    }

    printf("Better luck next time. Bye!\n");
    return 0;
}
//
// Created by jamaa on 27.3.2025.
//

#include "teht5i.h"
