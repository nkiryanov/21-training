#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "common_functions.h"
#include "data_io.h"

struct dt_record read_record_from_file(FILE *pfile, int index) {
    int offset = index * sizeof(struct dt_record);
    fseek(pfile, offset, SEEK_SET);

    struct dt_record record;
    fread(&record, sizeof(struct dt_record), 1, pfile);
    rewind(pfile);

    return record;
}

struct date read_date_from_file(FILE *pfile, int index) {
    struct dt_record record = read_record_from_file(pfile, index);
    struct date date;

    date.day = record.day;
    date.month = record.month;
    date.year = record.year;
    return date;
}

void write_record_in_file(FILE *pfile, const struct dt_record *record_to_write, int index) {
    int offset = index * sizeof(struct dt_record);
    fseek(pfile, offset, SEEK_SET);
    fwrite(record_to_write, sizeof(struct dt_record), 1, pfile);
    fflush(pfile);
    rewind(pfile);
}

void append_record_to_file(FILE *pfile, const struct dt_record *record_to_write) {
    fseek(pfile, 0, SEEK_END);
    fwrite(record_to_write, sizeof(struct dt_record), 1, pfile);
    fflush(pfile);
    rewind(pfile);
}

void swap_records_in_file(FILE *pfile, int record_index1, int record_index2) {
    struct dt_record record1 = read_record_from_file(pfile, record_index1);
    struct dt_record record2 = read_record_from_file(pfile, record_index2);

    write_record_in_file(pfile, &record1, record_index2);
    write_record_in_file(pfile, &record2, record_index1);
}

int get_file_size_in_bytes(FILE *pfile) {
    int size = 0;
    fseek(pfile, 0, SEEK_END);
    size = ftell(pfile);
    fseek(pfile, 0, SEEK_SET);
    return size;
}

int get_records_count_in_file(FILE *pfile) {
    return get_file_size_in_bytes(pfile) / sizeof(struct dt_record);
}

int compare_records_in_file(FILE *pfile, int record_index_left, int record_index_right) {
    struct dt_record record_left = read_record_from_file(pfile, record_index_left);
    struct dt_record record_right = read_record_from_file(pfile, record_index_right);

    int is_still_same = 0;

    if (record_left.year != record_right.year) {
        is_still_same = (record_left.year > record_right.year) ? 1 : -1;
    }

    if (!is_still_same && record_left.month != record_right.month) {
        is_still_same = (record_left.month > record_right.month) ? 1 : -1;
    }

    if (!is_still_same && record_left.day != record_right.day) {
        is_still_same = (record_left.day > record_right.day) ? 1 : -1;
    }

    if (!is_still_same && record_left.hour != record_right.hour) {
        is_still_same = (record_left.hour > record_right.hour) ? 1 : -1;
    }

    if (!is_still_same && record_left.minute != record_right.minute) {
        is_still_same = (record_left.minute > record_right.minute) ? 1 : -1;
    }

    if (!is_still_same && record_left.sec != record_right.sec) {
        is_still_same = (record_left.sec > record_right.sec) ? 1 : -1;
    }

    if (!is_still_same && record_left.status != record_right.status) {
        is_still_same = (record_left.status > record_right.status) ? 1 : -1;
    }

    if (!is_still_same && record_left.code != record_right.code) {
        is_still_same = (record_left.code > record_right.code) ? 1 : -1;
    }

    return is_still_same;
}

int compare_date(const struct date *date_left, const struct date *date_right) {
    int is_still_same = 0;

    if (date_left->year != date_right->year) {
        is_still_same = (date_left->year > date_right->year) ? 1 : -1;
    }
    if (!is_still_same && date_left->month != date_right->month) {
        is_still_same = (date_left->month > date_right->month) ? 1 : -1;
    }
    if (!is_still_same && date_left->day != date_right->day) {
        is_still_same = (date_left->day > date_right->day) ? 1 : -1;
    }
    return is_still_same;
}

void sort_asc_records_in_file(FILE *pfile) {
    int records_count = get_records_count_in_file(pfile);

    for (int i = 0; i < records_count; i++) {
        for (int j = i + 1; j < records_count; j++) {
            if (compare_records_in_file(pfile, i, j) == 1) {
                swap_records_in_file(pfile, i, j);
            }
        }
    }
}

int search_code_by_date_in_file(FILE *pfile, const struct date *date, int *code) {
    int is_search_complete = 0;
    int records_count = get_records_count_in_file(pfile);

    for (int i = 0; i < records_count && !is_search_complete; i++) {
        struct dt_record record;
        record = read_record_from_file(pfile, i);

        if (record.day == date -> day &&
            record.month == date -> month &&
            record.year == date -> year) {
            is_search_complete = 1;
            *code = record.code;
        }
    }
    return is_search_complete;
}

int delete_records_by_date_interval(FILE **ppfile,
                                    const char *filename,
                                    const struct date *date1, const struct date *date2) {
    FILE *pfile_tmp;
    struct dt_record record;
    struct date tmp_date;
    char *tmp_filename;
    int tmp_filename_len;
    int num_records = 0;
    int num_deleted = 0;

    tmp_filename_len = strlen(filename) + 4;
    tmp_filename = (char*)calloc(tmp_filename_len, sizeof(char));

    if (!tmp_filename) {
        perror("Error in allocating memory for tmp filename");
        exit(1);
    }
    strcat(tmp_filename, filename);
    strcat(tmp_filename, ".tmp");

    pfile_tmp = fopen(tmp_filename, "wb+");
    if (!pfile_tmp) {
        perror("Unable to create tmp file");
        exit(1);
    }

    num_records = get_records_count_in_file(*ppfile);

    for (int i = 0; i < num_records; i++) {
        tmp_date = read_date_from_file(*ppfile, i);
        if (compare_date(&tmp_date, date1) == -1 || compare_date(date2, &tmp_date) == -1) {
            record = read_record_from_file(*ppfile, i);
            fwrite(&record, sizeof(struct dt_record), 1, pfile_tmp);
        } else {
            num_deleted++;
        }
    }
    fflush(pfile_tmp);
    fclose(*ppfile);
    remove(filename);
    rename(tmp_filename, filename);
    free(tmp_filename);
    *ppfile = pfile_tmp;
    return num_deleted;
}
