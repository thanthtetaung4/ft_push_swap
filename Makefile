# Project Names
NAME = push_swap
TEST = test_o

# Compiler and Flags
CC = cc
# CFLAGS = -Wall -Wextra -Werror
CFLAGS =

# Libft Paths and Files
LIBFT_PATH = ./libft
LIBFT = ${LIBFT_PATH}/libft.a

# Source Paths
DISCRETIZE_PATH = ./src/discretization
VALIDATION_PATH = ./src/input_validation
FREE_PATH = ./src/free
UTILS_PATH = ./src/utils

# Source Files
SRC = ./src/main.c $(VALIDATION_PATH)/input_validation.c $(VALIDATION_PATH)/input_validation_utils.c \
		$(VALIDATION_PATH)/input_validation_helpers.c $(UTILS_PATH)/general_utils.c \
		$(FREE_PATH)/ft_free.c

TEST_SRC = ./src/test/test.c $(VALIDATION_PATH)/input_validation_utils.c \
			$(FREE_PATH)/ft_free.c

# Object Files
OBJ = $(SRC:.c=.o)
TEST_OBJ = $(TEST_SRC:.c=.o)

# All Target
all: $(NAME)
	@echo "\033[32m[ $(NAME) is ready for use]\033[0m"

test: $(TEST)
	@echo "\033[32m[ $(TEST) is ready for use]\033[0m"

#TEST Target
$(TEST): $(TEST_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -o $(TEST) $(TEST_OBJ) $(LIBFT)

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
