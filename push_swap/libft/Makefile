CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
DEBUGFLAGS	= -g -O0

# Original LIBFT files
OG_DIR		= og
OG_SRCS		= ft_isalpha.c ft_isdigit.c ft_isalnum.c \
			  ft_isascii.c ft_isprint.c ft_strlen.c ft_toupper.c \
			  ft_tolower.c ft_atoi.c ft_memset.c ft_memcpy.c \
			  ft_bzero.c ft_calloc.c ft_memchr.c ft_memcmp.c \
			  ft_memmove.c ft_strchr.c ft_strdup.c ft_strjoin.c \
			  ft_strlcat.c ft_strlcpy.c ft_strncmp.c ft_strnstr.c \
			  ft_strrchr.c ft_substr.c ft_strmapi.c ft_strtrim.c \
			  ft_split.c ft_itoa.c ft_putchar_fd.c ft_putstr_fd.c \
			  ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c \
			  ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
			  ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c \
			  ft_lstiter.c ft_lstmap.c ft_striteri.c 
OG_SRCS2	= $(addprefix $(OG_DIR)/, $(OG_SRCS))
OG_OBJS		= $(OG_SRCS2:.c=.o)

# PRINTF files
PRINTF_DIR	= printf
PRINTF_SRCS	= ft_printf.c print_single_chars.c print_ints.c \
			  print_hex.c print_str.c
PRINTF_SRCS2= $(addprefix $(PRINTF_DIR)/, $(PRINTF_SRCS))
PRINTF_OBJS	= $(PRINTF_SRCS2:.c=.o)

# GNL files
GNL_DIR		= gnl
GNL_SRCS	= get_next_line.c get_next_line_utils.c
GNL_SRCS2	= $(addprefix $(GNL_DIR)/, $(GNL_SRCS))
GNL_OBJS	= $(GNL_SRCS2:.c=.o)

NAME		= libft.a

all: $(NAME)

$(NAME): $(OG_OBJS) $(PRINTF_OBJS) $(GNL_OBJS)
	@echo "\nAll files compiled. Starting packaging to static library...\n"
	ar rcs $(NAME) $(OG_OBJS)
	ar rcs $(NAME) $(PRINTF_OBJS)
	ar rcs $(NAME) $(GNL_OBJS)
	@echo "\nlibft.a generated.\n"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ -I.

clean:
	@echo "\nCleaning all objects files...\n"
	@rm -f $(OG_OBJS)
	@rm -f $(PRINTF_OBJS)
	@rm -f $(GNL_OBJS)

fclean: clean
	@echo "\nCleaning $(NAME)\n"
	@rm -f $(NAME)

re: fclean all
