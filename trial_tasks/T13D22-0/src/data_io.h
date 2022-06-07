#ifndef SRC_DATA_IO_H_
#define SRC_DATA_IO_H_

#define PATH_SIZE_BUFFER 10

char* increase_array_size_if_needed(char *string_ptr, size_t *length, const size_t counter);
char* read_string_from_std(void);
int read_int_from_std(int *input_int);

FILE* open_file(char *path_to_file);
DIR* open_directory(char* path_to_dir);
char** get_files_in_directory(DIR *directory, char* path_to_folder, int *num_files);

char* copy_file_to_string(FILE* file);
void write_to_the_end_to_file(FILE *file);

#endif  // SRC_DATA_IO_H_
