# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/02 05:01:28 by mazoukni          #+#    #+#              #
#    Updated: 2022/04/02 05:01:38 by mazoukni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all re fclean clean
NAME = EasyFind
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
SRC = main.cpp
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