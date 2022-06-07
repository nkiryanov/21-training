#include "door_struct.h"
#include "list.h"

#include <stdlib.h>
#include <stdio.h>


struct node* init(const door* door_ptr) {
    node *head;
    door *door_in_memory;
    head = (struct node*)malloc(sizeof(struct node));
    door_in_memory = (struct door*)malloc(sizeof(struct door));

    if (!(head && door_in_memory))
        exit(1);

    *door_in_memory = *door_ptr;

    head -> door = door_in_memory;
    head -> next = NULL;

    return head;
}

struct node* add_door(struct node* elem, const struct door* door_ptr) {
    struct node* next_elem;
    door *door_in_memory;

    next_elem = (struct node*)malloc(sizeof(struct node));
    door_in_memory = (struct door*)malloc(sizeof(struct door));

    if (!(next_elem && door_in_memory))
        exit(1);

    *door_in_memory = *door_ptr;

    next_elem -> next = elem -> next;
    next_elem -> door = door_in_memory;
    elem -> next = next_elem;

    return next_elem;
}

struct node* find_door(int door_id, struct node* root) {
    struct node* pointer;
    pointer = root;
    while (pointer && pointer -> door -> id != door_id) {
        pointer = pointer -> next;
    }
    return pointer;
}


struct node* remove_door(struct node* elem, struct node* root) {
    struct node* previous_elem;
    struct node* next_elem;
    if (root != elem) {
        previous_elem = root;
        while (previous_elem -> next != elem) {
            previous_elem = previous_elem -> next;
        }
        next_elem = elem -> next;
        previous_elem -> next = next_elem;
    } else {
        next_elem = elem -> next;
    }

    free(elem -> door);
    free(elem);

    return next_elem;
}

void destroy(node* root) {
    while (root) {
        root = remove_door(root, root);
    }
}
