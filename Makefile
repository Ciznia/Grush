##
## EPITECH PROJECT, 3301
## Mini shell 1
## File description:
## Makefile
##
ID = root

CC := gcc
NAME = my_exec

SRC_DIR := src
BUILD_DIR := build

VPATH := $(SRC_DIR)
VPATH := $(SRC_DIR)/base

vpath %.c $(VPATH)

CFLAGS := -W -Wall -Wextra -Werror
CFLAGS += -iquote include
CFLAGS += -pedantic -std=c99

LIBFLAGS := -lcsfml-window
LIBFLAGS += -lcsfml-system
LIBFLAGS += -lcsfml-graphics
LIBFLAGS += -lcsfml-audio

SRC := main.c

CMD_NOT_FOUND = $(error $(strip $(1)) is required for this rule)
CHECK_CMD = $(if $(shell command -v $(1)),, $(call CMD_NOT_FOUND, $(1)))
CHECK_CMDS = $(foreach cmd, $(1), $(call CHECK_CMD, $(cmd)))

REQUIREMENTS := date expr tput

V ?=
ifeq ($(V), 1)
    $(info Verbose mode enabe)
    Q :=
else
    Q := @
endif

$(foreach req, $(REQUIREMENTS), $(call CHECK_CMD, $(req)))

ifneq ($(shell tput colors),0)
    C_RESET := \033[00m
    C_BOLD := \e[1m
    C_RED := \e[31m
    C_GREEN := \e[32m
    C_YELLOW := \e[33m
    C_BLUE := \e[34m
    C_PURPLE := \e[35m
    C_CYAN := \e[36m
endif

DIE := exit 1
ECHO := /bin/echo -e
EPOCH := $(shell date +%s)

_C_RED = $(subst :r,$(C_RED),$(1))
_C_CYAN = $(call _C_RED,$(subst :c,$(C_CYAN),$(1)))
_C_PURPLE = $(call _C_CYAN,$(subst :p,$(C_PURPLE),$(1)))
_C_YELLOW = $(call _C_PURPLE,$(subst :y,$(C_YELLOW),$(1)))
_C_BLUE = $(call _C_YELLOW,$(subst :b,$(C_BLUE),$(1)))
_C_GREEN = $(call _C_BLUE,$(subst :g,$(C_GREEN),$(1)))
_C_BOLD = $(call _C_GREEN,$(subst *,$(C_BOLD),$(1)))
_C_RESET = $(call _C_BOLD,$(subst ~,$(C_RESET),$(1)))

_SOLVE_COLORS = $(call _C_RESET,$(addprefix $(call _UNQUOTE,$(1)),~))
_UNQUOTE = $(subst ",,$(1))##") ## <- Hack to make highlighter happy
_QUOTE = "$(strip $(1))"

COLORIZE = $(call _QUOTE, $(call _SOLVE_COLORS, $(1)))
PRINT = $(ECHO) $(call COLORIZE, $(1))

CURRENT_TIME_MS = $(shell date +%s%3N)
BOXIFY = *[$(strip $(call _UNQUOTE, $(1)))~*]
HELP_RULE = *:p$(1)*$(if $(findstring _,$(1)),,\t)\t~

LOG_OK := $(call BOXIFY, ":gOK")
LOG_KO := $(call BOXIFY, ":rKO")
LOG_WN := $(call BOXIFY, ":yWN")
LOG_MK := $(call BOXIFY, ":yMK")
LOG_CC := $(call BOXIFY, ":cCC")
LOG_LD := $(call BOXIFY, ":cLD")
LOG_RM := $(call BOXIFY, ":cRM")
LOG_AR := $(call BOXIFY, ":cAR")

GET_ID = *$(if $(ID),@:y$(ID) ,)~
TIME = *:p$(shell expr $(call CURRENT_TIME_MS) - $(START_TIME))~*ms~

LOG = $(call PRINT, $(call $(1)) $(call GET_ID)$(call TIME) $(2))

COMPILE_DB := compile_commands.json
VG_REPORT ?= logs/trace_$(EPOCH)_.log

VG_FLAGS := --leak-check=full
VG_FLAGS += --track-origins=yes

START_TIME := $(shell date +%s%3N)
UNIT :=

ifdef $(UNIT)
    T_FLAGS := -lcriterion --coverage
    COV_DIR := tests/coverage
endif

OBJ := $(SRC:%.c=$(BUILD_DIR)/%.o)
DEPS := $(SRC:%.c=$(BUILD_DIR)/%.d)

all: CFLAGS += -MMD -MP
all: $(NAME)

$(NAME): $(OBJ)
	$(Q) $(CC) $(CFLAGS) $(LIBFLAGS) -o $(NAME) $(OBJ) || $(DIE)
	@ $(call LOG, LOG_LD, "Linked object(s)")
	@ $(call LOG, LOG_OK, "Built :c"$(NAME))

$(BUILD_DIR)/%.o: %.c
	$(Q) mkdir -p $(@D)
	$(Q) $(CC) $(CFLAGS) -c $< -o $@
	@ $(call LOG, LOG_CC, "Compiled :c"$(notdir $@))

$(BUILD_DIR)/%.d: %.c
	@ mkdir -p $(dir $@)
	@ $(CC) $(CFLAGS) $(DFLAGS) -MM -MT $(@:.d=.o) $< -MF $@

-include $(DEPS)

clean_obj:
	$(Q) $(RM) $(OBJ)
	@ $(call LOG, LOG_RM, "Removed :b"$(words $(OBJ))"~ object(s)")

clean_logs:
	$(Q) $(RM) $(LOGS)
	@ $(call LOG, LOG_RM, "Removed :b"$(words $(LOGS))"~ log(s)")

clean_cov:
	$(Q) $(RM) $(COV)
	@ $(call LOG, LOG_RM, "Removed :b"$(words $(COV))"~ cov file(s)")

clean_deps:
	$(Q) $(RM) $(DEPS)
	@ $(call LOG, LOG_RM, "Removed :b"$(words $(DEPS))"~ cov file(s)")

.PHONY: clean_obj clean_logs clean_cov clean_deps

clean: clean_obj clean_logs clean_cov
	@ $(call LOG, LOG_OK, "Cleaned")

.PHONY: clean fclean

fclean: clean clean_deps
	$(Q) $(RM) -r $(BUILD_DIR)
	@ $(call LOG, LOG_RM, "Removed :b"$(BUILD_DIR))
	$(Q) $(RM) "$(NAME)"
	@ $(call LOG, LOG_RM, "Removed :b"$(NAME))
ifdef $(UNIT)
	$(Q) $(RM) "$(UNIT)"
	@ $(call LOG, LOG_RM, "Removed :b"$(UNIT))
endif
	@ $(call LOG, LOG_OK, "Fully cleaned")

re: fclean all

.PHONY: re

debug: CFLAGS += -g3 -D W_DEBUG
debug: re
	@ $(call LOG, LOG_WN, "Compiled with debug flags")

.PHONY: debug

$(VG_REPORT):
	$(call CHECK_CMD, valgrind)
	$(Q) mkdir -p $(dir $@)
	@ $(call ASK, "program arguments")
	$(Q) read ARG; valgrind $(VG_FLAGS) -s ./$(NAME) $${ARG} 2> $(VG_REPORT)

v: debug $(VG_REPORT)
	@ $(call LOG, LOG_OK, "Valgrind report generated")

.PHONY: debug v

$(COMPILE_DB):
	$(CHECK_CMD, compiledb)
	@ compiledb make -Bwnk V=1
	@ $(call LOG, $(LOG_OK), "Generated compile_commands.json")

cdb: $(COMPILE_DB)

.PHONY: cdb

help:
	@ $(call PRINT, "*Available rules")
	@ $(call PRINT, $(call HELP_RULE,"all")"Build the project")
	@ $(call PRINT, $(call HELP_RULE,"clean_obj")"Remove object files")
	@ $(call PRINT, $(call HELP_RULE,"clean_logs")"Remove log files")
	@ $(call PRINT, $(call HELP_RULE,"clean_cov")"Remove coverage files")
	@ $(call PRINT, $(call HELP_RULE,"clean")"Remove build files")
	@ $(call PRINT, $(call HELP_RULE,"fclean")"Remove build files & binary")
	@ $(call PRINT, $(call HELP_RULE,"re")"Rebuild the project")
	@ $(call PRINT, $(call HELP_RULE,"debug")"Build with debug flags")
	@ $(call PRINT, $(call HELP_RULE,"v")"Run the program with valgrind")
	@ $(call PRINT, $(call HELP_RULE,"cdb")"Generate compile db json")
	@ $(call PRINT, $(call HELP_RULE,"help")"Display this help message")

.PHONY: help
