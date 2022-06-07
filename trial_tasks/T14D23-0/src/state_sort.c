#include <stdio.h>
#include <stdlib.h>

#include "data_io.h"
#include "common_functions.h"

int main(void) {
    int mode = -2;
    char* file_path = NULL;
    FILE* file = NULL;
    dt_record* record = NULL;

    file_path = read_string_from_std();
    file = open_binary_rw_file(file_path);
    file = close_binary_file_if_empty(file);

    while (file && mode != -1) {
        mode = get_mode_from_std();

        if (mode == 0) {
            output_file_content_dt_records(file);
        }
        if (mode == 1) {
            sort_asc_records_in_file(file);
            output_file_content_dt_records(file);
        }
        if (mode == 2) {
            record = read_dt_record_from_std();
            if (record) {
                append_record_to_file(file, record);
                sort_asc_records_in_file(file);
                output_file_content_dt_records(file);
                free(record);
            }
        }
    }

    if (file) {
        fclose(file);
    }
}
