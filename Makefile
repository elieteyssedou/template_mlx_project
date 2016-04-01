# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Elie <Elie@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/13 20:11:17 by eteyssed          #+#    #+#              #
#    Updated: 2016/04/01 18:47:08 by Elie             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	rtv1
SRC		=	lib/main.c lib/libmlx.c
OBJ =		$(SRC:.c=.o)
FLAGS =		-Wall -Wextra -Werror
INCLUDES =	-I . -I includes/ -I libft/
LIBFT =		libft/libft.a
MLX =		-Lmlx/ -lmlx -framework OPENGL -framework Appkit
CC =		gcc

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/ fclean
	@make -C libft/
	@$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(MLX)
	@echo "Sucess: Program compiled."

%.o: %.c
	@$(CC) $(FLAGS) $(INCLUDES) -o $@ -c $?

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
