#ifndef SRC_COMMON_FUNCTIONS_H_
#define SRC_COMMON_FUNCTIONS_H_

typedef struct dt_record {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int sec;
    int status;
    int code;
} dt_record;

typedef struct date {
    int day;
    int month;
    int year;
} date;


struct dt_record read_record_from_file(FILE *pfile, int index);
void write_record_in_file(FILE *pfile, const struct dt_record *record_to_write, int index);
void append_record_to_file(FILE *pfile, const struct dt_record *record_to_write);
void swap_records_in_file(FILE *pfile, int record_index1, int record_index2);
int get_file_size_in_bytes(FILE *pfile);
int get_records_count_in_file(FILE *pfile);

int compare_records_in_file(FILE *pfile, int record_index_left, int record_index_right);
void sort_asc_records_in_file(FILE *pfile);
int search_code_by_date_in_file(FILE *pfile, const struct date *date, int *code);
int compare_date(const struct date *date_left, const struct date *date_right);
struct date read_date_from_file(FILE *pfile, int index);
int delete_records_by_date_interval(FILE **pfile,
                                    const char *filename,
                                    const struct date *date1, const struct date *date2);

#endif  // SRC_COMMON_FUNCTIONS_H_
