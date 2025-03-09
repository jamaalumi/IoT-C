#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int number;
    struct node *next;
} nnode;

void free_list(nnode *head) {
    while (head) {
        nnode *temp = head;
        head = head->next;
        free(temp);
    }
}

void print_list(nnode *head) {
    printf("Entered numbers: ");
    while (head) {
        printf("%d ", head->number);
        head = head->next;
    }
    printf("\n");
}

int main() {
    nnode *head = NULL, *tail = NULL;
    char input[20];

    while (1) {
        printf("Enter a number or 'end' to stop: ");
        scanf("%s", input);

        if (strcmp(input, "end") == 0)
            break;

        char *endptr;
        int num = strtol(input, &endptr, 10);

        if (*endptr != '\0') {
            printf("Invalid input. Please enter a valid number.\n");
            continue;
        }

        nnode *new_node = malloc(sizeof(nnode));
        if (!new_node) {
            printf("Memory allocation failed!\n");
            break;
        }
        new_node->number = num;
        new_node->next = NULL;

        if (!head)
            head = tail = new_node;
        else {
            tail->next = new_node;
            tail = new_node;
        }
    }

    print_list(head);
    free_list(head);
    return 0;
}
//
// Created by jamaa on 9.3.2025.
//

#include "teht.h"
