#include "stack.h"

#include <stdlib.h>
#include <stdio.h>

struct stack* init(const int value) {
    stack* stack_head;
    stack_head = (stack*)malloc(sizeof(struct stack));
    if (stack_head) {
        stack_head -> value = value;
        stack_head -> next = NULL;
    }
    return stack_head;
}

void push(struct stack** head, int const value) {
    stack* new_head;
    new_head = (stack*)malloc(sizeof(struct stack));
    if (new_head) {
        new_head-> value = value;
        new_head -> next = *head;
        *head = new_head;
    }
}

void pop(struct stack** head) {
    stack* new_head;
    if (*head) {
        new_head = (*head) -> next;
        free(*head);
        *head = new_head;
    }
}

void destroy(struct stack** head) {
    while (*head) {
        pop(head);
    }
}
