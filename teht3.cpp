#include <stdio.h>

int main() {
    int numStudents;

    printf("How many students: ");
    scanf("%d", &numStudents);

    int grades[numStudents];

    // Initialize array with -1
    for (int i = 0; i < numStudents; i++) {
        grades[i] = -1;
    }

    while (1) {
        int studentNum, grade;

        printf("Enter student number (1 - %d) or 0 to stop: ", numStudents);
        scanf("%d", &studentNum);

        if (studentNum == 0) break;
        if (studentNum < 1 || studentNum > numStudents) {
            printf("Invalid student number!\n");
            continue;
        }

        printf("Enter grade (0 - 5) for student %d or -1 to cancel: ", studentNum);
        scanf("%d", &grade);

        if (grade < -1 || grade > 5) {
            printf("Invalid grade!\n");
            continue;
        }

        grades[studentNum - 1] = grade;
    }

    printf("Student   Grade\n");
    for (int i = 0; i < numStudents; i++) {
        printf("%d         %s\n", i + 1, (grades[i] == -1) ? "N/A" : (char[2]){grades[i] + '0', '\0'});
    }

    return 0;
}
//
// Created by jamaa on 27.3.2025.
//

#include "teht3.h"
