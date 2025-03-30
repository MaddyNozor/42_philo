# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: codespace <codespace@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/16 15:29:24 by mairivie          #+#    #+#              #
#    Updated: 2025/03/29 11:00:18 by codespace        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables

NAME = philo


COMPIL = cc
CFLAGS = -Wall -Wextra -Werror -g3 -pthread -I$(INCLUDE) -I$(LIBFT_INCLUDE)


INCLUDE = include/
SRC_DIR = source/
SRC_LIST = main.c \
		parsing.c \
		speak_to_me.c \
		manip_s_prog_data.c \
		utils.c
		
SRC = $(addprefix $(SRC_DIR), $(SRC_LIST))

OBJ_DIR = obj/
OBJ_LIST = $(addprefix $(OBJ_DIR), $(SRC_LIST:.c=.o))

LIBFT_DIR = libft/
LIBFT = $(LIBFT_DIR)libft.a
LIBFT_INCLUDE = libft/


# Règles

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJ_LIST) $(LIBFT)
	$(COMPIL) $(CFLAGS) $^ -o $@ $(LIBFT) -lm

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	mkdir -p $(OBJ_DIR)
	$(COMPIL) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re