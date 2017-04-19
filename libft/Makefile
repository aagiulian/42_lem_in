# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agiulian <arthur.giuliano@student.42.fr>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/17 22:23:16 by agiulian          #+#    #+#              #
#    Updated: 2017/03/17 18:49:18 by agiulian         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = libftprintf.a

SRC = libft/ft_atoi.c \
	  libft/ft_memalloc.c \
	  libft/ft_putchar_fd.c \
	  libft/ft_strclr.c \
	  libft/ft_strlcat.c \
	  libft/ft_strnew.c \
	  libft/ft_bzero.c \
	  libft/ft_memccpy.c \
	  libft/ft_putendl.c \
	  libft/ft_strcmp.c \
	  libft/ft_strlen.c \
	  libft/ft_strnstr.c \
	  libft/ft_isalnum.c \
	  libft/ft_memchr.c \
	  libft/ft_putendl_fd.c \
	  libft/ft_strcpy.c \
	  libft/ft_strmap.c \
	  libft/ft_strrchr.c \
	  libft/ft_isalpha.c \
	  libft/ft_memcmp.c \
	  libft/ft_putnbr.c \
	  libft/ft_strdel.c \
	  libft/ft_strmapi.c \
	  libft/ft_strsplit.c \
	  libft/ft_isascii.c \
	  libft/ft_memcpy.c \
	  libft/ft_putnbr_fd.c \
	  libft/ft_strdup.c \
	  libft/ft_strncat.c \
	  libft/ft_strstr.c \
	  libft/ft_isdigit.c \
	  libft/ft_memdel.c \
	  libft/ft_putstr.c \
	  libft/ft_strequ.c \
	  libft/ft_strncmp.c \
	  libft/ft_strsub.c \
	  libft/ft_isprint.c \
	  libft/ft_memmove.c \
	  libft/ft_putstr_fd.c \
	  libft/ft_striter.c \
	  libft/ft_strncpy.c \
	  libft/ft_strtrim.c \
	  libft/ft_ispunct.c \
	  libft/ft_memset.c \
	  libft/ft_strcat.c \
	  libft/ft_striteri.c \
	  libft/ft_strndup.c \
	  libft/ft_tolower.c \
	  libft/ft_itoa.c \
	  libft/ft_putchar.c \
	  libft/ft_strchr.c \
	  libft/ft_strjoin.c \
	  libft/ft_strnequ.c \
	  libft/ft_toupper.c \
	  libft/ft_lstnew.c \
	  libft/ft_lstdelone.c \
	  libft/ft_lstdel.c \
	  libft/ft_lstadd.c \
	  libft/ft_lstiter.c \
	  libft/ft_lstmap.c \
	  libft/ft_lstsize.c \
	  libft/ft_lstpush.c \
	  libft/ft_tablen.c \
	  libft/ft_tabdel.c \
	  libft/ft_lstpop.c \
	  libft/ft_strnjoin.c \
	  libft/ft_intlen.c \
	  libft/ft_intsize.c \
	  libft/ft_itoabase.c \
	  libft/ft_itoabase_cap.c \
	  libft/ft_uitoabase.c \
	  libft/ft_uitoabase_cap.c \
	  libft/get_next_line.c \
	  printf/ft_printf.c \
	  printf/utility.c \
	  printf/va_arg.c \
	  printf/priority.c \
	  printf/struct_handling.c \
	  printf/grep.c \
	  printf/char_arg.c \
	  printf/int_arg.c \
	  printf/uint_arg.c \
	  printf/bint_arg.c \
	  printf/oint_arg.c \
	  printf/str_arg.c \
	  printf/xint_arg.c \
	  printf/xcapint_arg.c \
	  printf/pct_arg.c \
	  printf/flags.c \
	  printf/ft_memjoin.c \
	  printf/ft_memnjoin.c \
	  printf/parse.c \
	  printf/color.c \
	  printf/edit.c \
	  printf/unicode.c


HEAD = -Ilibft/includes/ -Iprintf/.

ECHO = printf

OBJECT = $(SRC:.c=.o)

CFLAGS = $(HEAD) -O3 -Wall -Werror -Wextra

%.o	:	%.c 
		@$(CC) $(CFLAGS) -o $@ -c $<

all: $(NAME)

$(NAME): $(OBJECT)
	@ar rc $(NAME) $(OBJECT)
	@ranlib $(NAME)
	@$(ECHO) "\033[32mCompiling library\n\033[0m"

clean:
	@rm -f $(OBJECT) && $(ECHO) "\033[32m[Deleting library objects]\033[0m\n"

fclean: clean
	@rm -f $(NAME)
	@$(ECHO) "\033[32m[Deleting library binary]\033[0m\n"

re: fclean all
