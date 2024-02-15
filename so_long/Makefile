# Makefile for so_long

# Compiler and Flags
CC = cc
CFLAGS = -g -Wall -Wextra -Werror -I$(LIBFT_DIR) -I/usr/X11/include
LFLAGS = -L$(LIBFT_DIR) -lft_full -L/usr/X11/lib -lX11 -lmlx -lXext

# Target Binary
NAME = so_long
NAME_BONUS = so_long_bonus

# File and Directory Management
RM = rm -f
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft_full.a

# Source Directories
SRC_DIR = ./src
SRC_DIR_BONUS = ./src_bonus

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

SRC_BONUS = check_map_bonus.c \
			check_map_path_bonus.c \
			clean_up_2_bonus.c \
			clean_up_bonus.c \
			create_map_bonus.c \
			display_map_bonus.c \
			display_moves_bonus.c \
			errors_bonus.c \
			game_logic_bonus.c \
			handle_events_bonus.c \
			init_data_bonus.c \
			init_data_memory_bonus.c \
			init_graphics_bonus.c \
			init_mlx_bonus.c \
			main_bonus.c \
			set_game_data_bonus.c

# Object Files
OBJ = $(SRC:%.c=$(SRC_DIR)/%.o)
OBJ_BONUS = $(SRC_BONUS:%.c=$(SRC_DIR_BONUS)/%.o)

# Compilation Rules
$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(SRC_DIR_BONUS)/%.o: $(SRC_DIR_BONUS)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@

# Target Rules
$(NAME): $(LIBFT) $(OBJ)
	@echo "🔨 compiling $(NAME)"
	@$(CC) $(OBJ) $(LFLAGS) -o $(NAME)
	@echo "✅ $(NAME) compiled"

$(NAME_BONUS): $(LIBFT) $(OBJ_BONUS)
	@echo "🔨 compiling $(NAME_BONUS)"
	@$(CC) $(OBJ_BONUS) $(LFLAGS) -o $(NAME_BONUS)
	@echo "✅ $(NAME_BONUS) compiled"

# Library Compilation
$(LIBFT): $(LIBFT_DIR)
	@echo "🔨 compiling libft"
	@cd $(LIBFT_DIR) && $(MAKE) --quiet full
	@echo "✅ libft compiled"

# Phony Targets
all: $(NAME)

clean:
	@cd $(LIBFT_DIR) && $(MAKE) --quiet clean
	@$(RM) $(OBJ) $(OBJ_BONUS)
	@echo "✅ object files removed"

fclean: clean
	@cd $(LIBFT_DIR) && $(MAKE) --quiet fclean
	@echo "✅ libft library removed"
	@$(RM) $(NAME) $(NAME_BONUS)
	@echo "✅ executables removed"

re: fclean all

bonus: $(NAME_BONUS)

rebonus: fclean bonus

.PHONY: all clean fclean re bonus
