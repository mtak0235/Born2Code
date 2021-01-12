# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtak <mtak@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/22 13:25:13 by mtak              #+#    #+#              #
#    Updated: 2020/12/26 02:22:11 by mtak             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)
NAME = libft.a
HEADER = libft.h

all : $(NAME)
	
bonus : all

%.o : %.c $(HEADER)
	$(CC) -c $(CFLAGS) $< -o $@

$(NAME) : $(OBJS)
	ar crvs $(NAME) $(OBJS)

clean : 
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all 

.PHONY : all bonus clean fclean re 

