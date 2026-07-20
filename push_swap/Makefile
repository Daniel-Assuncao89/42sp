LIBFT_DIR	:= libft
LIBFT		:= $(LIBFT_DIR)/libft.a

# Compiler
CC 			:= cc

# Compiler/Preprocessor flags (used for compiling files to objects)
CFLAGS		:= -Wall -Wextra -Werror -Iincludes -I$(LIBFT_DIR)

# Linker flags (directories to search)
LDFLAGS		:= -L$(LIBFT_DIR)

# Libraries to link (must always go at the very end of the command)
LDLIBS		:= -lft 

DEBUGFLAGS	:= -g -O0

SRCS		:= 	push_swap.c \
				stack_utils.c \
				algorithms/simple_algo.c \
				algorithms/medium_algo.c \
				operations/push.c \
				operations/swap.c \
				operations/rotate.c \
				operations/reverse_rotate.c \

PARSE_SRCS	:= atoi_parsing.c \
			   count_parsing.c \
			   fill_parsing.c \
			   flags_parsing.c \
			   free_parsing.c \
			   parsing.c
PARSE_SRCS2 := $(addprefix parse/, $(PARSE_SRCS))

# OBJS		:= $(SRCS:.c=.o)

NAME		:= push_swap

all: $(NAME)

$(NAME): $(LIBFT) $(SRCS) $(PARSE_SRCS2)
	$(CC) $(CFLAGS) $(LDFLAGS) $(SRCS) $(PARSE_SRCS2) $(LDLIBS) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -f $(OBJS)
	$(MAKE) clean -C $(LIBFT_DIR)

fclean:
	rm -f $(NAME)
	# rm -f $(OBJS)
	$(MAKE) fclean -C $(LIBFT_DIR)

re:	fclean all

test_parse: $(LIBFT)
	$(CC) $(CFLAGS) $(LDFLAGS) $(PARSE_SRCS2) test_parse.c $(LDLIBS) -o test_parse

debug: $(LIBFT)
	$(CC) $(CFLAGS) $(DEBUGFLAGS) $(LDFLAGS) $(SRCS) $(PARSE_SRCS2) $(LDLIBS) -o $(NAME)

.PHONY: all clean fclean re

