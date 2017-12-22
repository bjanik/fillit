# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bjanik <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/12 10:30:25 by bjanik            #+#    #+#              #
#    Updated: 2017/12/22 13:44:13 by bjanik           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CC = gcc
CFLAGS = -Wall -Wextra -Werror

LIBFT  = libft
LIBFT_INC  = libft/includes
LIB = libft/libft.a

HEADER = includes

SRC_PATH = srcs
OBJ_PATH = obj

SRC_NAME = backtracking.c \
	   fillit.c \
	   main.c \
	   map.c \
	   other_functions.c \
	   parsing.c \
	   tetros.c \

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all : $(NAME)

$(NAME) : $(OBJ)
	make -C $(LIBFT)
	$(CC) $(FLAGS) $(OBJ) $(LIB) -o $(NAME)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir -p $(OBJ_PATH) 2> /dev/null
	$(CC) $(CFLAGS) -I$(HEADER) -I$(LIBFT_INC) -c $< -o $@

clean :
	rm -rf $(OBJ_PATH)
	make clean -C $(LIBFT)

fclean : clean
	make fclean -C $(LIBFT)
	rm -f $(NAME)

re : fclean all
