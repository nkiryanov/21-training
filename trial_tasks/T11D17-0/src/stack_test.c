#include "stack.h"
#include "stack_test.h"

#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Function `init` tests\n");
    test_stack_init();
    printf("Function `push` tests\n");
    test_stack_push();
    printf("Function `pop` tests\n");
    test_stack_pop_two_item_stack();
    test_stack_pop_one_item_stack();
    test_stack_pop_no_item_return_null();
    printf("Function `destroy` tests\n");
    test_stack_destroy();
    return 0;
}


void test_stack_init(void) {
    stack* head;
    head = init(3);
    printf("\tInitialization: ");

    if (head && head -> value == 3 && NULL == head -> next) {
        printf("SUCCESS\n");
        free(head);
    } else {
        printf("FAIL\n");
    }
}

void test_stack_push(void) {
    stack* head;
    stack* previous_head;
    head = init(3);
    printf("\tAdding second item to stack: ");

    previous_head = head;
    push(&head, 5);

    if (head -> next == previous_head && previous_head -> value == 3
        && head -> value == 5) {
        printf("SUCCESS\n");
        free(previous_head);
        free(head);
    } else {
        printf("FAIL\n");
    }
}

void test_stack_pop_two_item_stack(void) {
    stack* head;
    printf("\tRemoving item from two item stack: ");

    head = init(3);
    push(&head, 5);
    pop(&head);

    if (NULL == head -> next && head -> value == 3) {
        printf("SUCCESS\n");
        free(head);
    } else {
        printf("FAIL\n");
    }
}

void test_stack_pop_one_item_stack(void) {
    stack* head;
    printf("\tRemoving item from one item stack: ");

    head = init(3);
    pop(&head);

    if (NULL == head) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
}

void test_stack_pop_no_item_return_null(void) {
    stack* head;
    printf("\tTrying to remove item from empty stack: ");

    pop(&head);

    if (NULL == head) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
}

void test_stack_destroy(void) {
    stack* head;
    printf("\tDestroyed stack points to zero: ");

    head = init(5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);
    destroy(&head);

    if (NULL == head) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
}
