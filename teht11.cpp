#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

int replace_char(char *str, const char *repl) {
    if (strlen(repl) != 2) {
        return 0;
    }

    char old_char = repl[0];
    char new_char = repl[1];
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == old_char) {
            str[i] = new_char;
            count++;
        }
    }

    return count;
}

int main() {
    char input[MAX_LEN];
    char replace[3];

    printf("Enter a string: ");
    if (fgets(input, MAX_LEN, stdin) == NULL) {
        printf("Error reading input. Exiting...\n");
        return 1;
    }

    // Remove the newline character if present
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }

    printf("Enter two characters for replacement (e.g., e3): ");
    if (fgets(replace, sizeof(replace), stdin) == NULL || strlen(replace) < 2) {
        printf("Invalid replacement string. Exiting...\n");
        return 1;
    }

    int count = replace_char(input, replace);

    if (count > 0) {
        printf("Modified string: %s\n", input);
        printf("Number of characters replaced: %d\n", count);
    } else {
        printf("String was not modified.\n");
    }

    return 0;
}
//
// Created by jamaa on 14.2.2025.
//

#include "teht11.h"
