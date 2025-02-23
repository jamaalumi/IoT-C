#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

int main() {
    char input[MAX_LEN];

    while (1) {
        printf("Enter a string: ");
        if (fgets(input, MAX_LEN, stdin) == NULL) {
            printf("Error reading input. Exiting...\n");
            break;
        }

        // Remove the newline character if present
        size_t len = strlen(input);
        if (len > 0 && input[len - 1] == '\n') {
            input[len - 1] = '\0';
            len--; // Update length after removing newline
        }

        printf("Length of the string: %zu\n", len);

        // Check if the string is "stop"
        if (strcmp(input, "stop") == 0) {
            printf("Stopping program.\n");
            break;
        }
    }

    return 0;
}
//
// Created by jamaa on 14.2.2025.
//

#include "teht10.h"
