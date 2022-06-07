#include <string.h>
#include <stdio.h>
#include <time.h>

#include "log_levels.h"
#include "logger.h"

FILE* log_init(char *filename) {
    FILE* logfile = NULL;

    if (filename) {
        logfile = fopen(filename, "a");
    }

    if (!logfile) {
        printf("Can't create a file for logging\n");
    }

    return logfile;
}

int logcat(FILE* log_file, char *message, log_level level) {
    char log_level_message[10];
    time_t timer;
    char time_buffer[9];
    struct tm* tm_info;

    timer = time(NULL);
    tm_info = localtime(&timer);
    strftime(time_buffer, 9, "%H:%M:%S", tm_info);

    if (level == debug) {
        strcpy(log_level_message, "DEBUG");
    }

    if (level == trace) {
        strcpy(log_level_message, "TRACE");
    }

    if (level == info) {
        strcpy(log_level_message, "INFO");
    }

    if (level == warning) {
        strcpy(log_level_message, "WARNING");
    }

    if (level == error) {
        strcpy(log_level_message, "ERROR");
    }

    fprintf(log_file, "%s %s %s\n", log_level_message, time_buffer, message);

    return 0;
}

int log_close(FILE* log_file) {
    int result = 0;

    if (log_file) {
        fclose(log_file);
        result = 1;
    }

    return result;
}
