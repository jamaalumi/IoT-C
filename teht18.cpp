#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int shift_amount;

    while (1) {
        printf("Enter a number (0-15) or negative number to stop: ");
        scanf("%d", &shift_amount);

        if (shift_amount < 0)
            break;

        if (shift_amount < 0 || shift_amount > 15) {
            printf("Invalid input. Please enter a number between 0-15.\n");
            continue;
        }

        int random_num = rand() % 256; // Random 8-bit number
        printf("Random number (hex): %02X\n", random_num);

        int shifted = random_num >> shift_amount;
        int masked = shifted & 0x3F; // Masking to keep bits 0-5

        printf("Shifted and masked (hex): %02X\n", masked);
    }

    return 0;
}
//
// Created by jamaa on 9.3.2025.
//

#include "teht18.h"
