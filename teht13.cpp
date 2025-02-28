#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    char filename[100];
    FILE *file;
    int num, count = 0, min = INT_MAX, max = INT_MIN;

    // Get filename from user
    printf("Enter filename: ");
    scanf("%99s", filename);

    // Open file for reading
    file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Cannot open file %s\n", filename);
        return 1;
    }

    // Read integers and find min/max
    while (fscanf(file, "%d", &num) == 1) {
        count++;
        if (num < min) min = num;
        if (num > max) max = num;
    }

    // Close file
    fclose(file);

    // Print results
    if (count > 0) {
        printf("Count: %d\n", count);
        printf("Min: %d\n", min);
        printf("Max: %d\n", max);
    } else {
        printf("No valid numbers found in the file.\n");
    }

    return 0;
}
//
// Created by jamaa on 28.2.2025.
//

#include "teht13.h"
