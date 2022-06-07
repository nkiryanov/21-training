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

cpplint:
	cp ../materials/linters/CPPLINT.cfg .
	python3 ../materials/linters/cpplint.py --extension=c ./*.c ./*.h
	rm CPPLINT.cfg

cppcheck:
	~/bin/cppcheck/cppcheck --enable=all --suppress=missingIncludeSystem ./*.c ./*.h

cipher:  clean_objects | $(OBJ_DIR)/data_io.o $(OBJ_DIR)/cipher.o $(OBJ_DIR)/encode.o
	$(CC) $(CCBUILDFLAGS) $| -o $(OUT_DIR)/cipher

logging_cipher: CCFLAGS+=-D logging_cipher
logging_cipher: clean_objects | $(OBJ_DIR)/data_io.o $(OBJ_DIR)/cipher.o $(OBJ_DIR)/encode.o $(OBJ_DIR)/logger.o
	$(CC) $(CCBUILDFLAGS) $| -o $(OUT_DIR)/logging_cipher


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CCFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $@

clean:
	rm -rf $(OBJ_DIR) $(OUT_DIR)/cipher

clean_objects:
	rm -rf $(OBJ_DIR)
