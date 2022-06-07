#ifndef SRC_CIPHER_H_
#define SRC_CIPHER_H_

#ifndef logging_cipher
#define ALLOWED_STRINGS "-1", "1", "2", "3"
#define ALLOWED_STRINGS_NUMBER 4
#endif  // SRC_LOGGER_H_

#ifdef logging_cipher
#define ALLOWED_STRINGS "-1", "1", "2", "3", "4"
#define ALLOWED_STRINGS_NUMBER 5
FILE* mode_add_log_file();
#endif  // SRC_LOGGER_H_


int set_mode(void);
int check_is_entry_allowed(char *entry, int allowed_strings_number, ...);
FILE* mode_read_output_file(void);
void mode_append_file_and_output(FILE* file);
void mode_encode_folder(void);

#endif  // SRC_CIPHER_H_
