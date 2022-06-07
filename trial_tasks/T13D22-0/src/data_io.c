#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>

#include "data_io.h"

char* increase_array_size_if_needed(char *array_ptr, size_t *array_length, const size_t sting_length) {
    if (*array_length - sting_length <= 2) {
        *array_length += PATH_SIZE_BUFFER;
        array_ptr = (char*)realloc(array_ptr, (*array_length) * sizeof(char));
        if (!array_ptr) {
            exit(1);
        }
    }
    return array_ptr;
}

char* read_string_from_std(void) {
    char *string = NULL;
    char end = ' ';
    size_t length = 0;
    size_t array_length = 0;

    while (end != '\n') {
        scanf("%c", &end);
        if (end != '\n') {
            string = increase_array_size_if_needed(
                string,
                &array_length,
                length);
            string[length] = end;
            length += 1;
        }
    }
    if (string) {
        string[length] = '\0';
    }
    return string;
}

int read_int_from_std(int *input_int) {
    int read_result;
    char end;

    end = '\0';
    read_result = 1;

    if (scanf("%d%c", input_int, &end) != 2 || end != '\n') {
        read_result = 0;
        printf("n/a\n");
    }

    while (end != '\n') {end = getchar();}
    return read_result;
}

FILE* open_file(char *path_to_file) {
    FILE* file;

    // try to open file to read
    file = fopen(path_to_file, "r");

    // if file is exist reopen the same file to append
    if (file) {
        fclose(file);
        file = fopen(path_to_file, "a+");
    }
    return file;
}


DIR* open_directory(char* path_to_dir) {
    DIR* directory = NULL;
    directory = opendir(path_to_dir);

    if (!directory) {
        printf("n/a\n");
    }
    return directory;
}

char** get_files_in_directory(DIR *directory, char* path_to_folder, int *num_files) {
    struct dirent *entry;
    size_t folder_path_len;
    char **files = NULL;

    folder_path_len = strlen(path_to_folder);
    *num_files = 0;

    while ( (entry = readdir(directory)) != NULL ) {
        size_t filename_length;
        int index;

        *num_files += 1;
        index = *num_files - 1;
        filename_length = strlen(entry->d_name);

        files = (char**)realloc(files, *num_files * sizeof(char*));
        if (!files) {
            printf("Can't allocate memory for names of files in folder");
            exit(1);
        }

        files[index] = (char*)calloc(filename_length + folder_path_len, sizeof(char));
        if (!files[index]) {
            printf("Can't allocate memory for file name of file in folder");
            exit(1);
        }

        strcpy(files[index], path_to_folder);
        if (path_to_folder[folder_path_len - 1] != '/') {
            strcat(files[index], "/");
        }
        strcat(files[index], entry->d_name);
    }
    return files;
}

char* copy_file_to_string(FILE* file) {
    size_t length = 0;
    char *buffer = NULL;

    // get file length
    if (file) {
        fseek(file, 0, SEEK_END);
        length = ftell(file);
        fseek(file, 0, SEEK_SET);
    }

    // read file to stirng if size is not zero
    if (file && length) {
        buffer = (char*)calloc(length + 1, sizeof(char));
        if (!buffer) {
            printf("Can't get memory for sroring file.\n");
            exit(1);
        }
        fread(buffer, sizeof(char), length, file);
        buffer[length + 1] = '\0';
    }

    // output error if file doesn't exits or empty
    if (!file || !length) {
        printf("n/a\n");
    }

    return buffer;
}

void write_to_the_end_to_file(FILE *file) {
    char *input_string;
    input_string = read_string_from_std();

    // writ to the end to file only if it exist and avaliable to write
    if (file) {
        fseek(file, 0, SEEK_END);
        fprintf(file, "%c", '\n');
        fprintf(file, "%s", input_string);
        fseek(file, 0, SEEK_SET);
    }

    free(input_string);
}
