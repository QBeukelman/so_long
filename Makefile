# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: quentinbeukelman <quentinbeukelman@stud      +#+                      #
#                                                    +#+                       #
#    Created: 2023/01/12 11:42:25 by quentinbeuk   #+#    #+#                  #
#    Updated: 2023/01/20 15:21:56 by quentinbeuk   ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

# ===== Names =====
NAME = so_long.a
NAME_MLX = mlx.a
NAME_EXCUITABLE = so_long

# ===== Compile =====
CC = gcc
CFLAGS = -c -Wall -Werror -Wextra
INCLUDES = -I./INCLUDES
MLX_FLAGS = -I include -lglfw -framework Cocoa -framework OpenGL -framework IOKit
MLX_FLAGS_42 = -I include -lglfw -L "/Users/$USER/.brew/opt/glfw/lib/" -framework Cocoa -framework OpenGL -framework IOKit

# ===== Colors =====
BOLD	:= \033[1m
RED		:= \033[31;1m
GREEN	:= \033[32;1m
YELLOW	:= \033[33;1m
BLUE	:= \033[34;1m
RESET	:= \033[0m

# ===== Sources =====
SOURCES = main.c \

SOURCES_MAP = map_parser.c \
			map_validation.c \
			freeing_functions.c \
			struct_functions.c \
			map_solve.c \
			get_coordinates.c \

SOURCES_GAME = images_struct.c \
			images_to_window.c \
			player_movement.c \
			player_movement_helper.c \
			game_messages.c \

# ===== Manage Directories =====
INC = inc
DIR_OBJ = obj

DIR_SOURCES = sources
DIR_SOURCES_MAP = sources/map_parser
DIR_SOURCES_GAME = sources/game_handler

O_SOURCES = $(SOURCES:%.c=$(DIR_OBJ)/$(DIR_SOURCES)/%.o)
O_SOURCES_MAP = $(SOURCES_MAP:%.c=$(DIR_OBJ)/$(DIR_SOURCES_MAP)/%.o)
O_SOURCES_GAME = $(SOURCES_GAME:%.c=$(DIR_OBJ)/$(DIR_SOURCES_GAME)/%.o)

$(DIR_OBJ)/$(DIR_SOURCES)/%.o: $(DIR_SOURCES)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -I $(INC) -c $< -o $@

$(DIR_OBJ)/$(DIR_SOURCES_MAP)/%.o: $(DIR_SOURCES_MAP)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -I $(INC) -c $< -o $@

$(DIR_OBJ)/$(DIR_SOURCES_GAME)/%.o: $(DIR_SOURCES_GAME)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -I $(INC) -c $< -o $@

# ===== Rules =====
all: $(NAME)

$(NAME): $(O_SOURCES) $(O_SOURCES_MAP) $(O_SOURCES_GAME)
	@echo "$(BLUE)$(BOLD)\nCompiling library: LIBFT ...$(RESET)"
	@$(MAKE) all -C ./includes/libft/
	@cp includes/libft/libft.a $(NAME)
	@mv $(NAME) $(DIR_SOURCES)
	@echo "$(BLUE)$(BOLD)\nCompiling library: MLX42 ...$(RESET)"
	@$(MAKE) all -C ./includes/MLX42/
	@cp includes/MLX42/libmlx42.a $(NAME_MLX)
	@mv $(NAME_MLX) $(DIR_SOURCES)
	@$(AR) rcs $@ $^
	@ranlib $@
	@echo "$(BLUE)$(BOLD)\nCompiling program: so_long ...$(RESET)"
	@rm $(NAME)
	@$(CC) -o $(NAME_EXCUITABLE) $(DIR_SOURCES)/$(SOURCES) $(DIR_SOURCES_MAP)/*.c $(DIR_SOURCES_GAME)/*.c $(DIR_SOURCES)/so_long.a $(DIR_SOURCES)/mlx.a $(MLX_FLAGS)
	@echo "$(GREEN)$(BOLD)\nCompile sucessfull!\n$(RESET)"

clean:
	@echo "$(BLUE)\nCleaning ...$(RESET)"
	@$(RM) -rf $(DIR_OBJ)
	@$(MAKE) clean -C ./includes/libft/
	@$(MAKE) clean -C ./includes/MLX42/
	@rm -rf $(EXTRA_O)
	@rm -rf $(OBJS)
	@echo "$(GREEN)$(BOLD)\nAll clean!\n$(RESET)"

fclean: clean
	@$(RM) $(DIR_SOURCES)/$(NAME)
	@$(RM) $(DIR_SOURCES)/$(NAME_MLX)
	@$(MAKE) fclean -C ./includes/libft/
	@$(MAKE) fclean -C ./includes/MLX42/

re: fclean all

.PHONY: clean fclean re all
