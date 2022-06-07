SRC_DIR := .
OBJ_DIR = ../objects
OUT_DIR = ../build

SRC := $(wildcard $(SRC_DIR)/*.c)
OBJ := $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

QUEST_ = Quest_

CC = gcc
CCFLAGS = -c -Wall -Werror -Wextra
CCBUILDFLAGS = -Wall -Werror -Wextra

.PHONY: clean clean_objects

strlen_tests: CCFLAGS+=-D strlen_tests
strlen_tests: clean_objects | $(OBJ_DIR)/s21_string.o $(OBJ_DIR)/s21_string_test.o
	$(CC) $(CCBUILDFLAGS) $| -o $(OUT_DIR)/$(QUEST_)1

strcmp_tests: CCFLAGS+=-D strcmp_tests
strcmp_tests: clean_objects | $(OBJ_DIR)/s21_string.o $(OBJ_DIR)/s21_string_test.o
	$(CC) $(CCBUILDFLAGS) $| -o $(OUT_DIR)/$(QUEST_)2

strcpy_tests: CCFLAGS+=-D strcpy_tests
strcpy_tests: clean_objects | $(OBJ_DIR)/s21_string.o $(OBJ_DIR)/s21_string_test.o
	$(CC) $(CCBUILDFLAGS) $| -o $(OUT_DIR)/$(QUEST_)3

strcat_tests: CCFLAGS+=-D strcat_tests
strcat_tests: clean_objects | $(OBJ_DIR)/s21_string.o $(OBJ_DIR)/s21_string_test.o
	$(CC) $(CCBUILDFLAGS) $| -o $(OUT_DIR)/$(QUEST_)4

strchr_tests: CCFLAGS+=-D strchr_tests
strchr_tests: clean_objects | $(OBJ_DIR)/s21_string.o $(OBJ_DIR)/s21_string_test.o
	$(CC) $(CCBUILDFLAGS) $| -o $(OUT_DIR)/$(QUEST_)5

strstr_tests: CCFLAGS+=-D strstr_tests
strstr_tests: clean_objects | $(OBJ_DIR)/s21_string.o $(OBJ_DIR)/s21_string_test.o
	$(CC) $(CCBUILDFLAGS) $| -o $(OUT_DIR)/$(QUEST_)6

strtok_tests: CCFLAGS+=-D strtok_tests
strtok_tests: clean_objects | $(OBJ_DIR)/s21_string.o $(OBJ_DIR)/s21_string_test.o
	$(CC) $(CCBUILDFLAGS) $| -o $(OUT_DIR)/$(QUEST_)7

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CCFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $@

clean:
	rm -rf $(OBJ_DIR) $(OUT_DIR)/$(QUEST_)*

clean_objects:
	rm -rf $(OBJ_DIR)
