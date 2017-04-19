# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agiulian <arthur.giuliano@student.42.fr>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/17 22:23:16 by agiulian          #+#    #+#              #
#    Updated: 2017/04/19 14:25:01 by agiulian         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc -Wall -Wextra -Werror

NAME = lem-in 

SRC = parse.c

HEAD = -Ilibft/includes/ -Iprintf/. -I.

LIB = libft/libftprintf.a

ECHO = printf

OBJ = $(SRC:.c=.o)

CFLAGS = $(HEAD)

%.o	:	%.c
		@$(CC) $(CFLAGS) -o $@ -c $<

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	@$(CC) $(CFLAGS) -o $(NAME) $(LIB) $(OBJ)
	@$(ECHO) "\033[32m[Compiling lem-in Project]\033[0m\n"

clean:
	@make clean -C libft
	@rm -f $(OBJ) && $(ECHO) "\033[32m[Deleting len-in objects]\033[0m\n"

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)
	@$(ECHO) "\033[32m[Deleting lem-in Binary]\033[0m\n"

re: fclean all
