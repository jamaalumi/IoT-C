#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

int count_words(const char* str, const char *word) {
    if (word == NULL || strlen(word) == 0) {
        return 0;
    }

    int count = 0;
    const char *ptr = str;
    size_t word_len = strlen(word);

    while ((ptr = strstr(ptr, word)) != NULL) {
        count++;
        ptr += word_len; // Move past the current match
    }

    return count;
}

int main() {
    char input[MAX_LEN];
    char word[MAX_LEN];

    while (1) {
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

        printf("Enter a word to count: ");
        if (fgets(word, MAX_LEN, stdin) == NULL) {
            printf("Error reading input. Exiting...\n");
            return 1;
        }

        // Remove the newline character if present
        len = strlen(word);
        if (len > 0 && word[len - 1] == '\n') {
            word[len - 1] = '\0';
        }

        if (strcmp(word, "stop") == 0) {
            printf("Stopping program.\n");
            break;
        }

        int count = count_words(input, word);
        printf("The word '%s' appears %d times in the string.\n", word, count);
    }

    return 0;
}
//
// Created by jamaa on 14.2.2025.
//

#include "teht12.h"
