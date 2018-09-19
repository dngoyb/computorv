# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngbanza <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/19 16:06:42 by ngbanza           #+#    #+#              #
#    Updated: 2018/09/19 16:06:49 by ngbanza          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Computor

SRC = computor.c ft_execution.c main.c input_read.c \

FLAG = -Wall -Werror -Wextra

SILENT = --no-print-directory

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
