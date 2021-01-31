NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror
SOURCE = ft_printf.c \
	ft_char_str.c \
	ft_flaglist.c \
	ft_hextoa.c \
	ft_option.c \
	ft_split_n.c \
	ft_utils.c \
	ft_utoa.c
LIBFT_PATH = libftprintf
LIBFT_NAME = libft.a
OBJECT = $(SOURCE:.c=.o)
$(NAME): $(OBJECT)
	@make -C ./$(LIBFT_PATH) all
	@cp $(LIBFT_PATH)/$(LIBFT_NAME) $(NAME)
	ar	rcs $(NAME) $(OBJECT)
$(OBJECT): $(SOURCE)
	gcc $(CFLAGS) -c $(SOURCE)
all: $(NAME)
clean:
	@make -C ./$(LIBFT_PATH) clean
	@rm -f *.o
fclean:
	@make -C ./$(LIBFT_PATH) fclean
	@rm -f *.o
	@rm -f *.a
re:	fclean all

.PHONY: all clean fclean re