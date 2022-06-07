#ifndef SRC_S21_STRING_H_
#define SRC_S21_STRING_H_

typedef unsigned long size_t;
size_t s21_strlen(const char *str);
int s21_strcmp(const char *s1, const char *s2);
char * s21_strcpy(char *to, const char * from);
char* s21_strcat(char *dest, const char *src);
char* s21_strchr(const char *str, const char chr);
char* s21_strstr(const char *string, const char *substring);
char *s21_strtok(char *str, const char *delim);

#endif  // SRC_S21_STRING_H_
