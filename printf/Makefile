NAME = libftprintf.a
CC = cc
LIBFT_DIR = libft/
CFLAGS= -Wall -Wextra -Werror -I ./includes -I $(LIBFT_DIR)
SRCS = srcs/ft_printchar.c srcs/ft_printstr.c \
srcs/ft_printf.c srcs/ft_printptr.c srcs/ft_printnbr.c \
srcs/ft_printhex.c srcs/ft_printunsigned.c

OBJS = $(SRCS:.c=.o)
LIBFT = $(LIBFT_DIR)libft.a
FILE_EXEC = test/example.c

all: $(NAME)
$(LIBFT):
	@make -C $(LIBFT_DIR) 

$(NAME): $(LIBFT) $(OBJS)
	@cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJS)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	@make clean -C $(LIBFT_DIR)
	rm -f $(OBJS)
fclean: clean
	@make fclean -C $(LIBFT_DIR)
	rm -f $(NAME) a.out
re: fclean all

exec: all
	$(CC) $(CFLAGS) $(FILE_EXEC) $(NAME)
	./a.out

.PHONY: all clean fclean re
