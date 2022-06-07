#ifndef SRC_STACK_H_
#define SRC_STACK_H_

typedef struct stack {
    int value;
    struct stack* next;
} stack;

struct stack* init(const int value);
void push(stack** head, int const value);
void pop(struct stack** head);
void destroy(struct stack** head);

#endif  // SRC_STACK_H_
