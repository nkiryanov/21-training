SRC_DIR := .
OBJ_DIR = ../objects
OUT_DIR = ../build

SRC := $(wildcard $(SRC_DIR)/*.c)
OBJ := $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

QUEST_ = Quest_

CC = gcc
CCFLAGS = -c -Wall -Werror -Wextra
CCBUILDFLAGS = -Wall -Werror -Wextra

.PHONY: clean

cpplint:
	cp ../materials/linters/CPPLINT.cfg .
	python3 ../materials/linters/cpplint.py --extension=c ./*.c ./*.h
	rm CPPLINT.cfg

cppcheck:
	~/bin/cppcheck/cppcheck --enable=all --suppress=missingIncludeSystem ./*.c ./*.h

door_struct: $(OBJ_DIR)/dmanager_module.o
	$(CC) $(CCBUILDFLAGS) $^ -o $(OUT_DIR)/$(QUEST_)1

list_test: $(OBJ_DIR)/list.o $(OBJ_DIR)/list_test.o
	$(CC) $(CCBUILDFLAGS) $^ -o $(OUT_DIR)/$(QUEST_)2

list_test_leaks: list_test
	leaks --atExit -- $(OUT_DIR)/$(QUEST_)2

stack_test: $(OBJ_DIR)/stack.o $(OBJ_DIR)/stack_test.o
	$(CC) $(CCBUILDFLAGS) $^ -o $(OUT_DIR)/$(QUEST_)3

stack_test_leaks: stack_test
	leaks --atExit -- $(OUT_DIR)/$(QUEST_)3

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CCFLAGS) $< -o $@

$(OBJ_DIR):
	mkdir -p $@

clean:
	rm -rf $(OBJ_DIR) $(OUT_DIR)/$(QUEST_)*
