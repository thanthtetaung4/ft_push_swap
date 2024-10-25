# Project Names
NAME = push_swap

# Compiler and Flags
CC = cc
CFLAGS = -Wall -Wextra -Werror


# Libft Paths and Files
LIBFT_PATH = ./libft
LIBFT = ${LIBFT_PATH}/libft.a

# Source Paths
DISCRETIZE_PATH = ./src/discretization
VALIDATION_PATH = ./src/input_validation
FREE_PATH = ./src/free
UTILS_PATH = ./src/utils
INIT_PATH = ./src/init
SORTING_PATH = ./src/sorting
OPERATION_PATH = ./src/operations
# Source Files
SRC = ./src/main.c $(VALIDATION_PATH)/input_validation.c $(VALIDATION_PATH)/input_validation_utils.c \
		$(UTILS_PATH)/general_utils.c $(DISCRETIZE_PATH)/ft_discretize.c \
		$(FREE_PATH)/ft_free.c $(INIT_PATH)/init.c \
		$(SORTING_PATH)/sorting.c $(SORTING_PATH)/sorting_utils.c \
		$(OPERATION_PATH)/operations_a.c $(OPERATION_PATH)/operations_b.c \
		$(OPERATION_PATH)/operations_c.c $(SORTING_PATH)/sorting_helpers.c \
		$(SORTING_PATH)/sorting_methods.c

# Object Files
OBJ = $(SRC:.c=.o)
TEST_OBJ = $(TEST_SRC:.c=.o)

# All Target
all: $(NAME)
	@echo "\033[32m[ $(NAME) is ready for use]\033[0m"

# NAME Target
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
