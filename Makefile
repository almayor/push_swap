# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: unite <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/26 02:09:26 by unite             #+#    #+#              #
#    Updated: 2020/05/17 05:02:48 by unite            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CK = checker
SRC_CK_NAME = checker.c

NAME_PS = push_swap
SRC_PS_NAME = push_swap.c

SRC_NAME = \
utils/ps_tab2stack.c \
utils/ps_exit.c \
utils/ps_atoi.c \
utils/ps_isnumeric_str.c \
utils/ps_index_stack.c \
operations/perform_operation.c \
operations/functions/perform_sb.c \
operations/functions/perform_rrb.c \
operations/functions/perform_rb.c \
operations/functions/perform_rra.c \
operations/functions/perform_sa.c \
operations/functions/perform_ra.c \
operations/functions/perform_ss.c \
operations/functions/perform_rr.c \
operations/functions/perform_pa.c \
operations/functions/perform_rrr.c \
operations/functions/perform_pb.c \
stack/issorted_stack.c \
stack/min_stack.c \
stack/rotate_stack.c \
stack/new_stack.c \
stack/push_stack.c \
stack/free_stack.c \
stack/avg_stack.c \
stack/reverse_rotate_stack.c \
stack/pull_stack.c \
stack/swap_stack.c \
stack/print_stack.c \
stack/append_stack.c \
stack/get_stack.c \
stack/isset_stack.c \
stack/search_stack.c \
stack/max_stack.c \
sorts/advanced_sort.c \
sorts/simple_sort.c \
sorts/advanced_prepare_stacks.c \

TEST_NAME = unit-tests

TEST_SRC_NAME = \
main.c \
stack_suite.c \
operations_suite.c \
utils_suite.c

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
	$(MAKE) -C $(PATHL) fclean

re : fclean all

test : all $(TEST_BIN)
	./$(TEST_BIN)

$(PATHL)/libftprintfgnl.a :
	$(MAKE) -C $(PATHL)

################################################################################
