#include "s21_string.h"
#include <stdio.h>

size_t s21_strlen(const char *str) {
    char *s;
    for (s = (char *)str; *s; ++s) {}
    return (s - str);
}

int s21_strcmp(const char *s1, const char *s2) {
    int result;

    for ( ; *s1 == *s2 && *s1 != '\0'; s1++, s2++) {}
    if (*s1 == '\0')
        result = 0;
    else
        result = (*(unsigned char *)s1 < *(unsigned char *)s2) ? -1 : +1;
    return result;
}

char* s21_strcpy(char *to, const char * from) {
    char *save = to;

    for (; (*to = *from); ++from, ++to) {}
    return save;
}


char* s21_strcat(char *dest, const char *src) {
    char *save = dest;
    for (; *dest; dest++) {}
    while ((*dest++ = *src++)) {}
    return save;
}

char* s21_strchr(const char *str, const char chr) {
    char *pointer;
    while (*str && *str != chr) {
        str++;
    }
    if (*str == '\0')
        pointer = NULL;
    else
        pointer = (char *)str;
    return pointer;
}

char* s21_strstr(const char *string, const char *substring) {
    char *pointer = NULL;
    char *a, *b;
    int is_search_complete = 0;

    if (*substring == 0) {
        is_search_complete = 1;
    }

    while (*string && !is_search_complete) {
        if (*string != *substring) {
            string++;
            continue;
        }

        a = (char *)string;
        b = (char *)substring;
        while (*a == *b) {
            a++;
            b++;
        }
        if (*b == 0) {
            pointer = (char *)string;
            is_search_complete = 1;
        }
        string++;
    }

    return pointer;
}


char *s21_strtok(char *str, const char *delim) {
    char *token;
    static char *save_ptr = NULL;

    if (NULL == str || NULL == delim) {
        token = save_ptr;
    } else {
        token = str;
    }

    while (token && *token && s21_strchr(delim, *token)) {
        token++;
    }

    if (token && *token == '\0') {
        token = NULL;
        save_ptr = NULL;
    } else if (token) {
        save_ptr = token;
        while (*save_ptr && !(s21_strchr(delim, *save_ptr))) {
            save_ptr++;
        }
    }

    if (save_ptr && *save_ptr) {
        *save_ptr = '\0';
        save_ptr++;
    } else if (save_ptr && *save_ptr == '\0') {
        save_ptr = NULL;
    }

    return token;
}
