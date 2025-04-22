# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: codespace <codespace@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/16 15:29:24 by mairivie          #+#    #+#              #
#    Updated: 2025/04/22 21:50:02 by codespace        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables

NAME = philo


COMPIL = cc
CFLAGS = -Wall -Wextra -Werror -g3 -pthread -I$(INCLUDE)


INCLUDE = include/
SRC_DIR = source/
SRC_LIST = main.c \
		parsing.c \
		routine.c \
		init.c \
		utils.c \
		getters.c \
		stop_philo.c
		
SRC = $(addprefix $(SRC_DIR), $(SRC_LIST))

OBJ_DIR = obj/
OBJ_LIST = $(addprefix $(OBJ_DIR), $(SRC_LIST:.c=.o))

# LIBFT_DIR = libft/
# LIBFT = $(LIBFT_DIR)libft.a
# LIBFT_INCLUDE = libft/


# Règles

all: $(NAME)

# $(LIBFT):
# 	make -C $(LIBFT_DIR)

$(NAME): $(OBJ_LIST)
	$(COMPIL) $(CFLAGS) $^ -o $(NAME) -lm

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	mkdir -p $(OBJ_DIR)
	$(COMPIL) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
# make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
# make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re