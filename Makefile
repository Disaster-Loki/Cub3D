# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/20 09:48:32 by sde-carv          #+#    #+#              #
#    Updated: 2024/08/20 09:48:34 by sde-carv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= cub3D
BONUS		= cub3D_bonus
 
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
L_DIR		= ./libft	
LIBFT		= -L$(L_DIR) -lft
M_DIR		= ./minilibx-linux
M_libx		= -L$(M_DIR) -lmlx -lXext -lX11 -lm

RESET		= \033[0m
RED			= \033[31m
BLUE		= \033[34m
YELLOW		= \033[33m
ORANGE		= \033[38;5;208m
GREEN		= \033[32m

S_FILES		= ./src/main.c    						\
			  ./src/close_game.c		  			\
			  ./src/error.c  						\
			  ./src/utils.c  						\
			  ./src/draw_window.c  					\
			  ./src/get_file.c  					\
			  ./src/win_init.c  					\
			  ./src/parsing.c  						\
			  ./src/keyboard.c  					\
			  ./src/ray_cast.c  					\
			  ./src/ray_dda.c  						\
			  ./src/ray_vars.c  					\
			  ./src/pos.c  							\
			  ./src/r_utils.c  						\
			  ./src/validate.c  					\
			  ./src/treat_map.c						\
			  ./src/forbiden_char.c					\
			  ./src/player_in_map.c					\
			  ./src/more_players.c					\
			  ./src/sorrounded_by_1.c				\
			  ./src/help_sorround_by_1.c 			\
			  ./src/many_textures.c					\
			  ./src/good_textures.c					\
			  ./src/textures_path.c					\
			  ./src/textures_extencion.c			\
			  ./src/many_colors.c					\
			  ./src/floor_roof.c					\
			  ./src/init_textures.c					\
			  ./src/ray_draw.c						\
			  ./src/move_player.c					\
			  ./src/changetabsbyspace.c				\

S_FILES_BONUS	= ./bonus/src/main_bonus.c						\
			  	  ./bonus/src/close_game_bonus.c  				\
			      ./bonus/src/error_bonus.c  					\
			      ./bonus/src/utils_bonus.c  					\
			      ./bonus/src/draw_window_bonus.c  				\
			      ./bonus/src/get_file_bonus.c  				\
			      ./bonus/src/win_init_bonus.c  				\
			      ./bonus/src/parsing_bonus.c  					\
			      ./bonus/src/keyboard_bonus.c 	 				\
			      ./bonus/src/ray_cast_bonus.c  				\
			      ./bonus/src/ray_dda_bonus.c  					\
			      ./bonus/src/ray_vars_bonus.c  				\
			      ./bonus/src/pos_bonus.c  						\
			      ./bonus/src/r_utils_bonus.c  					\
			      ./bonus/src/validate_bonus.c  				\
			      ./bonus/src/treat_map_bonus.c					\
			      ./bonus/src/forbiden_char_bonus.c				\
			      ./bonus/src/player_in_map_bonus.c				\
			      ./bonus/src/more_players_bonus.c				\
			      ./bonus/src/sorrounded_by_1_bonus.c			\
			      ./bonus/src/help_sorround_by_1_bonus.c 		\
			      ./bonus/src/many_textures_bonus.c				\
			      ./bonus/src/good_textures_bonus.c				\
			      ./bonus/src/textures_path_bonus.c				\
			      ./bonus/src/textures_extencion_bonus.c		\
			      ./bonus/src/many_colors_bonus.c				\
			      ./bonus/src/floor_roof_bonus.c				\
			      ./bonus/src/init_textures_bonus.c				\
			      ./bonus/src/ray_draw_bonus.c					\
			      ./bonus/src/move_player_bonus.c				\
			      ./bonus/src/mini_map_bonus.c					\
			      ./bonus/src/mouse_press_bonus.c				\
			      ./bonus/src/door_bonus.c						\
			      ./bonus/src/sprite_bonus.c					\
				  ./bonus/src/door_utils_bonus.c				\
				  ./bonus/src/flood_fill.c						\
			      ./bonus/src/validate_door_bonus.c				\
			      ./bonus/src/changetabsbyspace_bonus.c			\

S_OBJ			= $(S_FILES:.c=.o)
S_OBJ_BS		= $(S_FILES_BONUS:.c=.o)

all:	$(NAME)

$(NAME): $(S_OBJ)
		 $(MAKE) -C $(L_DIR)
		 $(MAKE) -C $(M_DIR)
		 $(CC) $(CFLAGS) -o $(NAME) $(S_OBJ) $(LIBFT) $(M_libx)
		 clear
		 @echo "$(GREEN) MANDATORY - COMPILATION COMPLETE$(RESET)"	

bonus:   $(BONUS)

$(BONUS): $(S_OBJ_BS)
		 $(MAKE) -C $(L_DIR)
		 $(MAKE) -C $(M_DIR)
		 $(CC) $(CFLAGS) -o $(BONUS) $(S_OBJ_BS) $(LIBFT) $(M_libx)
		 clear
		 @echo "$(GREEN) BONUS - COMPILATION COMPLETE$(RESET)"

clean:
		@$(MAKE) clean -C $(L_DIR)
		@$(MAKE) clean -C $(M_DIR)
		rm -f $(S_OBJ)
		rm -f $(S_OBJ_BS)
		clear
		@echo "$(ORANGE) CLEANING THE OBJECTS$(RESET)"

fclean: clean
		@$(MAKE) fclean -C $(L_DIR)
		rm -f $(NAME)
		rm -f $(BONUS)
		clear
		@echo "$(RED) CLEARING ALL FILES$(RESET)"

re: fclean all

re_bs: fclean bonus