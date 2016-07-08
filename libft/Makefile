# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/18 21:24:52 by bkabbas           #+#    #+#              #
#    Updated: 2016/01/18 23:32:51 by bkabbas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
PATH_HEADERS = -I includes/
PATH_SRC = src/

SRC_FT = $(PATH_SRC)ft_isupper.c \
		$(PATH_SRC)ft_memjoin.c \
		$(PATH_SRC)ft_strclr.c \
		$(PATH_SRC)ft_strnew.c \
		$(PATH_SRC)ft_itoa.c \
		$(PATH_SRC)ft_memmove.c \
		$(PATH_SRC)ft_strcmp.c \
		$(PATH_SRC)ft_strnstr.c \
		$(PATH_SRC)ft_abs.c \
		$(PATH_SRC)ft_lstadd.c \
		$(PATH_SRC)ft_memset.c \
		$(PATH_SRC)ft_strcpy.c \
		$(PATH_SRC)ft_strrchr.c \
		$(PATH_SRC)ft_atoi.c \
		$(PATH_SRC)ft_lstcount.c \
		$(PATH_SRC)ft_memswap.c \
		$(PATH_SRC)ft_strdel.c \
		$(PATH_SRC)ft_strrev.c \
		$(PATH_SRC)ft_bzero.c \
		$(PATH_SRC)ft_lstdel.c \
		$(PATH_SRC)ft_min.c \
		$(PATH_SRC)ft_strdup.c \
		$(PATH_SRC)ft_strsplit.c \
		$(PATH_SRC)ft_clamp.c \
		$(PATH_SRC)ft_lstdelone.c \
		$(PATH_SRC)ft_pi.c \
		$(PATH_SRC)ft_strequ.c \
		$(PATH_SRC)ft_strstr.c \
		$(PATH_SRC)ft_clampf.c \
		$(PATH_SRC)ft_lstfindbyindex.c \
		$(PATH_SRC)ft_pushback_array.c \
		$(PATH_SRC)ft_striter.c \
		$(PATH_SRC)ft_strsub.c \
		$(PATH_SRC)ft_clampf01.c \
		$(PATH_SRC)ft_lstfindbyvalue.c \
		$(PATH_SRC)ft_putchar.c \
		$(PATH_SRC)ft_striteri.c \
		$(PATH_SRC)ft_strtolower.c \
		$(PATH_SRC)ft_create_array.c \
		$(PATH_SRC)ft_lstiter.c \
		$(PATH_SRC)ft_putchar_fd.c \
		$(PATH_SRC)ft_strjoin.c \
		$(PATH_SRC)ft_strtoupper.c \
		$(PATH_SRC)ft_getnextxarraychar.c \
		$(PATH_SRC)ft_lstmap.c \
		$(PATH_SRC)ft_putendl.c \
		$(PATH_SRC)ft_strlcat.c \
		$(PATH_SRC)ft_strtrim.c \
		$(PATH_SRC)ft_getnextxchar.c \
		$(PATH_SRC)ft_lstnew.c \
		$(PATH_SRC)ft_putendl_fd.c \
		$(PATH_SRC)ft_strlcpy.c \
		$(PATH_SRC)ft_strtrimarraychar.c \
		$(PATH_SRC)ft_isalnum.c \
		$(PATH_SRC)ft_max.c \
		$(PATH_SRC)ft_putnbr.c \
		$(PATH_SRC)ft_strlen.c \
		$(PATH_SRC)ft_strtrimchar.c \
		$(PATH_SRC)ft_isalpha.c \
		$(PATH_SRC)ft_memalloc.c \
		$(PATH_SRC)ft_putnbr_fd.c \
		$(PATH_SRC)ft_strmap.c \
		$(PATH_SRC)ft_strtrimlchar.c \
		$(PATH_SRC)ft_isascii.c \
		$(PATH_SRC)ft_memccpy.c \
		$(PATH_SRC)ft_putstr.c \
		$(PATH_SRC)ft_strmapi.c \
		$(PATH_SRC)ft_strtrimrchar.c \
		$(PATH_SRC)ft_isdigit.c \
		$(PATH_SRC)ft_memchr.c \
		$(PATH_SRC)ft_putstr_fd.c \
		$(PATH_SRC)ft_strncat.c \
		$(PATH_SRC)ft_tolower.c \
		$(PATH_SRC)ft_islower.c \
		$(PATH_SRC)ft_memcmp.c \
		$(PATH_SRC)ft_strcat.c \
		$(PATH_SRC)ft_strncmp.c \
		$(PATH_SRC)ft_toupper.c \
		$(PATH_SRC)ft_isprint.c \
		$(PATH_SRC)ft_memcpy.c \
		$(PATH_SRC)ft_strchr.c \
		$(PATH_SRC)ft_strncpy.c \
		$(PATH_SRC)ft_isspace.c \
		$(PATH_SRC)ft_memdel.c \
		$(PATH_SRC)ft_strchr_count.c \
		$(PATH_SRC)ft_strnequ.c \
		$(PATH_SRC)ft_pushfront_array.c \
		$(PATH_SRC)ft_strchrnul.c \
		$(PATH_SRC)ft_delete_array.c \
		$(PATH_SRC)ft_del_at_array.c \
		$(PATH_SRC)ft_delrange_at_array.c \
		$(PATH_SRC)ft_strnchr.c \
		$(PATH_SRC)ft_create_tab.c \
		$(PATH_SRC)ft_lst_get_end.c \
		$(PATH_SRC)ft_lst_to_t_array.c \
		$(PATH_SRC)ft_lst_to_array.c \
		$(PATH_SRC)get_next_line.c

OBJ_FT = $(SRC_FT:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_FT)
	@ar rc $(NAME) $(OBJ_FT)
	@ranlib $(NAME)
	@echo library linked correctly

%.o: %.c
	$(CC) $(CFLAGS) $(PATH_HEADERS) -o $@ -c $<

clean:
	@rm -f $(OBJ_FT)
	@echo removed binary files

fclean: clean
	@rm -f $(NAME)
	@echo removed library

re: fclean all

.PHONY: all clean fclean re
