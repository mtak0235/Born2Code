# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sehwpark <sehwpark@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/21 20:27:43 by sehwpark          #+#    #+#              #
#    Updated: 2021/01/06 18:50:33 by sehwpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBC = ar rc
NAME = libft.a
SRCS =  ./ft_atoi.c \
    	./ft_bzero.c \
    	./ft_calloc.c \
    	./ft_isalnum.c \
    	./ft_isalpha.c \
    	./ft_isascii.c \
    	./ft_isdigit.c \
    	./ft_isprint.c \
    	./ft_isprint.c \
    	./ft_itoa.c \
    	./ft_memchr.c \
    	./ft_memcmp.c \
    	./ft_memcpy.c \
    	./ft_memccpy.c \
    	./ft_memmove.c \
    	./ft_memset.c \
    	./ft_putchar_fd.c \
    	./ft_putstr_fd.c \
    	./ft_putendl_fd.c \
    	./ft_putnbr_fd.c \
    	./ft_putstr_fd.c \
    	./ft_split.c \
    	./ft_strchr.c \
    	./ft_strdup.c \
    	./ft_strjoin.c \
    	./ft_strlcat.c \
    	./ft_strjoin.c \
    	./ft_strlcat.c \
    	./ft_strlcpy.c \
    	./ft_strlen.c \
    	./ft_strmapi.c \
    	./ft_strncmp.c \
    	./ft_strnstr.c \
    	./ft_strrchr.c \
    	./ft_strrchr.c \
    	./ft_strtrim.c \
    	./ft_substr.c \
    	./ft_tolower.c \
    	./ft_toupper.c 

BONUSES =   ./ft_lstadd_back.c \
    	    ./ft_lstadd_front.c \
    		./ft_lstclear.c \
    		./ft_lstdelone.c \
    		./ft_lstiter.c \
    		./ft_lstlast.c \
    		./ft_lstmap.c \
    		./ft_lstnew.c \
    		./ft_lstsize.c 

OBJS = $(SRCS:.c=.o)
BONUSOBJS = $(BONUSES:.c=.o)

%.o : %.c
	$(CC) $(CFLAGS) -I . -c $< -o $@

$(NAME) : $(OBJS)
	$(LIBC) $(NAME) $(OBJS)

bonus: $(NAME) $(BONUSOBJS)
	$(LIBC) $(NAME) $(BONUSOBJS)

all: $(NAME)

clean:
	rm -f $(OBJS) $(BONUSOBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean all fclean re