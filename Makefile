# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: unite <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/26 02:09:26 by unite             #+#    #+#              #
#    Updated: 2020/05/22 05:46:51 by unite            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CK = checker
SRC_CK_NAME = checker.c

NAME_PS = push_swap
SRC_PS_NAME = push_swap.c

SRC_NAME = \
src/operations/functions/perform_pa.c \
src/operations/functions/perform_pb.c \
src/operations/functions/perform_ra.c \
src/operations/functions/perform_rb.c \
src/operations/functions/perform_rr.c \
src/operations/functions/perform_rra.c \
src/operations/functions/perform_rrb.c \
src/operations/functions/perform_rrr.c \
src/operations/functions/perform_sa.c \
src/operations/functions/perform_sb.c \
src/operations/functions/perform_ss.c \
src/operations/perform_operation.c \
src/sorts/advanced_sort/advanced_merge_stacks.c \
src/sorts/advanced_sort/advanced_push.c \
src/sorts/advanced_sort/advanced_sort.c \
src/sorts/advanced_sort/advanced_split_stacks.c \
src/sorts/simple_sort/simple_sort.c \
src/stack/append_stack.c \
src/stack/avg_stack.c \
src/stack/free_stack.c \
src/stack/get_stack.c \
src/stack/isset_stack.c \
src/stack/issorted_stack.c \
src/stack/max_stack.c \
src/stack/min_stack.c \
src/stack/new_stack.c \
src/stack/print_stack.c \
src/stack/pull_stack.c \
src/stack/push_stack.c \
src/stack/reverse_rotate_stack.c \
src/stack/rotate_stack.c \
src/stack/search_stack.c \
src/stack/swap_stack.c \
src/utils/ps_atoi.c \
src/utils/ps_exit.c \
src/utils/ps_index_stack.c \
src/utils/ps_isnumeric_str.c \
src/utils/ps_tab2stack.c \

TEST_NAME = unit-tests

TEST_SRC_NAME = \
main.c \
stack_suite.c \
operations_suite.c \
utils_suite.c \
sorts_suite.c

################################################################################

PATH = .
PATHS = $(PATH)/src
PATHO = $(PATH)/obj
PATHL = $(PATH)/libftprintfgnl
PATHI = $(PATH)/include $(PATHL)

TEST_PATH = test/unit
TEST_PATHS = $(TEST_PATH)/src
TEST_PATHO = $(TEST_PATH)/obj
TEST_PATHI = $(TEST_PATH)/include

################################################################################

CC = /usr/bin/gcc
RM = /bin/rm
MKDIR = /bin/mkdir

################################################################################

COMPILE = $(CC) -c
LINK = $(CC) -lftprintfgnl -L $(PATHL)

CFLAGS += -Wall -Wextra -Werror
CFLAGS += -O3 -std=gnu11 -ffast-math -march=native
CFLAGS += -MMD
CFLAGS += $(foreach path, $(PATHI) $(TEST_PATHI), -I$(path))

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

TEST_SRC = $(patsubst %.c, $(TEST_PATHS)/%.c, $(TEST_SRC_NAME))
TEST_OBJ = $(patsubst %.c, $(TEST_PATHO)/%.o, $(TEST_SRC_NAME))

BIN_CK = $(PATH)/$(NAME_CK)
BIN_PS = $(PATH)/$(NAME_PS)
TEST_BIN = $(TEST_PATH)/$(TEST_NAME)

################################################################################

$(BIN_CK) : $(OBJ_CK) $(OBJ)
	$(LINK) $^ -o $@

$(BIN_PS) : $(OBJ_PS) $(OBJ)
	$(LINK) $^ -o $@

$(TEST_BIN) : $(TEST_OBJ) $(OBJ)
	$(LINK) $^ -o $@

################################################################################

$(PATHO)/%.o : $(PATHS)/%.c
	$(MKDIR) -p $(@D)
	$(COMPILE) $(CFLAGS) $< -o $@

$(TEST_PATHO)/%.o : $(TEST_PATHS)/%.c
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

test : all $(TEST_BIN)
	./$(TEST_BIN)

$(PATHL)/libftprintfgnl.a :
	$(MAKE) -C $(PATHL)

################################################################################
