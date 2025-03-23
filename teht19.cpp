#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 40

typedef struct menu_item_ {
    char name[50];
    double price;
} menu_item;

int compare_by_name(const void *a, const void *b) {
    return strcmp(((menu_item*)a)->name, ((menu_item*)b)->name);
}

int compare_by_price(const void *a, const void *b) {
    if (((menu_item*)a)->price > ((menu_item*)b)->price) return 1;
    if (((menu_item*)a)->price < ((menu_item*)b)->price) return -1;
    return 0;
}

int main() {
    char filename[100];
    menu_item menu[MAX_ITEMS];
    int count = 0;
    int choice;

    printf("Enter filename: ");
    scanf("%99s", filename);

    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error: Could not open file %s\n", filename);
        return 1;
    }

    while (count < MAX_ITEMS && fscanf(file, "%49[^;]; %lf\n", menu[count].name, &menu[count].price) == 2) {
        count++;
    }

    fclose(file);

    printf("Choose sorting order:\n");
    printf("1. Sort by name\n");
    printf("2. Sort by price\n");
    printf("Enter choice (1 or 2): ");
    scanf("%d", &choice);

    if (choice == 1) {
        qsort(menu, count, sizeof(menu_item), compare_by_name);
    } else if (choice == 2) {
        qsort(menu, count, sizeof(menu_item), compare_by_price);
    } else {
        printf("Invalid choice. Printing unsorted menu.\n");
    }

    printf("%-50s %8s\n", "Item", "Price");
    printf("%-50s %8s\n", "--------------------------------------------------", "--------");
    for (int i = 0; i < count; i++) {
        printf("%-50s %8.2f\n", menu[i].name, menu[i].price);
    }

    return 0;
}
//
// Created by jamaa on 11.3.2025.
//

#include "teht19.h"
