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

print_module: $(OBJ_DIR)/print_module.o $(OBJ_DIR)/main_module_entry_point.o
	$(CC) $(CCBUILDFLAGS) $^ -o $(OUT_DIR)/$(QUEST_)1

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CCFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $@

clean:
	rm -rf $(OBJ_DIR) $(OUT_DIR)/$(QUEST_)*

clean_objects:
	rm -rf $(OBJ_DIR)
