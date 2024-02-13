# Makefile for so_long

# Compiler and Flags
CC = cc
CFLAGS = -g -Wall -Wextra -Werror -I$(LIBFT_DIR) -I/usr/X11/include
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
SRC = check_map_path.c \
		check_map.c \
		clean_up.c \
		clean_up_2.c \
		create_map.c \
		display_map.c \
		errors.c \
		game_logic.c \
		handle_events.c \
		init_data_memory.c \
		init_data.c \
		init_graphics.c \
		main.c \
		set_game_data.c

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
	@cd $(LIBFT_DIR) && $(MAKE) --quiet full
	@echo "✅ libft compiled"

# Phony Targets
all: $(NAME)

clean:
	@cd $(LIBFT_DIR) && $(MAKE) --quiet clean
	@$(RM) $(OBJ)
	@echo "✅ object files removed"

fclean: clean
	@cd $(LIBFT_DIR) && $(MAKE) --quiet fclean
	@echo "✅ libft library removed"
	@$(RM) $(NAME)
	@echo "✅ $(NAME) executable removed"

re: fclean all

.PHONY: all clean fclean re
