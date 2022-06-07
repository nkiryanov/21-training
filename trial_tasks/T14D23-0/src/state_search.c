#include <stdio.h>
#include <stdlib.h>

#include "data_io.h"
#include "common_functions.h"

int main(void) {
    char* file_path = NULL;
    FILE* file = NULL;
    date* date = NULL;
    int code;
    int is_code_found = 0;

    file_path = read_string_from_std();
    file = open_binary_rw_file(file_path);
    file = close_binary_file_if_empty(file);

    if (file_path) {
        free(file_path);
    }

    if (file) {
        date = read_date_from_std();
    }
    if (date) {
        is_code_found = search_code_by_date_in_file(file, date, &code);
        free(date);
    }
    if (date && is_code_found) {
        printf("%d", code);
    }
    if (date && !is_code_found) {
        printf("n/a\n");
    }

    if (file) {
        fclose(file);
    }
}
