# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngbanza <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/19 16:06:42 by ngbanza           #+#    #+#              #
#    Updated: 2018/09/24 14:12:54 by ngbanza          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Computor

SRC = computor.c ft_execution.c main.c input_read.c \

UNAME := $(shell uname)

ifeq ($(UNAME), Linux)
FLAG = -Wall -Werror -Wextra -lm
else
FLAG = -Wall -Werror -Wextra
endif

OBJ = $(SRC:.c=.o)

all: $(NAME)
$(NAME):
		@gcc $(FLAG) -c $(SRC)
		@gcc $(FLAG) $(OBJ)  -o $(NAME)
		@printf "\x1b[32mCompiled $(NAME)\x1b[0m\n"

clean:
		@/bin/rm -f $(OBJ) *.o

fclean: clean
		@/bin/rm -f $(NAME)

re: fclean all
