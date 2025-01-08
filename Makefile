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

NAME		= cub3d
 
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

S_FILES		= ./src/main.c    			\
			  ./src/close.c  			\
			  ./src/error.c  			\
			  ./src/utils.c  			\
			  ./src/get_file.c  		\
			  ./src/val_file.c  		\
			  ./src/win_init.c  		\
			  ./src/parsing.c  			\

S_OBJ		= $(S_FILES:.c=.o)

all:	$(NAME)

$(NAME): $(S_OBJ)
		 $(MAKE) -C $(L_DIR)
		 $(MAKE) -C $(M_DIR)
		 $(CC) $(CFLAGS) -o $(NAME) $(S_OBJ) $(LIBFT) $(M_libx)
		 clear
		 @echo "$(GREEN) MANDATORY - COMPILATION COMPLETE$(RESET)"	

clean:
		@$(MAKE) clean -C $(L_DIR)
		@$(MAKE) clean -C $(M_DIR)
		rm -f $(S_OBJ)
		clear
		@echo "$(ORANGE) CLEANING THE OBJECTS$(RESET)"

fclean: clean
		@$(MAKE) fclean -C $(L_DIR)
		rm -f $(NAME)
		clear
		@echo "$(RED) CLEARING ALL FILES$(RESET)"

re: fclean all