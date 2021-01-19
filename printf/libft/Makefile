# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seunghoh <seunghoh@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/27 01:53:53 by seunghoh          #+#    #+#              #
#    Updated: 2021/01/13 19:47:39 by seunghoh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
BASE_SRCS = ft_strnstr.c \
			ft_isdigit.c \
			ft_putstr_fd.c\
			ft_strlcpy.c \
			ft_strlen.c \
			ft_memcmp.c \
			ft_putnbr_fd.c \
			ft_strchr.c \
			ft_bzero.c \
			ft_strjoin.c \
			ft_isascii.c \
			ft_memcpy.c \
			ft_memccpy.c \
			ft_isprint.c \
			ft_putendl_fd.c \
			ft_toupper.c \
			ft_split.c \
			ft_isalpha.c \
			ft_memchr.c \
			ft_putchar_fd.c \
			ft_memset.c \
			ft_substr.c \
			ft_strncmp.c \
			ft_strmapi.c \
			ft_strtrim.c \
			ft_memmove.c \
			ft_strlcat.c \
			ft_calloc.c \
			ft_strdup.c \
			ft_atoi.c \
			ft_isalnum.c \
			ft_itoa.c \
			ft_tolower.c \
			ft_strrchr.c \
			ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c \
			get_next_line.c \
			get_next_line_utils.c \
			ft_uitohex.c \
			ft_ptrtohex.c

BASE_OBJS = ${BASE_SRCS:.c=.o}

all : $(NAME)

$(NAME) : ${BASE_OBJS}
	ar rcs ${NAME} $(BASE_OBJS)

clean :
	rm -rf $(BASE_OBJS)

fclean : clean
	rm -rf libft.a

re : clean all
