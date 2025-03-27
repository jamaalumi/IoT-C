#include <stdio.h>

int main() {
    float busPrice, taxiPrice, money;

    // Get ticket prices and available money
    printf("Enter price of bus ticket: ");
    scanf("%f", &busPrice);

    printf("Enter price of taxi: ");
    scanf("%f", &taxiPrice);

    printf("How much money you have: ");
    scanf("%f", &money);

    while (money >= busPrice || money >= taxiPrice) {
        printf("You have %.2f euros left.\n", money);
        printf("Do you want to take\n1) bus (%.2f euros)\n2) taxi (%.2f euros)\n", busPrice, taxiPrice);
        printf("Enter your selection: ");

        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            if (money >= busPrice) {
                money -= busPrice;
                printf("You chose bus.\n");
            } else {
                printf("You don’t have enough money for bus.\n");
            }
        } else if (choice == 2) {
            if (money >= taxiPrice) {
                money -= taxiPrice;
                printf("You chose taxi.\n");
            } else {
                printf("You don’t have enough money for taxi.\n");
            }
        } else {
            printf("Invalid selection.\n");
        }
    }

    printf("You need to walk. Bye\n");
    return 0;
}
//
// Created by jamaa on 27.3.2025.
//

#include "teht1.h"
