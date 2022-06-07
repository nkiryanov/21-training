#include "print_module.h"

#include <stdio.h>
#include <time.h>

char print_char(char ch) {
    return putchar(ch);
}

void print_log(char (*print)(char), char* message) {
    char* log_prefix = Log_prefix;
    time_t timer;
    char time_buffer[9];
    struct tm* tm_info;

    timer = time(NULL);
    tm_info = localtime(&timer);
    strftime(time_buffer, 9, "%H:%M:%S", tm_info);

    for (; *log_prefix; log_prefix++) {
        (*print) (*log_prefix);
    }

    (*print) (' ');

    for (int i = 0; i < 9; i++) {
        (*print) (time_buffer[i]);
    }

    (*print) (' ');

    for (; *message; message++) {
        (*print) (*message);
    }
}
