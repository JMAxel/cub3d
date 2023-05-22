# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jogomes- <jogomes-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/22 13:29:56 by jogomes-          #+#    #+#              #
#    Updated: 2023/05/22 17:04:39 by jogomes-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
SRC = src/main.c src/error.c src/map/check_map.c src/map/check_texture.c \
		src/map/check_floor_ceiling.c
OBJ = $(SRC:.c=.o)
CC = @cc
CFLAGS = -Wall -Wextra -Werror
RM = @rm -f

$(NAME) : $(OBJ) ./libft/libft.a
	@$(CC) $(CFLAGS) $(OBJ) libft/libft.a -o $(NAME)
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
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --trace-children=yes --track-fds=yes ./cub3d

.PHONY : all clean fclean re valgrind
