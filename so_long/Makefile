# Makefile for so_long

# Compiler and Flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(LIBFT_DIR)

# Target Binary
NAME = so_long

# File and Directory Management
RM = rm -f
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBS = -L$(LIBFT_DIR) -lft

# Source Directories
SRC_DIR = ./src

# Source Files
SRC = check_map.c \
		error.c \
		main.c \
		set_game_data.c \
		set_graphics_data.c

# Object Files
OBJ = $(SRC:%.c=$(SRC_DIR)/%.o)

# Compilation Rules
$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Target Rules
$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(OBJ) $(LIBS) -o $(NAME)

# Library Compilation
$(LIBFT): $(LIBFT_DIR)
	cd $(LIBFT_DIR) && $(MAKE)

# Phony Targets
all: $(NAME)

clean:
	cd $(LIBFT_DIR) && $(MAKE) clean
	$(RM) $(OBJ)

fclean: clean
	cd $(LIBFT_DIR) && $(MAKE) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re