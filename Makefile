##
## EPITECH PROJECT, 2023
## cpoolday04
## File description:
## Makefile
##


NAME := grush

CFLAGS := -W -Wall -Wextra -Werror
CFLAGS += -pedantic -std=c99 -fno-builtin
CFLAGS += -iquote include

LDFLAGS :=

VPATH := src

vpath %.c $(VPATH)

SRC := main.c

BUILD_DIR := build
OBJ := $(SRC:%.c=$(BUILD_DIR)/%.o)

all: $(NAME)

$(BUILD_DIR)/%.o: %.c
	@ mkdir -p $(dir $@)
	@ $(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@ $(CC) -o $@ $(CFLAGS) $(OBJ) $(LDFLAGS) $(LDLIBS)

tests_run: $(UNIT)
	@ ./$(UNIT) --verbose

cov: tests_run
	@ gcovr --exclude tests

.PHONY: tests_run cov

clean:
	@ $(RM) $(OBJ)

fclean: clean
	@ $(RM) -r $(BUILD_DIR)
	@ $(RM) $(UNIT)

.PHONY: clean fclean

re: fclean all

.PHONY: re
