# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seunghoh <seunghoh@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/13 21:17:30 by seunghoh          #+#    #+#              #
#    Updated: 2021/01/15 06:51:06 by seunghoh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I./libft

SRCS = ft_printf.c \
	   parse.c \
	   parse_util.c \
	   parse_int.c \
	   parse_string.c \
	   parse_hex.c \

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	make -C libft all
	cp libft/libft.a $(NAME)
	ar rcs $(NAME) $(OBJS)

clean :
	make -C libft clean
	rm -rf $(OBJS)

fclean : clean
	make -C libft fclean
	rm -rf $(NAME)

re : clean all
