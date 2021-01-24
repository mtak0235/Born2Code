# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sehwpark <sehwpark@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/21 20:27:43 by sehwpark          #+#    #+#              #
#    Updated: 2021/01/23 22:47:10 by sehwpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = libft
LIB = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBC = ar rc
NAME = libftprintf.a
SRCS = ft_printf.c \
       ft_printf_utils.c \
	   print_func.c \
	   print_nbr.c \
	   ft_itoa_remake.c \
	   print_p.c \
	   print_char.c

OBJS = $(SRCS:.c=.o)

%.o : %.c
	$(CC) $(CFLAGS) -I . -c $< -o $@

$(NAME) : $(OBJS)
	make -C $(LIBFT)/
	cp $(LIBFT)/$(LIB) $(NAME)
	$(LIBC) $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -f $(OBJS)
	make clean -C $(LIBFT)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT)

re: fclean all

.PHONY: clean all fclean re
