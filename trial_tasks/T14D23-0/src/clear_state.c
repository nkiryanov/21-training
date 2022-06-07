#include <stdio.h>
#include <stdlib.h>

#include "data_io.h"
#include "common_functions.h"

int main(void) {
    char* filename = NULL;
    FILE* file = NULL;
    date *date1 = NULL;
    date *date2 = NULL;

    filename = read_string_from_std();
    file = open_binary_rw_file(filename);
    file = close_binary_file_if_empty(file);

    if (file) {
        read_date_interval_from_std(&date1, &date2);
    }

    if (date1 && date2) {
        output_file_content_dt_records(file);
        int num_deleted = delete_records_by_date_interval(&file, filename, date1, date2);
        if (num_deleted > 0) {
            output_file_content_dt_records(file);
        }
        printf("num_deleted=%d\n", num_deleted);
        free(filename);
        fclose(file);
    }
}
