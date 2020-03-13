# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: unite <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/26 02:09:26 by unite             #+#    #+#              #
#    Updated: 2020/02/26 05:18:34 by unite            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CHECKER = checker
SRC_CHECKER_NAME = checker.c

NAME_PUSHSWAP = push_swap
SRC_PUSHSWAP_NAME = push_swap.c

################################################################################

SRC_NAME += \
operations/perform_operation.c \
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

SRC_NAME += \
sorting/insertion_sort.c \
sorting/quick_sort.c \

SRC_NAME += \
stack/free_stack.c \
stack/has_duplicates_stack.c \
stack/is_empty_stack.c \
stack/is_sorted_stack.c \
stack/new_stack.c \
stack/print_stack.c \
stack/pull_stack.c \
stack/push_stack.c \
stack/reverse_rotate_stack.c \
stack/rotate_stack.c \
stack/swap_stack.c \

SRC_NAME += \
utils/arguments_to_stack.c \
utils/ft_atoi2.c \
utils/is_numeric_string.c \
utils/print_trace.c \

################################################################################

PATHS = srcs
PATHO = objs
PATHI = includes

PATHFT = libftprintf.a

################################################################################

COMPILE = gcc -c
LINK = gcc

CFLAGS += -Wall -Wextra -Werror
CFLAGS += -O3 -std=gnu11 -ffast-math -march=native
CFLAGS += -MMD

################################################################################

TRUE = 1
FALSE = 0

ifeq ($(DEBUG), $(TRUE)) 
	COMPILE += -g
endif

################################################################################

SRC = $(patsubst %.c, $(PATHS)/%.c, $(SRC_NAME))
OBJ = $(patsubst %.c, $(PATHO)/%.o, $(SRC_NAME))

SRC_CHECKER = $(patsubst %.c, $(PATHS)/%.c, $(SRC_CHECKER_NAME))
OBJ_CHECKER = $(patsubst %.c, $(PATHO)/%.o, $(SRC_CHECKER_NAME))

SRC_PUSHSWAP = $(patsubst %.c, $(PATHS)/%.c, $(SRC_PUSHSWAP_NAME))
OBJ_PUSHSWAP = $(patsubst %.c, $(PATHO)/%.o, $(SRC_PUSHSWAP_NAME))

################################################################################

$(NAME_CHECKER) : $(OBJ_CHECKER) $(OBJ) $(PATHFT)
	$(LINK) $^ -o $@

$(NAME_PUSHSWAP) : $(OBJ_PUSHSWAP) $(OBJ) $(PATHFT)
	$(LINK) $^ -o $@

$(PATHO)/%.o : $(PATHS)/%.c
	mkdir -p $(@D)
	$(COMPILE) $(CFLAGS) -I$(PATHI) $< -o $@

################################################################################

DEP += $(patsubst %.c, $(PATHO)/%.d, $(SRC_NAME))
DEP += $(patsubst %.c, $(PATHO)/%.d, $(SRC_CHECKER_NAME))
DEP += $(patsubst %.c, $(PATHO)/%.d, $(SRC_PUSHSWAP_NAME))

-include $(DEP)

################################################################################

.PHONY : all clean fclean re

all : $(NAME_CHECKER) $(NAME_PUSHSWAP)

fclean : clean
	rm -f $(NAME_CHECKER) $(NAME_PUSHSWAP)

clean :
	rm -rf $(PATHO)

re : fclean all

################################################################################
