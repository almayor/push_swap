# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: unite <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/26 02:09:26 by unite             #+#    #+#              #
#    Updated: 2020/05/15 02:05:14 by unite            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CK = checker
SRC_CK_NAME = src/checker.c

NAME_PS = push_swap
SRC_PS_NAME = src/push_swap.c

SRC_NAME = $(wildcard src/*/*/*/*)

################################################################################

PATHS = .
PATHO = obj
PATHI = include
PATHL = libftprintfgnl

PATHTESTS = test/unit/src
PATHTESTI = test/unit/include

################################################################################

COMPILE = gcc -c
LINK = gcc

CFLAGS += -Wall -Wextra -Werror
CFLAGS += -O3 -std=gnu11 -ffast-math -march=native
CFLAGS += -MMD
CFLAGS += -lftprintfgnl -L $(PATHL)

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

################################################################################

$(NAME_CK) : $(OBJ_CK) $(OBJ)
	$(LINK) $^ -o $@

$(NAME_PS) : $(OBJ_PS) $(OBJ)
	$(LINK) $^ -o $@

$(PATHO)/%.o : $(PATHS)/%.c
	mkdir -p $(@D)
	$(COMPILE) $(CFLAGS) -I$(PATHI) $< -o $@

################################################################################

SRC_TEST += $(wildcard $(PATHTESTS)/*.c)
SRC_TEST += $(wildcard $(PATHTESTS)/*/*.c)
SRC_TEST += $(wildcard $(PATHTESTS)/*/*/*.c)

OBJ_TEST = $(patsubst $(PATHTESTS)/%.c, $(PATHTESTO)/%.o, $(SRC_TEST))

$(NAME_TESTS) : $(OBJ_TEST) $(OBJ)
	$(LINK) $^ -o $@

$(PATHTESTO)/%.o : $(PATHTESTS)/%.c
	mkdir -p $(@D)
	$(COMPILE) $(CFLAGS) -I$(PATHI) -I$(PATHTESTI) $< -o $@

################################################################################

DEP += $(patsubst %.c, $(PATHO)/%.d, $(SRC_NAME))
DEP += $(patsubst %.c, $(PATHO)/%.d, $(SRC_CK_NAME))
DEP += $(patsubst %.c, $(PATHO)/%.d, $(SRC_PS_NAME))
DEP += $(patsubst %.c, $(PATHTESTO)/%.d, $(SRC_TEST_NAME))

-include $(DEP)

################################################################################

.PHONY : all clean fclean re test

all : $(PATHL)/libftprintfgnl.a $(NAME_CK) $(NAME_PS)

fclean : clean
	rm -f $(NAME_CK) $(NAME_PS) $(NAME_TESTS)

clean :
	rm -rf $(PATHO)

re : fclean all

test : all $(NAME_TEST)
	./$(NAME_TEST)

$(PATHL)/libftprintfgnl.a :
	make -C $(PATHL)

################################################################################
