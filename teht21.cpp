#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE 100

// Function to compute XOR checksum
unsigned char compute_checksum(const char *sentence) {
    unsigned char checksum = 0;
    while (*sentence && *sentence != '*') {
        checksum ^= *sentence;
        sentence++;
    }
    return checksum;
}

// Function to validate a line
int validate_nmea_line(const char *line) {
    if (line[0] != '$') return 0; // Line must start with $

    char *asterisk = strchr(line, '*');
    if (!asterisk || asterisk - line < 1) return 0; // Must contain '*'

    unsigned char calculated_checksum = compute_checksum(line + 1);

    // Extract checksum from the line (two hex digits after '*')
    unsigned int given_checksum;
    if (sscanf(asterisk + 1, "%2x", &given_checksum) != 1) return 0;

    return calculated_checksum == given_checksum;
}

int main() {
    char filename[100];
    char line[MAX_LINE];

    printf("Enter filename: ");
    scanf("%99s", filename);

    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error: Could not open file %s\n", filename);
        return 1;
    }

    while (fgets(line, sizeof(line), file)) {
        // Remove newline character if present
        line[strcspn(line, "\r\n")] = 0;

        if (validate_nmea_line(line)) {
            printf("[ OK ] %s\n", line);
        } else {
            printf("[FAIL] %s\n", line);
        }
    }

    fclose(file);
    return 0;
}
//
// Created by jamaa on 11.3.2025.
//

#include "teht21.h"
