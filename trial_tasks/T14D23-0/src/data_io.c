#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stddef.h>

#include "data_io.h"
#include "common_functions.h"

int get_mode_from_std(void) {
    int mode = -2;
    char end = '\0';
    int scanf_result = 0;

    scanf_result = scanf("%d", &mode);
    if (scanf_result != 1 || mode < MODE_MIN || mode > MODE_MAX) {
        printf("n/a\n");
        mode = -2;
    }
    while (end != 10) {end = getchar();}
    return mode;
}

char* increase_array_size_if_needed(char *array_ptr, size_t *array_length, const size_t sting_length) {
    if (sting_length + 1 >= *array_length) {
        *array_length += FILENAME_ARRAY_BUFFER;
        array_ptr = (char*)realloc(array_ptr, (*array_length) * sizeof(char));
        if (!array_ptr) {
            perror("Error allocating memory for input string.\n");
            exit(1);
        }
    }
    return array_ptr;
}

char* read_string_from_std(void) {
    char *string = NULL;
    char input_chr = ' ';
    size_t length = 0;
    size_t array_length = 0;

    while (input_chr != '\n') {
        scanf("%c", &input_chr);
        if (input_chr != '\n') {
            length += 1;
            string = increase_array_size_if_needed(string, &array_length, length);
            string[length - 1] = input_chr;
        }
    }
    if (string) {
        string[length] = '\0';
    }
    return string;
}

struct dt_record* read_dt_record_from_std(void) {
    dt_record *record = NULL;
    int scanf_result;
    int year, month, day, hour, minute, sec, status, code;
    char end;

    scanf_result = scanf("%d %d %d %d %d %d %d %d%c",
        &year, &month, &day, &hour, &minute, &sec, &status, &code,
        &end);

    if (scanf_result != 9 || end != '\n') {
        printf("n/a\n");
    } else {
        record = (dt_record*)calloc(1, sizeof(dt_record));
        if (!record) {
            perror("Errors during memory allocation.\n");
            exit(1);
        }
        record -> year = year;
        record -> month = month;
        record -> day = day;
        record -> hour = hour;
        record -> minute = minute;
        record -> sec = sec;
        record -> status = status;
        record -> code = code;
    }

    while (end != '\n') { end = getchar(); }
    return record;
}

struct date* read_date_from_std(void) {
    date *input_date = NULL;
    int scanf_result;
    int day, month, year;
    char end = '\0';

    scanf_result = scanf("%d.%d.%d", &day, &month, &year);
    while (end != '\n') { end = getchar(); }

    if (scanf_result != 3 ||
        day < 0 || day > 31 ||
        month < 0 || month > 12 ||
        year < 0) {
        printf("n/a\n");
    } else {
        input_date = (date*)calloc(1, sizeof(date));
        if (!input_date) {
            perror("Errors during memory allocation.\n");
            exit(1);
        }
        input_date -> day = day;
        input_date -> month = month;
        input_date -> year = year;
    }
    return input_date;
}

void read_date_interval_from_std(struct date **date1, struct date **date2) {
    date input_date1;
    date input_date2;
    int scanf_result;
    char end = '\0';

    scanf_result = scanf("%d.%d.%d %d.%d.%d",
                         &input_date1.day, &input_date1.month, &input_date1.year,
                         &input_date2.day, &input_date2.month, &input_date2.year);
    while (end != '\n') { end = getchar(); }

    if (scanf_result != 6
        || input_date1.day < 0 || input_date1.day > 31
        || input_date2.day < 0 || input_date2.day > 31
        || input_date1.month < 0 || input_date1.month > 12
        || input_date2.month < 0 || input_date2.month > 12
        || input_date1.year < 0 || input_date2.year < 0
        || compare_date(&input_date1, &input_date2) == 1
         ) {
        printf("int n/a\n");
    } else {
        *date1 = (date*)calloc(1, sizeof(date));
        *date2 = (date*)calloc(1, sizeof(date));
        if (!date1 || !date2) {
            perror("Can't allocate memory for dates interval.\n");
            exit(1);
        }
        **date1 = input_date1;
        **date2 = input_date2;
    }
}


FILE* open_binary_rw_file(char *path_to_file) {
    FILE* file = NULL;

    // try to open file to read-write
    file = fopen(path_to_file, "rb+");

    // print error if file couldn't be openned
    if (!file) {
        printf("n/a\n");
    }
    return file;
}

FILE* close_binary_file_if_empty(FILE* pfile) {
    int num_records;

    if (pfile) {
        num_records = get_records_count_in_file(pfile);
        if (num_records == 0) {
            fclose(pfile);
            printf("n/a\n");
            pfile = NULL;
        }
    }
    return pfile;
}

void output_record(FILE* file, int index) {
    dt_record record = read_record_from_file(file, index);
    printf("%d %d %d %d %d %d %d %d\n",
        record.year,
        record.month,
        record.day,
        record.hour,
        record.minute,
        record.sec,
        record.status,
        record.code);
    }

void output_file_content_dt_records(FILE* file) {
    int num_records;

    if (file) {
        num_records = get_records_count_in_file(file);
        for (int i = 0; i < num_records; i++) {
            output_record(file, i);
        }
    }
}
