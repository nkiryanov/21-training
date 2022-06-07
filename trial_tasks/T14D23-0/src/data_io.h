#ifndef SRC_DATA_IO_H_
#define SRC_DATA_IO_H_

#define FILENAME_ARRAY_BUFFER 10;
#define MODE_MIN -1
#define MODE_MAX 2

char* increase_array_size_if_needed(char *array_ptr, size_t *array_length, const size_t sting_length);
char* read_string_from_std(void);
int get_mode_from_std(void);

struct dt_record* read_dt_record_from_std(void);
struct date* read_date_from_std(void);
void read_date_interval_from_std(struct date **date1, struct date **date2);

FILE* open_binary_rw_file(char *path_to_file);
FILE* close_binary_file_if_empty(FILE* pfile);

void output_record(FILE* file, int index);
void output_file_content_dt_records(FILE* file);

#endif  // SRC_DATA_IO_H_
