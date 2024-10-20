# Project Names
NAME = push_swap

# Compiler and Flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Libft Paths and Files
LIBFT_PATH = ./libft
LIBFT = ${LIBFT_PATH}/libft.a

# Source Paths
DISCRETIZE_PATH = ./src/discretization

# Source Files
SRC = ./src/main.c

# Object Files
OBJ = $(SRC:.c=.o)

# All Target
all: $(NAME)
	@echo "\033[32m[ $(SRC) is ready for use]\033[0m"

# Server Target
$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)

# Compile Libft
$(LIBFT):
	make -C $(LIBFT_PATH)

# Clean Target
clean:
	rm -f $(OBJ)
	make -C $(LIBFT_PATH) clean
	@echo "\033[33m[Cleaned up]\033[0m"

# Full Clean Target
fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_PATH) fclean
	@echo "\033[33m[Cleaned up]\033[0m"

# Rebuild Target
re: fclean all

.PHONY: all clean fclean re
