# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/10 12:50:22 by emajuri           #+#    #+#              #
#    Updated: 2023/08/02 13:22:03 by emajuri          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = wordle

SRC = main.cpp Wordle.cpp

OBJ = $(addprefix obj/,$(SRC:%.cpp=%.o))

DEP = $(OBJ:%.o=%.d)

#folders
INC = ./inc
SRC_DIR = ./src
OBJ_DIR = ./obj

#flags
WWW = -Wall -Wextra -Werror
FLAGS = $(WWW) -I inc

.PHONY: all clean fclean re

all: $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ_DIR) $(OBJ)
	c++ $(FLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

-include $(DEP)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	c++ $(FLAGS) -MMD -c $< -o $@

re: fclean all
