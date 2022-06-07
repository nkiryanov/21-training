#ifndef SRC_LIST_TEST_H_
#define SRC_LIST_TEST_H_

void test_node_init_allocates_memory(void);
void test_node_init_initial_data_valid(void);
void test_node_add_door_next_to_head(void);
void test_node_add_door_after_second_item(void);

void test_node_find_door_in_head(void);
void test_node_find_door_in_middle(void);
void test_node_find_door_there_is_no_door_with_that_id(void);

void test_node_remove_door_removing_head_returns_second_elem(void);
void test_node_remove_door_removing_last_returns_null(void);
void test_node_remove_door_removing_middle_returns_last(void);

void test_node_destroy(void);

#endif  // SRC_LIST_TEST_H_
