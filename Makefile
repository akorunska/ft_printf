# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akorunsk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/28 17:30:40 by akorunsk          #+#    #+#              #
#    Updated: 2017/12/01 10:33:07 by akorunsk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC =	src/ft_printf.c src/specifier.c \
		src/helpers/initialise.c src/helpers/putnumbrs.c \
		src/helpers/count_digits.c src/helpers/parse.c \
		src/helpers/checker.c src/helpers/output_str.c \
		src/helpers/length_conv.c \
		src/handlers/handle_flags.c \
		src/handlers/handle_char.c src/handlers/handle_int.c \
		src/handlers/handle_string.c src/handlers/handle_percent.c \
		src/handlers/handle_octal.c src/handlers/handle_hex.c

INC = -I include/

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

CFLAGS = -c $(FLAGS)

LIBNAME = libft/libft.a

all: $(NAME)

obj: $(OBJ)

$(NAME) : libmake $(OBJ)
	cp $(LIBNAME) $(NAME)
	ar r $(NAME) $(OBJ)

%.o: %.c
		gcc $(CFLAGS) $(INC) -o $@ $<

clean: libclean
		rm -rf $(OBJ)

fclean: libfclean clean
		rm -rf $(NAME)

re: fclean all

test:
	gcc main.c libftprintf.a

libmake:
	@make -C libft/ all

libclean:
	@make -C libft/ clean

libfclean:
	@make -C libft/ fclean
