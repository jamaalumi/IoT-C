#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

bool generate_password(char *output, int size, const char *word) {
    int word_len = strlen(word);
    int pass_len = word_len * 2 + 1;

    if (pass_len >= size)
        return false;

    const char printable_chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()-_=+";
    int printable_len = strlen(printable_chars);

    output[0] = printable_chars[rand() % printable_len]; // Start with a random character

    for (int i = 0; i < word_len; i++) {
        output[i * 2 + 1] = word[i];                       // Letter from word
        output[i * 2 + 2] = printable_chars[rand() % printable_len]; // Random character
    }

    output[pass_len - 1] = '\0';  // Null-terminate
    return true;
}

int main() {
    srand(time(NULL));
    char word[32], password[65]; // Enough space for longest password

    while (1) {
        printf("Enter a word (or 'stop' to exit): ");
        scanf("%31s", word);

        if (strcmp(word, "stop") == 0)
            break;

        if (generate_password(password, sizeof(password), word))
            printf("Generated Password: %s\n", password);
        else
            printf("Error: Password too long to generate!\n");
    }
    return 0;
}
//
// Created by jamaa on 9.3.2025.
//

#include "teht17.h"
