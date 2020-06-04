# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: unite <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/26 02:09:26 by unite             #+#    #+#              #
#    Updated: 2020/06/05 02:01:44 by unite            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CK = checker
SRC_CK_NAME = checker.c

NAME_PS = push_swap
SRC_PS_NAME = push_swap.c

SRC_NAME = \
operations/functions/perform_pa.c \
operations/functions/perform_pb.c \
operations/functions/perform_ra.c \
operations/functions/perform_rb.c \
operations/functions/perform_rr.c \
operations/functions/perform_rra.c \
operations/functions/perform_rrb.c \
operations/functions/perform_rrr.c \
operations/functions/perform_sa.c \
operations/functions/perform_sb.c \
operations/functions/perform_ss.c \
operations/perform_operation.c \
sorts/advanced_sort/advanced_merge_stacks.c \
sorts/advanced_sort/advanced_push.c \
sorts/advanced_sort/advanced_sort.c \
sorts/simple_sort/simple_sort.c \
stack/append_stack.c \
stack/avg_stack.c \
stack/free_stack.c \
stack/get_stack.c \
stack/isset_stack.c \
stack/issorted_stack.c \
stack/max_stack.c \
stack/min_stack.c \
stack/new_stack.c \
stack/print_stack.c \
stack/pull_stack.c \
stack/push_stack.c \
stack/reverse_rotate_stack.c \
stack/rotate_stack.c \
stack/search_stack.c \
stack/swap_stack.c \
utils/ps_atoi.c \
utils/ps_exit.c \
utils/ps_index_stack.c \
utils/ps_isnumeric_str.c \
utils/ps_tab2stack.c \
utils/ps_print_stacks.c \

TEST_UNIT_NAME = unit-tests

TEST_SRC_UNIT_NAME = \
main.c \
stack_suite.c \
operations_suite.c \
utils_suite.c \
sorts_suite.c

TEST_FUNC_NAME = functional-tests.py

################################################################################

PATHS = src
PATHO = obj
PATHL = libftprintfgnl
PATHI = include $(PATHL)

TEST_UNIT_PATH = test/unit
TEST_UNIT_PATHS = $(TEST_UNIT_PATH)/src
TEST_UNIT_PATHO = $(TEST_UNIT_PATH)/obj
TEST_UNIT_PATHI = $(TEST_UNIT_PATH)/include

TEST_FUNC_PATH = test/functional

################################################################################

CC = gcc
RM = rm
MKDIR = /bin/mkdir

################################################################################

COMPILE = $(CC) -c
LINK = $(CC)

CFLAGS += -Wall -Wextra -Werror
CFLAGS += -O3 -std=gnu11 -ffast-math -march=native
CFLAGS += -MMD
CFLAGS += $(foreach path, $(PATHI) $(TEST_UNIT_PATHI), -I$(path))

LIBS = -lftprintfgnl -L $(PATHL)

################################################################################

ifeq ($(DEBUG), 1) 
	COMPILE += -g
endif

################################################################################

SRC = $(patsubst %.c, $(PATHS)/%.c, $(SRC_NAME))
OBJ = $(patsubst %.c, $(PATHO)/%.o, $(SRC_NAME))

SRC_CK = $(patsubst %.c, $(PATHS)/%.c, $(SRC_CK_NAME))
OBJ_CK = $(patsubst %.c, $(PATHO)/%.o, $(SRC_CK_NAME))

SRC_PS = $(patsubst %.c, $(PATHS)/%.c, $(SRC_PS_NAME))
OBJ_PS = $(patsubst %.c, $(PATHO)/%.o, $(SRC_PS_NAME))

TEST_UNIT_SRC = $(patsubst %.c, $(TEST_UNIT_PATHS)/%.c, $(TEST_SRC_UNIT_NAME))
TEST_UNIT_OBJ = $(patsubst %.c, $(TEST_UNIT_PATHO)/%.o, $(TEST_SRC_UNIT_NAME))

BIN_CK = $(NAME_CK)
BIN_PS = $(NAME_PS)
TEST_UNIT_BIN = $(TEST_UNIT_PATH)/$(TEST_UNIT_NAME)

TEST_FUNC_EXE = $(TEST_FUNC_PATH)/$(TEST_FUNC_NAME)

################################################################################

$(BIN_CK) : $(OBJ_CK) $(OBJ)
	$(LINK) $^ -o $@ $(LIBS)

$(BIN_PS) : $(OBJ_PS) $(OBJ)
	$(LINK) $^ -o $@ $(LIBS)

$(TEST_UNIT_BIN) : $(TEST_UNIT_OBJ) $(OBJ)
	$(LINK) $^ -o $@ $(LIBS)

################################################################################

$(PATHO)/%.o : $(PATHS)/%.c
	$(MKDIR) -p $(@D)
	$(COMPILE) $(CFLAGS) $< -o $@

$(TEST_UNIT_PATHO)/%.o : $(TEST_UNIT_PATHS)/%.c
	$(MKDIR) -p $(@D)
	$(COMPILE) $(CFLAGS) $< -o $@

################################################################################

DEP += $(patsubst %.c, $(PATHO)/%.d, $(SRC_NAME))
DEP += $(patsubst %.c, $(PATHO)/%.d, $(SRC_CK_NAME))
DEP += $(patsubst %.c, $(PATHO)/%.d, $(SRC_PS_NAME))
DEP += $(patsubst %.c, $(TEST_PATHO)/%.d, $(TEST_SRC_NAME))

-include $(DEP)

################################################################################

.DEFAULT_GOAL = all

.PHONY : all clean fclean re test

all : $(PATHL)/libftprintfgnl.a $(BIN_CK) $(BIN_PS)

fclean : clean
	$(RM) -f $(BIN_CK) $(BIN_PS) $(TEST_BIN)

clean :
	$(RM) -rf $(PATHO)
	$(RM) -rf $(TEST_PATHO)
	$(MAKE) -C $(PATHL) fclean

re : fclean all

test-unit: all $(TEST_UNIT_BIN)
	@echo '########### UNIT TESTS ###########'
	./$(TEST_UNIT_BIN)

test :
ifneq ($(TEST-UNIT), 0)
	make test-unit
endif
	./$(TEST_FUNC_EXE)

$(PATHL)/libftprintfgnl.a :
	$(MAKE) -C $(PATHL)

################################################################################
