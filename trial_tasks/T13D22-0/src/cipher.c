#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <dirent.h>

#include "data_io.h"
#include "cipher.h"
#include "encode.h"

#ifdef logging_cipher
#include "log_levels.h"
#include "logger.h"
#endif  // logging_cipher

int main() {
    FILE* file = NULL;
    int mode_type = -1;
    int is_file_openned = 0;

    #ifdef logging_cipher
    FILE* log_file = NULL;
    #endif  // logging_cipher


    while (mode_type != 0) {
        mode_type = set_mode();

        if (mode_type == 1) {
            file = mode_read_output_file();
            if (file) {
                is_file_openned = 1;
            }
            #ifdef logging_cipher
            if (log_file) {
                logcat(log_file, "Файл прочитан", info);
            }
            #endif  // logging_cipher
        }

        if (mode_type == 2) {
            mode_append_file_and_output(file);
            #ifdef logging_cipher
            if (log_file) {
                logcat(log_file, "Попробовали записать в конец файла", info);
            }
            #endif  // logging_cipher
        }

        if (mode_type == 3) {
            mode_encode_folder();
            #ifdef logging_cipher
            if (log_file) {
                logcat(log_file, "The folder encoded", info);
            }
            #endif  // logging_cipher
        }

        #ifdef logging_cipher
        if (mode_type == 4) {
            log_file = mode_add_log_file();
        }
        #endif  // logging_cipher
    }

    if (is_file_openned) {
        fclose(file);
    }

    #ifdef logging_cipher
    if (log_file) {
        log_close(log_file);
    }
    #endif  // logging_cipher
}

int set_mode(void) {
    char mode[3];
    int error_reading = 0;
    int entry_type = -1;

    size_t position = 0;
    char end = ' ';

    for (position = 0; position <= 2 && end !='\n';) {
        scanf("%c", &end);
        if (end != '\n') {
            if (position < 1) {
                mode[position] = end;
                position++;
            }
        }
    }
    mode[position] = '\0';

    if (end != '\n') {
        while (end != '\n') {end = getchar();}
        error_reading = 1;
    }

    if (!error_reading) {
        entry_type = check_is_entry_allowed(mode, ALLOWED_STRINGS_NUMBER, ALLOWED_STRINGS);
    }

    if (error_reading || entry_type == -1) {
        printf("n/a\n");
    }

    return entry_type;
}

int check_is_entry_allowed(char *entry, int allowed_strings_number, ...) {
    va_list allowed_list;
    int entry_type;

    entry_type = -1;
    va_start(allowed_list, allowed_strings_number);

    for (int i = 0; i < allowed_strings_number && entry_type == -1; i++) {
        char *allowed_string;
        allowed_string = va_arg(allowed_list, char*);
        if (strcmp(entry, allowed_string) == 0) {
            entry_type = i;
        }
    }
    va_end(allowed_list);

    return entry_type;
}

FILE* mode_read_output_file(void) {
    char* path_to_file;
    char* buffer;
    FILE* file = NULL;

    path_to_file = read_string_from_std();
    file = open_file(path_to_file);
    free(path_to_file);
    buffer = copy_file_to_string(file);

    if (buffer) {
        printf("%s\n", buffer);
        free(buffer);
    }

    return file;
}

void mode_append_file_and_output(FILE* file) {
    char *buffer;
    write_to_the_end_to_file(file);
    buffer = copy_file_to_string(file);
    if (buffer) {
        printf("%s\n", buffer);
        free(buffer);
    }
}

void mode_encode_folder(void) {
    char* path_to_folder;
    DIR* directory;
    int shift, is_shift_read, num_files;

    shift = is_shift_read = 0;

    printf("Set path to folder to encrypt: ");
    path_to_folder = read_string_from_std();
    directory = open_directory(path_to_folder);
    if (directory) {
        printf("Set shift number (int): ");
        is_shift_read = read_int_from_std(&shift);
    }

    if (directory && is_shift_read) {
        char** files;
        files = get_files_in_directory(directory, path_to_folder, &num_files);
        encrypt_c_h_files((const char**)files, num_files, shift);

        for (int i = 0; i < num_files; i++) {
            free(files[i]);
        }
        free(files);
    }

    if (directory) {
        closedir(directory);
    }

    if (path_to_folder) {
        free(path_to_folder);
    }
}


#ifdef logging_cipher
FILE* mode_add_log_file() {
    char* path_to_log = NULL;
    FILE* log_file = NULL;

    printf("Set path to log file: ");
    path_to_log = read_string_from_std();

    log_file = log_init(path_to_log);

    if (path_to_log) {
        free(path_to_log);
    }

    if (!log_file) {
        printf("n/a\n");
    }

    return log_file;
}
#endif  // logging_cipher
