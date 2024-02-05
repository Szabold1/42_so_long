# Makefile for so_long

# Compiler and Flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(LIBFT_DIR) -I/usr/X11/include
LFLAGS = -L$(LIBFT_DIR) -lft_full -L/usr/X11/lib -lX11 -lmlx -lXext

# Target Binary
NAME = so_long

# File and Directory Management
RM = rm -f
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft_full.a

# Source Directories
SRC_DIR = ./src

# Source Files
SRC = check_map.c \
		draw.c \
		exit_free.c \
		handle_events.c \
		main.c \
		move_player.c \
		set_game_data.c \
		set_graphics_data.c

# Object Files
OBJ = $(SRC:%.c=$(SRC_DIR)/%.o)

# Compilation Rules
$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@

# Target Rules
$(NAME): $(LIBFT) $(OBJ)
	@echo "🔨 compiling $(NAME)"
	@$(CC) $(OBJ) $(LFLAGS) -o $(NAME)
	@echo "✅ $(NAME) compiled"

# Library Compilation
$(LIBFT): $(LIBFT_DIR)
	@echo "🔨 compiling libft"
	@cd $(LIBFT_DIR) && $(MAKE) full
	@echo "✅ libft compiled"

# Phony Targets
all: $(NAME)

clean:
	@cd $(LIBFT_DIR) && $(MAKE) clean
	@$(RM) $(OBJ)
	@echo "✅ object files removed"

fclean: clean
	@cd $(LIBFT_DIR) && $(MAKE) fclean
	@echo "✅ libft library removed"
	@$(RM) $(NAME)
	@echo "✅ $(NAME) executable removed"

re: fclean all

.PHONY: all clean fclean re
