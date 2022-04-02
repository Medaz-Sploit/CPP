# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/02 04:35:07 by mazoukni          #+#    #+#              #
#    Updated: 2022/04/02 04:37:02 by mazoukni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all re fclean clean
NAME = Literal
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
SRC = main.cpp Literal.cpp
OBJ = $(SRC:.cpp=.o)

%.o %.cpp:
	$(CC) $(FLAGS) -c $(SRC)
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all