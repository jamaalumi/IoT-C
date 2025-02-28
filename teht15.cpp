#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 40

typedef struct {
    char name[50];
    double price;
} menu_item;

int main() {
    char filename[100];
    FILE *file;
    menu_item menu[MAX_ITEMS];
    int count = 0;

    // Get filename
    printf("Enter filename: ");
    scanf("%99s", filename);

    // Open file for reading
    file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Cannot open file %s\n", filename);
        return 1;
    }

    // Read data into array
    while (count < MAX_ITEMS && fscanf(file, " %49[^;]; %lf", menu[count].name, &menu[count].price) == 2) {
        count++;
    }
    fclose(file);

    // Print formatted menu
    printf("\n%-50s %8s\n", "Item", "Price");
    printf("----------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-50s %8.2f\n", menu[i].name, menu[i].price);
    }

    return 0;
}
//
// Created by jamaa on 28.2.2025.
//

#include "teht15.h"
