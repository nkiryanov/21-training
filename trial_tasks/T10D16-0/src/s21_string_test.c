#include "s21_string.h"
#include "s21_string_test.h"
#include <stdio.h>

int main() {
    #ifdef strlen_tests
        printf("s21_strlen tests:\n");
        test_s21_strlen_edge_case();
        test_s21_strlen_normal();
        test_s21_strlen_null_in_the_middle_abnormal();
    #endif  // DEBUG

    #ifdef strcmp_tests
        printf("s21_strcmp tests:\n");
        test_s21_strcmp_null_stings();
        test_s21_strcmp_first_string_bigger();
        test_s21_strcmp_second_string_bigger();
    #endif  // strcmp_tests

    #ifdef strcpy_tests
        printf("s21_strcpy:\n");
        test_s21_strcpy_from_to_test();
        test_s21_strcpy_test_returned_string();
        test_s21_strcpy_test_null_string();
        test_s21_strcpy_test_null_char_in_the_middle();
    #endif  // strcpy_tests

    #ifdef strcat_tests
        printf("s21_strcat:\n");
        test_s21_strcat_null_string();
        test_s21_strcat_str1_append_str2();
        test_s21_strcat_str1_to_str2_return_appended_string();
        test_s21_strcat_null_string_appended_to_str2();
    #endif  // strcat_tests

    #ifdef strchr_tests
        printf("s21_strchr:\n");
        test_s21_strchr_no_char();
        test_s21_strchr_null_char_return_null();
        test_s21_strchr_existed_char_returns_pointer();
    #endif  // strchr_tests

    #ifdef strstr_tests
        printf("s21_strstr:\n");
        test_s21_strstr_existed_str_returns_pointer();
        test_s21_strstr_null_string_returns_null();
        test_s21_strstr_non_existed_string_returns_null();
    #endif  // strstr_tests

    #ifdef strtok_tests
        printf("s21_strtok:\n");
        test_s21_strtok_one_delimeter();
        test_s21_strtok_three_delimeter_that_used_once();
        test_s21_strtok_three_delimeter_that_used_several_times();
        test_s21_strtok_source_sting_has_only_delimeters();
        test_s21_strtok_source_sting_is_null();
        test_s21_strtok_delim_string_is_null();
    #endif  // strtok_tests
    return 0;
}


void test_s21_strlen_edge_case(void) {
    // Edge case. The size of string is null
    char *str;
    size_t array_size;
    str = "\0";
    printf("\tCounting len of NULL string `%s`. Size should be `0`", str);
    array_size = s21_strlen(str);
    if (array_size == 0)
        printf("SUCCESS\n");
    else
        printf("FAIL\n");
}


void test_s21_strlen_normal(void) {
    // size of the string should be the number of chars in the `test` string
    char *str;
    size_t array_size;
    str = "test";
    printf("\tCounting len of normal string `%s`. Size should be `4`", str);

    array_size = s21_strlen(str);

    if (array_size != 4)
        printf("FAIL\n");
    else
        printf("SUCCESS\n");
}

void test_s21_strlen_null_in_the_middle_abnormal(void) {
    // size of the string should be the size of chars before null
    char *str;
    size_t array_size;
    str = "test-null-size-17\0test";
    printf("\tCounting len if string with NULL in the middle: ");

    array_size = s21_strlen(str);

    if (array_size != 17)
        printf("FAIL\n");
    else
        printf("SUCCESS\n");
}

void test_s21_strcmp_null_stings(void) {
    // Comparing null strings. Should be equal.
    char *charArray1, *charArray2;
    int result;
    charArray1 = "\0";
    charArray2 = "\0";
    printf(
        "\tComparring NULL strings `%s` is lower that `%s`: ",
        charArray1, charArray2);

    result = s21_strcmp(charArray1, charArray2);

    if (result != 0)
        printf("FAIL\n");
    else
        printf("SUCCESS\n");
}

void test_s21_strcmp_first_string_bigger(void) {
    char *bigger, *lower;
    int result;
    bigger = "BBBB_bigger_string";
    lower = "AAAA_lower_string";
    printf("\tTest that sting `%s` is lower that `%s`: ", lower, bigger);

    result = s21_strcmp(bigger, lower);

    if (result != 1)
        printf("FAIL\n");
    else
        printf("SUCCESS\n");
}

void test_s21_strcmp_second_string_bigger(void) {
    char *lower, *bigger;
    int result;
    lower = "AAAA_lower_string";
    bigger = "BBBB_bigger_string";
    printf("\tTest that sting `%s` is bigger that `%s`: ", bigger, lower);

    result = s21_strcmp(lower, bigger);

    if (result != -1)
        printf("FAIL\n");
    else
        printf("SUCCESS\n");
}


void test_s21_strcpy_from_to_test(void) {
    char *src = "some string copy from";
    char dest[30] = "some string copy to";
    int result;
    printf(
        "\tTry to copy string `%s` to the string array `%s`: ",
        src, dest);

    s21_strcpy(dest, src);

    result = s21_strcmp(dest, src);

    if (result != 0)
        printf("FAIL\n");
    else
        printf("SUCCESS\n");
}

void test_s21_strcpy_test_returned_string(void) {
    char *src = "some string copy from";
    char dest[30];
    char *returned_string;
    int result;
    printf("\tTest that s21_strcpy retuns copied string `%s`: ", src);

    returned_string = s21_strcpy(dest, src);
    result = s21_strcmp(returned_string, dest);

    if (result != 0)
        printf("FAIL\n");
    else
        printf("SUCCESS\n");
}

void test_s21_strcpy_test_null_string(void) {
    char *src = "\0";
    char dest[30];
    int result;
    printf(
        "\tTry to copy NULL string `%s` to the string array `%s`: ",
        src, dest);

    s21_strcpy(dest, src);
    result = s21_strcmp(dest, src);

    if (result != 0)
        printf("FAIL\n");
    else
        printf("SUCCESS\n");
}

void test_s21_strcpy_test_null_char_in_the_middle(void) {
    // Test appending string with NULL in the middle
    char *charArray1 = "some_text_before\0_some_text_after";
    char charArray2[30];
    char *expectedString = "some_text_before";
    int result;
    printf("\tTry to copy string with NULL in the middle to string array: ");

    s21_strcpy(charArray2, charArray1);
    result = s21_strcmp(charArray2, expectedString);

    if (result != 0)
        printf("FAIL\n");
    else
        printf("SUCCESS\n");
}

void test_s21_strcat_null_string(void) {
    // Test appending null string returns same string
    int result;
    char dest[10] = "string1";
    char src_null_str[10] = "";
    printf(
        "\tTry to append NULL string `%s` to the normal string `%s`: ",
        src_null_str, dest);

    s21_strcat(dest, src_null_str);
    result = s21_strcmp("string1", dest);

    if (result != 0)
        printf("FAIL\n");
    else
        printf("SUCCESS\n");
}

void test_s21_strcat_str1_append_str2(void) {
    // Test normal behavior. str2 should be appended in place.
    int result;
    char src[20] = " string1";
    char dest[20] = "string2";
    printf(
        "\tTry to append normal string `%s` to the normal string `%s`: ",
        src, dest);

    s21_strcat(dest, src);
    result = s21_strcmp("string2 string1", dest);

    if (result != 0)
        printf("FAIL\n");
    else
        printf("SUCCESS\n");
}

void test_s21_strcat_str1_to_str2_return_appended_string(void) {
     // Test normal behavior. strcat should return pointer to appended string.
    int result;
    char src[20] = " string1";
    char dest[20] = "string2";
    char *appended_str;
    printf("\tLike previous, but we are looking on returning value (not pointer). :");

    appended_str = s21_strcat(dest, src);
    result = s21_strcmp("string2 string1", appended_str);

    if (result != 0)
        printf("FAIL\n");
    else
        printf("SUCCESS\n");
}

void test_s21_strcat_null_string_appended_to_str2(void) {
     // Test normal behavior. strcat should return pointer to appended string.
    int result;
    char dest[20] = "";
    char src[20] = "appended_string";
    printf(
        "\tTry to append string `%s` to the NULL string `%s`: ",
        src, dest);

    s21_strcat(dest, src);
    result = s21_strcmp("appended_string", dest);

    if (result != 0)
        printf("FAIL\n");
    else
        printf("SUCCESS\n");
}

void test_s21_strchr_no_char(void) {
     // Try to find non existed char in the string. Should return NULL.
    char str[20] = "sometext";
    char non_existed_char = 'a';
    char *result;
    printf(
        "\tTry to find null char `%c` in the string `%s`: ",
        non_existed_char, str);

    result = s21_strchr(str, non_existed_char);

    if (!result)
        printf("SUCCESS\n");
    else
        printf("FAIL\n");
}

void test_s21_strchr_null_char_return_null(void) {
     // Try to find non 0 char in the string. Should return NULL.
    char str[20] = "sometext";
    char null_char = '\0';
    char *result;
    printf(
        "\tTry to find null char `%c` in the string `%s`: ",
        null_char, str);

    result = s21_strchr(str, null_char);

    if (!result)
        printf("SUCCESS\n");
    else
        printf("FAIL\n");
}

void test_s21_strchr_existed_char_returns_pointer(void) {
     // Try to find existed char in the string. Should return pointer.
    char str[20] = "sometext";
    char *first_char = str + 4;
    char looking_char = 't';
    char *result;
    printf(
        "\tTry to find existed char `%c` in the string `%s`: ",
        looking_char, str);

    result = s21_strchr(str, looking_char);

    if (result == first_char)
        printf("SUCCESS\n");
    else
        printf("FAIL\n");
}

void test_s21_strstr_existed_str_returns_pointer(void) {
     // Try to find existed string in the string. Should return pointer.
    char str[20] = "sometext_text";
    char *existed_string = "text";
    char *first_str = str + 4;
    char *result;
    printf(
        "\tTry to find existed string `%s` in the string `%s`: ",
        existed_string, str);

    result = s21_strstr(str, existed_string);

    if (result == first_str)
        printf("SUCCESS\n");
    else
        printf("FAIL\n");
}

void test_s21_strstr_null_string_returns_null(void) {
     // Try to find 0 string in a string. Should return NULL
    char str[20] = "sometext_text";
    char *null_stirng = "\0";
    char *result;
    printf(
        "\tTry to find NULL string `%s` in the string `%s`: ",
        null_stirng, str);

    result = s21_strstr(str, null_stirng);

    if (!result)
        printf("SUCCESS\n");
    else
        printf("FAIL\n");
}

void test_s21_strstr_non_existed_string_returns_null(void) {
     // Try to find non existed string in the string. Should return NULL.
    char str[20] = "sometext_text";
    char *non_existed_str = "textt";
    char *result;
    printf(
        "\tTry to find non existed string `%s` in the string `%s`: ",
        non_existed_str, str);

    result = s21_strstr(str, non_existed_str);

    if (!result)
        printf("SUCCESS\n");
    else
        printf("FAIL\n");
}

void test_s21_strtok_one_delimeter(void) {
     // Try to cut the string with space delimeter
    char str[20] = "word1 word2 word3";
    char delim[20] = " ";
    char *token;
    int result = 1;
    printf("\tTrying to cat sting `%s` with delimeter `%s`: ", str, delim);

    token = s21_strtok(str, delim);
    result = (result && s21_strcmp(token, "word1") == 0) ? 1 : 0;

    token = s21_strtok(NULL, delim);
    result = (result && s21_strcmp(token, "word2") == 0) ? 1 : 0;

    token = s21_strtok(NULL, delim);
    result = (result && s21_strcmp(token, "word3") == 0) ? 1 : 0;

    token = s21_strtok(NULL, delim);
    result = (result && NULL == token) ? 1 : 0;

    if (result)
        printf("SUCCESS\n");
    else
        printf("FAIL\n");
}

void test_s21_strtok_three_delimeter_that_used_once(void) {
     // Try to cut the string with space delimeter
    char str[50] = "word1 word2,word3;word4";
    char delim[20] = " ,;";
    char *token;
    int result = 1;
    printf("\tTrying to cat sting `%s` with delimeters `%s`: ", str, delim);

    token = s21_strtok(str, delim);
    result = (result && s21_strcmp(token, "word1") == 0) ? 1 : 0;

    token = s21_strtok(NULL, delim);
    result = (result && s21_strcmp(token, "word2") == 0) ? 1 : 0;

    token = s21_strtok(NULL, delim);
    result = (result && s21_strcmp(token, "word3") == 0) ? 1 : 0;

    token = s21_strtok(NULL, delim);
    result = (result && s21_strcmp(token, "word4") == 0) ? 1 : 0;

    token = s21_strtok(NULL, delim);
    result = (result && NULL == token) ? 1 : 0;

    if (result)
        printf("SUCCESS\n");
    else
        printf("FAIL\n");
}

void test_s21_strtok_three_delimeter_that_used_several_times(void) {
     // Try to cut the string with space delimeter
    char str[50] = "word1 word2, ;word3;,word4;";
    char delim[20] = " ,;";
    char *token;
    int result = 1;
    printf("\tTrying to cat sting `%s` with delimeters `%s`: ", str, delim);

    token = s21_strtok(str, delim);
    result = (result && s21_strcmp(token, "word1") == 0) ? 1 : 0;

    token = s21_strtok(NULL, delim);
    result = (result && s21_strcmp(token, "word2") == 0) ? 1 : 0;

    token = s21_strtok(NULL, delim);
    result = (result && s21_strcmp(token, "word3") == 0) ? 1 : 0;

    token = s21_strtok(NULL, delim);
    result = (result && s21_strcmp(token, "word4") == 0) ? 1 : 0;

    token = s21_strtok(NULL, delim);
    result = (result && NULL == token) ? 1 : 0;

    if (result)
        printf("SUCCESS\n");
    else
        printf("FAIL\n");
}

void test_s21_strtok_source_sting_has_only_delimeters(void) {
     // Try to cut the string with space delimeter
    char str[50] = " ,;  , ;,,,,,;;  ;,";
    char delim[20] = " ,;";
    char *token;
    int result = 1;
    printf("\tTrying to cat sting `%s` with delimeters `%s`: ", str, delim);

    token = s21_strtok(str, delim);
    result = (result && NULL == token) ? 1 : 0;

    token = s21_strtok(NULL, delim);
    result = (result && NULL == token) ? 1 : 0;

    if (result)
        printf("SUCCESS\n");
    else
        printf("FAIL\n");
}

void test_s21_strtok_source_sting_is_null(void) {
     // Try to cut the string with space delimeter
    char *str = NULL;
    char delim[20] = " ,;";
    char *token;
    int result = 1;
    printf("\tTrying to cat null string with delimeters `%s`: ", delim);

    token = s21_strtok(str, delim);
    result = (result && NULL == token) ? 1 : 0;

    token = s21_strtok(NULL, delim);
    result = (result && NULL == token) ? 1 : 0;

    if (result)
        printf("SUCCESS\n");
    else
        printf("FAIL\n");
}

void test_s21_strtok_delim_string_is_null(void) {
     // Try to cut the string with space delimeter
    char str[50] = "some text";
    char *delim = NULL;
    char *token;
    int result = 1;
    printf("\tTrying to cat string `%s` with NULL delimeters: ", str);

    token = s21_strtok(str, delim);
    result = (result && NULL == token) ? 1 : 0;

    token = s21_strtok(NULL, delim);
    result = (result && NULL == token) ? 1 : 0;

    if (result)
        printf("SUCCESS\n");
    else
        printf("FAIL\n");
}
