NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I./libft

SRCS = ft_printf.c ft_check.c ft_print.c ft_utils.c ft_printstr.c ft_printint.c

OBJS = $(SRCS:.c=.o)

all:$(NAME)

$(NAME):$(OBJS)
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

.PHONY: clean all fclean re
