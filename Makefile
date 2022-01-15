# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: noufel <noufel@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/08 00:20:25 by nammari           #+#    #+#              #
#    Updated: 2022/01/15 20:06:18 by noufel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_FILES	= $(addprefix srcs/, ft_dprintf.c \
			chained_list.c \
			flag_checkers.c\
			digit_sign_and_prefix.c\
		    flag_values_fill.c\
			specifier_checkers.c\
			utils.c\
			digit_printer.c\
		   	string_printer.c\
			char_printer.c\
			digit_utils.c)

INCLUDE = include/ft_dprintf.h

CC	=		gcc -c

AR	=		ar

ARFLAGS	=	rc

CFLAGS	=	-Wextra -Wall -Werror

NAME	=	libftprintf.a

OBJS	=	$(SRC_FILES:.c=.o)

$(NAME):	$(OBJS)
			make -sC libft
			mv libft/libft.a libftprintf.a
			$(AR) $(ARFLAGS) $(NAME) $(OBJS)
			ranlib $(NAME)

%.o:		%.c $(INCLUDE)
			$(CC) -IINCLUDE -o $@ $< $(CFLAGS)

all: $(NAME)

clean:
			rm -rf $(OBJS)
			make clean -sC libft
fclean:		clean
			rm -rf $(NAME)
			make fclean -sC libft

re:			fclean all
