#ifndef SRC_S21_STRING_TEST_H_
#define SRC_S21_STRING_TEST_H_

void test_s21_strlen_edge_case(void);
void test_s21_strlen_normal(void);
void test_s21_strlen_null_in_the_middle_abnormal(void);

void test_s21_strcmp_null_stings(void);
void test_s21_strcmp_first_string_bigger(void);
void test_s21_strcmp_second_string_bigger(void);

void test_s21_strcpy_from_to_test(void);
void test_s21_strcpy_test_returned_string(void);
void test_s21_strcpy_test_null_string(void);
void test_s21_strcpy_test_null_char_in_the_middle(void);

void test_s21_strcat_null_string(void);
void test_s21_strcat_str1_append_str2(void);
void test_s21_strcat_str1_to_str2_return_appended_string(void);
void test_s21_strcat_null_string_appended_to_str2(void);

void test_s21_strchr_no_char(void);
void test_s21_strchr_null_char_return_null(void);
void test_s21_strchr_existed_char_returns_pointer(void);

void test_s21_strstr_existed_str_returns_pointer(void);
void test_s21_strstr_null_string_returns_null(void);
void test_s21_strstr_non_existed_string_returns_null(void);

void test_s21_strtok_one_delimeter(void);
void test_s21_strtok_three_delimeter_that_used_once(void);
void test_s21_strtok_three_delimeter_that_used_several_times(void);
void test_s21_strtok_source_sting_has_only_delimeters(void);
void test_s21_strtok_source_sting_is_null(void);
void test_s21_strtok_delim_string_is_null(void);
#endif  // SRC_S21_STRING_TEST_H_
