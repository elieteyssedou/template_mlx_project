# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eteyssed <eteyssed@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/13 20:11:17 by eteyssed          #+#    #+#              #
#    Updated: 2014/11/13 20:11:25 by eteyssed         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	rtv1
SRC		=	
OBJ =		$(SRC:.c=.o)
FLAGS =		-Wall -Wextra -Werror
INCLUDES =	-I . -I includes
LIBFT =		libft/libft.a
MLX =		mlx/libmlx.a
CC =		gcc

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/ fclean
	@make -C libft/
	@$(CC) -O3 $(FLAGS) -o $(NAME) $(INCLUDES) $(OBJ) $(LIBFT) $(MLX)
	@echo "Sucess: Program compiled."

%.o: %.c
	@$(CC) $(FLAGS) -I. -o $@ -c $? 

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
