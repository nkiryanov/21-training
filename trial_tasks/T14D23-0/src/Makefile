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

state_sort: $(OBJ_DIR)/data_io.o $(OBJ_DIR)/common_functions.o $(OBJ_DIR)/state_sort.o
	$(CC) $(CCBUILDFLAGS) $^ -o $(OUT_DIR)/$(QUEST_)1

state_search: $(OBJ_DIR)/data_io.o $(OBJ_DIR)/common_functions.o $(OBJ_DIR)/state_search.o
	$(CC) $(CCBUILDFLAGS) $^ -o $(OUT_DIR)/$(QUEST_)2

clear_state: $(OBJ_DIR)/data_io.o $(OBJ_DIR)/common_functions.o $(OBJ_DIR)/clear_state.o
	$(CC) $(CCBUILDFLAGS) $^ -o $(OUT_DIR)/$(QUEST_)3

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CCFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $@

clean:
	rm -rf $(OBJ_DIR) $(OUT_DIR)/cipher

clean_objects:
	rm -rf $(OBJ_DIR)
