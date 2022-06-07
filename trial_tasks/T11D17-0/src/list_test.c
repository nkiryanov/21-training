#include "door_struct.h"
#include "list.h"
#include "list_test.h"

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    printf("Function `init` tests\n");
    test_node_init_allocates_memory();
    test_node_init_initial_data_valid();

    printf("Function `add_door` tests\n");
    test_node_add_door_next_to_head();
    test_node_add_door_after_second_item();

    printf("Function `find_door` tests\n");
    test_node_find_door_in_head();
    test_node_find_door_in_middle();
    test_node_find_door_there_is_no_door_with_that_id();

    printf("Function `remove_door` tests\n");
    test_node_remove_door_removing_head_returns_second_elem();
    test_node_remove_door_removing_last_returns_null();
    test_node_remove_door_removing_middle_returns_last();

    printf("Function `destroy` tests\n");
    test_node_destroy();

    return 0;
}

void create_three_nodes_linked_list(node **head, node **first, node **second) {
    door door1 = {10, 1};
    door door2 = {20, 0};
    door door3 = {30, 1};

    *head = init(&door1);
    *first = add_door(*head, &door2);
    *second = add_door(*first, &door3);
}

void destruct_three_nodes_linked_list(node *head, node *first, node *second) {
    if (head) {
        free(head -> door);
        free(head);
    }
    if (first) {
        free(first -> door);
        free(first);
    }
    if (second) {
        free(second -> door);
        free(second);
    }
}

void test_node_init_allocates_memory() {
    door door_item = {10, 1};
    node *node_item;

    printf("\tmemory allocation: ");

    node_item = init(&door_item);

    if (node_item) {
        printf("FAIL\n");
        free(node_item -> door);
        free(node_item);
    } else {
        printf("SUCCSESS\n");
    }
}

void test_node_init_initial_data_valid() {
    door door_item = {10, 1};
    node *node_item;

    printf("\tinitial variables set correctly: ");

    node_item = init(&door_item);

    if (node_item -> door -> id == door_item.id &&
        node_item -> door -> status == door_item.status &&
        NULL == node_item -> next) {
        printf("SUCCSESS\n");
    } else {
        printf("FAIL\n");
    }

    free(node_item -> door);
    free(node_item);
}

void test_node_add_door_next_to_head() {
    node* head;
    node* next_node;
    door door_head_node = {10, 1};
    door door_next_node = {20, 0};

    printf("\tadd_door after head: ");

    head = init(&door_head_node);
    next_node = add_door(head, &door_next_node);

    if (head -> next == next_node &&
        next_node -> door -> id == door_next_node.id
        && next_node -> door -> status == door_next_node.status
        && next_node -> next == NULL)
        printf("SUCCESS\n");
    else
        printf("FAIL\n");

    free(head -> door);
    free(head);
    free(next_node -> door);
    free(next_node);
}


void test_node_add_door_after_second_item() {
    node* head;
    node* first_next_node;
    node* second_next_node;
    printf("\tadd_door after second elem: ");
    create_three_nodes_linked_list(&head, &first_next_node, &second_next_node);

    if (first_next_node -> next == second_next_node
        && second_next_node -> door -> id == 30
        && second_next_node -> door -> status == 1
        && second_next_node -> next == NULL)
        printf("SUCCESS\n");
    else
        printf("FAIL\n");

    destruct_three_nodes_linked_list(head, first_next_node, second_next_node);
}


void test_node_find_door_in_head(void) {
    node* head;
    node* second_elem;
    node* third_elem;
    node* found_node;
    printf("\tTry to find door by id (located at head): ");
    create_three_nodes_linked_list(&head, &second_elem, &third_elem);

    found_node = find_door(10, head);

    if (found_node == head)
        printf("SUCCESS\n");
    else
        printf("FAIL\n");
    destruct_three_nodes_linked_list(head, second_elem, third_elem);
}

void test_node_find_door_in_middle(void) {
    node* head;
    node* second_elem;
    node* third_elem;
    node* found_node;
    printf("\tTry to find door by id (located in the middle of the list): ");
    create_three_nodes_linked_list(&head, &second_elem, &third_elem);

    found_node = find_door(30, head);

    if (found_node == third_elem)
        printf("SUCCESS\n");
    else
        printf("FAIL\n");

    destruct_three_nodes_linked_list(head, second_elem, third_elem);
}

void test_node_find_door_there_is_no_door_with_that_id(void) {
    node* head;
    node* second_elem;
    node* third_elem;
    node* found_node;
    printf("\tTry to find door by id (no door with that id): ");
    create_three_nodes_linked_list(&head, &second_elem, &third_elem);

    found_node = find_door(50, head);

    if (NULL == found_node)
        printf("SUCCESS\n");
    else
        printf("FAIL\n");

    destruct_three_nodes_linked_list(head, second_elem, third_elem);
}

void test_node_remove_door_removing_head_returns_second_elem(void) {
    node* head;
    node* second_elem;
    node* third_elem;
    node* tmp_node;
    printf("\tTry remove head elem: ");
    create_three_nodes_linked_list(&head, &second_elem, &third_elem);

    // printf("head=%p, second_elem=%p, third=%p\n", head, second_elem, third_elem);

    tmp_node = remove_door(head, head);
    // printf("head=%p, second_elem=%p, third=%p, tmp_node=%p\n", head, second_elem, third_elem, tmp_node);

    if (tmp_node == second_elem)
        printf("SUCCESS\n");
    else
        printf("FAIL\n");

    destruct_three_nodes_linked_list(NULL, second_elem, third_elem);
}

void test_node_remove_door_removing_last_returns_null(void) {
    node* head;
    node* second_elem;
    node* third_elem;
    node* tmp_node;
    printf("\tTry remove last elem: ");
    create_three_nodes_linked_list(&head, &second_elem, &third_elem);

    tmp_node = remove_door(third_elem, head);

    if (NULL == tmp_node)
        printf("SUCCESS\n");
    else
        printf("FAIL\n");
    destruct_three_nodes_linked_list(head, second_elem, NULL);
}

void test_node_remove_door_removing_middle_returns_last(void) {
    node* head;
    node* second_elem;
    node* third_elem;
    node* tmp_node;
    printf("\tTry remove middle elem: ");
    create_three_nodes_linked_list(&head, &second_elem, &third_elem);

    tmp_node = remove_door(second_elem, head);

    if (tmp_node == third_elem)
        printf("SUCCESS\n");
    else
        printf("FAIL\n");
    destruct_three_nodes_linked_list(head, NULL, third_elem);
}

void test_node_destroy() {
    node* head;
    node* second_elem;
    node* third_elem;
    printf("\tTry to destroy linked list: ");
    create_three_nodes_linked_list(&head, &second_elem, &third_elem);

    destroy(head);

    printf("SUCCESS\n");
}
