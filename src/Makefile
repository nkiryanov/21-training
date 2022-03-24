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

all: state_sort state_search clear_state

cpplint:
	cp ../materials/linters/CPPLINT.cfg .
	python3 ../materials/linters/cpplint.py --extension=c ./*.c ./*.h
	rm CPPLINT.cfg

cppcheck:
	~/bin/cppcheck/cppcheck --enable=all --suppress=missingIncludeSystem ./*.c ./*.h

matrix_mul: $(OUT_DIR) | $(OBJ_DIR)/matrix_mul.o $(OBJ_DIR)/common_matrix.o
	$(CC) $(CCBUILDFLAGS) $| -o $(OUT_DIR)/matrix_mul

snake_matrix: $(OUT_DIR) | $(OBJ_DIR)/snake_matrix.o $(OBJ_DIR)/common_matrix.o
	$(CC) $(CCBUILDFLAGS) $| -o $(OUT_DIR)/snake_matrix

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CCFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $@

$(OUT_DIR):
	mkdir -p $@

clean:
	rm -rf $(OBJ_DIR) $(OUT_DIR)/cipher

clean_objects:
	rm -rf $(OBJ_DIR)
