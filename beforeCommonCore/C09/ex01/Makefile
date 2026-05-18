NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = 	srcs/ft_putchar.c \
		srcs/ft_strlen.c \
		srcs/ft_putstr.c \
		srcs/ft_strcmp.c \
		srcs/ft_swap.c
INC = -I includes
OBJS = $(SRCS:.c=.o)
$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)
%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@
all: $(NAME)
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all
