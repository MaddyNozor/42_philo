# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mairivie <mairivie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/14 13:02:42 by mairive           #+#    #+#              #
#    Updated: 2024/11/19 15:39:53 by mairivie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = ft_isalnum.c ft_isalpha.c ft_isdigit.c ft_isprint.c ft_isascii.c \
	  ft_bzero.c ft_memcpy.c ft_memmove.c ft_memset.c ft_memchr.c ft_memcmp.c\
	  ft_strlcat.c ft_strlcpy.c \
	  ft_strlen.c ft_strncmp.c ft_strchr.c ft_strrchr.c ft_strnstr.c \
	  ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	  ft_toupper.c ft_tolower.c ft_atoi.c ft_itoa.c \
	  ft_calloc.c ft_strdup.c ft_strjoin.c ft_strtrim.c ft_split.c \
	  ft_substr.c ft_striteri.c ft_strmapi.c\
	  ft_printf.c print_numbers.c print_txt.c \
	  get_next_line_utils.c get_next_line.c \
	  ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
	  ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
	  ft_lstmap.c \
			
OBJ = $(SRC:.c=.o)

BONUS_OBJ = $(BONUS_SRC:.c=.o)

# Regles

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRC)
	gcc -nostartfiles -shared -o libft.so $(OBJ) $(BONUS_OBJ)

bonus: $(BONUS_OBJ) $(OBJ)
	ar rc $(NAME) $(OBJ) $(BONUS_OBJ)

clean: 
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME)

re: clean all

.PHONY: so bonus clean fclean re
