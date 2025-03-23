#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COURSES 50
#define MAX_STUDENTS 100
#define MAX_NAME_LENGTH 100
#define FILE_NAME "transcript.txt"

// Data structures
typedef struct {
    char name[MAX_NAME_LENGTH];
    int credits;
} Course;

typedef struct {
    char student[MAX_NAME_LENGTH];
    int grade;
} StudentGrade;

typedef struct {
    Course course;
    StudentGrade students[MAX_STUDENTS];
    int student_count;
} CourseRecord;

// Function prototypes
void trim_whitespace(char *str);
int read_file(const char *filename, CourseRecord courses[], int *course_count);
void print_transcript(const char *student_name, CourseRecord courses[], int course_count);
double calculate_average(int grades[], int count);

int main() {
    CourseRecord courses[MAX_COURSES];
    int course_count = 0;

    // Read data from file
    if (!read_file(FILE_NAME, courses, &course_count)) {
        printf("Error reading file.\n");
        return 1;
    }

    char student_name[MAX_NAME_LENGTH];
    while (1) {
        printf("Enter student's name (or 'stop' to quit): ");
        fgets(student_name, MAX_NAME_LENGTH, stdin);
        trim_whitespace(student_name);

        if (strcmp(student_name, "stop") == 0) {
            break;
        }
        print_transcript(student_name, courses, course_count);
    }
    return 0;
}

// Function to trim whitespace
void trim_whitespace(char *str) {
    char *end;
    while (*str == ' ') str++;  // Trim leading space
    end = str + strlen(str) - 1;
    while (end > str && *end == ' ') end--;  // Trim trailing space
    *(end + 1) = '\0';
}

// Function to read file and parse data
int read_file(const char *filename, CourseRecord courses[], int *course_count) {
    FILE *file = fopen(filename, "r");
    if (!file) return 0;

    char line[256];
    CourseRecord *current_course = NULL;

    while (fgets(line, sizeof(line), file)) {
        trim_whitespace(line);
        if (strlen(line) == 0) continue; // Ignore empty lines

        if (line[0] == '[') {
            // Parsing a course
            char *colon = strchr(line, ':');
            if (!colon) continue;

            *colon = '\0';
            strcpy(courses[*course_count].course.name, line + 1);
            courses[*course_count].course.credits = atoi(colon + 1);
            courses[*course_count].student_count = 0;
            current_course = &courses[*course_count];
            (*course_count)++;
        } else if (current_course) {
            // Parsing a student and grade
            char *colon = strchr(line, ':');
            if (!colon) continue;

            *colon = '\0';
            strcpy(current_course->students[current_course->student_count].student, line);
            current_course->students[current_course->student_count].grade = atoi(colon + 1);
            current_course->student_count++;
        } else {
            printf("Error: Student found before a course definition: %s\n", line);
        }
    }
    fclose(file);
    return 1;
}

// Function to print a student's transcript
void print_transcript(const char *student_name, CourseRecord courses[], int course_count) {
    int grades[MAX_COURSES];
    int grade_count = 0;

    printf("------------------------------------------\n");
    printf("Student: %s\n", student_name);
    printf("------------------------------------------\n");
    printf("%-30s %-5s\n", "Course", "Grade");
    printf("------------------------------------------\n");

    for (int i = 0; i < course_count; i++) {
        for (int j = 0; j < courses[i].student_count; j++) {
            if (strcmp(courses[i].students[j].student, student_name) == 0) {
                printf("%-30s %d\n", courses[i].course.name, courses[i].students[j].grade);
                grades[grade_count++] = courses[i].students[j].grade;
            }
        }
    }

    if (grade_count == 0) {
        printf("No records found for %s.\n", student_name);
    } else {
        printf("------------------------------------------\n");
        printf("Average Grade: %.2f\n", calculate_average(grades, grade_count));
        printf("------------------------------------------\n");
    }
}

// Function to calculate the average grade
double calculate_average(int grades[], int count) {
    if (count == 0) return 0;
    int sum = 0;
    for (int i = 0; i < count; i++) {
        sum += grades[i];
    }
    return (double)sum / count;
}
//
// Created by jamaa on 22.3.2025.
//

#include "project.h"
