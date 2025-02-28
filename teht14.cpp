#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_LENGTH 80

int main() {
    char filename[100];
    char lines[MAX_LINES][MAX_LENGTH + 1];
    int count = 0;
    FILE *file;

    // Get filename
    printf("Enter filename: ");
    scanf("%99s", filename);

    // Open file for reading
    file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Cannot open file %s\n", filename);
        return 1;
    }

    // Read lines into array
    while (count < MAX_LINES && fgets(lines[count], MAX_LENGTH + 1, file)) {
        lines[count][strcspn(lines[count], "\n")] = '\0'; // Remove newline
        count++;
    }
    fclose(file);

    // Convert to uppercase
    for (int i = 0; i < count; i++) {
        for (int j = 0; lines[i][j]; j++) {
            lines[i][j] = toupper(lines[i][j]);
        }
    }

    // Open file for writing
    file = fopen(filename, "w");
    if (file == NULL) {
        fprintf(stderr, "Error: Cannot write to file %s\n", filename);
        return 1;
    }

    // Write back to file
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s\n", lines[i]);
    }
    fclose(file);

    printf("File successfully converted to uppercase.\n");
    return 0;
}
//
// Created by jamaa on 28.2.2025.
//

#include "teht14.h"
