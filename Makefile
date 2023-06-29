# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jogomes- <leugim3005@gmail.com>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/22 13:29:56 by jogomes-          #+#    #+#              #
#    Updated: 2023/06/19 19:29:13 by jogomes-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
SRC = src/main.c src/error.c src/map/check_map.c src/map/save_map.c\
		src/map/check_floor_ceiling.c src/utils.c src/map/validate_map.c \
		src/map/find_player.c src/raycasting.c

OBJ = $(SRC:.c=.o)
CC = @cc
CFLAGS = -Wall -Wextra -Werror -g
RM = @rm -f

$(NAME) : $(OBJ) ./libft/libft.a
	$(CC) $(CFLAGS) $(OBJ) libft/libft.a mlx/libmlx_Linux.a -lXext -lX11 -lm -o $(NAME)
	@echo "'cub3d' created!"

all : $(NAME)

./libft/libft.a :
	@make -s -C libft

clean : 
	$(RM) $(OBJ)
	@make clean -s -C libft
	@echo "Cleaning done!"

fclean : clean
	$(RM) *.a
	@make fclean -s -C libft
	$(RM) $(NAME)

re : fclean
	@make

valgrind:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --trace-children=yes --track-fds=yes ./cub3d maps/base.cub

norminette:
	@norminette src
	@norminette include

.PHONY : all clean fclean re valgrind norminette
