# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: unite <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/26 02:09:26 by unite             #+#    #+#              #
#    Updated: 2020/03/18 09:52:55 by unite            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CHECKER = checker
SRC_CHECKER_NAME = srcs/checker.c

NAME_PUSHSWAP = push_swap
SRC_PUSHSWAP_NAME = srcs/push_swap.c

NAME_TESTS = tests.out
SRC_TESTS_NAME = srcs/main.c

################################################################################

SRC_NAME += $(wildcard srcs/*/*.c)
SRC_NAME += $(wildcard srcs/*/*/*.c)
SRC_NAME += $(wildcard srcs/*/*/*/*.c)

################################################################################

PATHS = .
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

SRC_TESTS += $(wildcard tests/*.c)
SRC_TESTS += $(wildcard tests/*/*.c)
SRC_TESTS += $(wildcard tests/*/*/*.c)

OBJ_TESTS = $(patsubst %.c, $(PATHO)/%.o, $(SRC_TESTS))

$(NAME_TESTS) : $(OBJ_TESTS) $(PATHFT) $(OBJ)
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

.PHONY : all clean fclean re test

all : $(NAME_CHECKER) $(NAME_PUSHSWAP)

fclean : clean
	rm -f $(NAME_CHECKER) $(NAME_PUSHSWAP) $(NAME_TESTS)

clean :
	rm -rf $(PATHO)

re : fclean all

tests : all $(NAME_TESTS)
	./$(NAME_TESTS)

################################################################################
