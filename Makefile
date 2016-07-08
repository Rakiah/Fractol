# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/18 21:30:01 by bkabbas           #+#    #+#              #
#    Updated: 2016/01/25 16:07:58 by bkabbas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
PATH_SRC = src/
PATH_HEADERS = -I minilibx/ -I includes/ -I libft/includes/ -I rakiah3d/includes/
SRC = $(PATH_SRC)main.c \
	  $(PATH_SRC)init.c \
	  $(PATH_SRC)fractals.c \
	  $(PATH_SRC)fractals_2.c \
	  $(PATH_SRC)fractals_3.c \
	  $(PATH_SRC)fractals_4.c \
	  $(PATH_SRC)fractals_5.c \
	  $(PATH_SRC)events.c \
	  $(PATH_SRC)color.c \
	  $(PATH_SRC)events_2.c
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
CLIBS_PATH = -L rakiah3d/ -L libft/
CLIBS = -lr3d \
	-lft \
	-lm \
	-lmlx \
	-framework OpenGL \
	-framework AppKit
	#-lXext \
	#-lX11
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C rakiah3d/
	make -C libft/
	make -C minilibx/
	$(CC) $(CFLAGS) $(CLIBS_PATH) -o $(NAME) $(OBJ) $(CLIBS)

%.o: %.c
	$(CC) $(CFLAGS) $(PATH_HEADERS) -o $@ -c $<

nolib: $(NAME)
	$(CC) $(CFLAGS) $(CLIBS_PATH) -o $(NAME) $(OBJ) $(CLIBS)

clean:
	rm -f $(OBJ)
	make -C libft/ clean
	make -C rakiah3d/ clean

fclean: clean
	rm -f $(NAME)
	make -C libft/ fclean
	make -C rakiah3d/ fclean
	make -C minilibx/ clean

re: fclean all

.PHONY: all clean fclean re nolib
