# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/18 21:24:52 by bkabbas           #+#    #+#              #
#    Updated: 2016/01/25 13:12:04 by bkabbas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libr3d.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
PLATFORM = El_capitan

PATH_HEADERS = -I includes/
PATH_R3D = ./
PATH_M4F = $(PATH_R3D)m4f/
PATH_V4F = $(PATH_R3D)v4f/
PATH_V3F = $(PATH_R3D)v3f/
PATH_V2F = $(PATH_R3D)v2f/
PATH_QUAT = $(PATH_R3D)quat/
PATH_INPUT = $(PATH_R3D)input/
PATH_TRANSFORM = $(PATH_R3D)transform/
PATH_MESH = $(PATH_R3D)mesh/
PATH_LOADERS = $(PATH_R3D)loaders/
PATH_CORECOMPONENT = $(PATH_R3D)core_components/
PATH_RENDERING = $(PATH_R3D)rendering/
PATH_LINUX = linux/
PATH_ELCAPITAN = el_capitan/
PATH_KEYCODES = $(PATH_INPUT)
ifeq ($(PLATFORM), Linux)
	PATH_KEYCODES = $(PATH_INPUT)$(PATH_LINUX)
else
	PATH_KEYCODES = $(PATH_INPUT)$(PATH_ELCAPITAN)
endif
SRC_M4F = $(PATH_M4F)m4f_manipulations.c $(PATH_M4F)m4f_operators.c $(PATH_M4F)m4f_adjugate.c $(PATH_M4F)m4f_initializers.c
SRC_V4F = $(PATH_V4F)v4f_manipulations.c $(PATH_V4F)v4f_operators.c $(PATH_V4F)v4f_operators_new.c $(PATH_V4F)v4f_utils.c
SRC_V3F = $(PATH_V3F)v3f_manipulations.c $(PATH_V3F)v3f_operators.c $(PATH_V3F)v3f_operators_new.c $(PATH_V3F)v3f_utils.c
SRC_V2F = $(PATH_V2F)v2f_manipulations.c $(PATH_V2F)v2f_operators.c $(PATH_V2F)v2f_operators_new.c $(PATH_V2F)v2f_utils.c
SRC_QUAT = $(PATH_QUAT)quat_manipulations.c $(PATH_QUAT)quat_operators_new.c
SRC_MESH = $(PATH_MESH)mesh_draw.c $(PATH_MESH)mesh_inits.c
SRC_LOADERS = $(PATH_LOADERS)loader.c $(PATH_LOADERS)obj_loader.c $(PATH_LOADERS)obj_model.c $(PATH_LOADERS)rs_loader.c $(PATH_LOADERS)ro_loader.c $(PATH_LOADERS)bmp_loader.c
SRC_TRANSFORM = $(PATH_TRANSFORM)trs_manipulations.c $(PATH_TRANSFORM)trs_operators_pos.c $(PATH_TRANSFORM)trs_operators_rot.c $(PATH_TRANSFORM)trs_operators_scale.c
SRC_CORECOMPONENT = $(PATH_CORECOMPONENT)core.c $(PATH_CORECOMPONENT)window.c $(PATH_CORECOMPONENT)internal_behavior.c $(PATH_CORECOMPONENT)error.c
SRC_RENDERING = $(PATH_RENDERING)renderer.c $(PATH_RENDERING)pixel_handler.c $(PATH_RENDERING)interpolant.c $(PATH_RENDERING)line.c $(PATH_RENDERING)line_drawing.c
SRC_OTHER = $(PATH_R3D)texture.c $(PATH_R3D)material.c $(PATH_R3D)vertex.c $(PATH_R3D)object.c $(PATH_R3D)camera.c
SRC_INPUT = $(PATH_INPUT)focus_handler.c $(PATH_INPUT)key_down.c $(PATH_INPUT)key_up.c $(PATH_INPUT)mouse_down.c $(PATH_INPUT)mouse_up.c $(PATH_INPUT)mouse_pos.c
SRC_KEYCODES = $(PATH_KEYCODES)mlx_to_r3d.c $(PATH_KEYCODES)mlx_to_r3d_keypad.c $(PATH_KEYCODES)mlx_to_r3d_alphabet.c $(PATH_KEYCODES)mlx_to_r3d_special.c
OBJ_M4F = $(SRC_M4F:.c=.o)
OBJ_V4F = $(SRC_V4F:.c=.o)
OBJ_V3F = $(SRC_V3F:.c=.o)
OBJ_V2F = $(SRC_V2F:.c=.o)
OBJ_QUAT = $(SRC_QUAT:.c=.o)
OBJ_MESH = $(SRC_MESH:.c=.o)
OBJ_INPUT = $(SRC_INPUT:.c=.o)
OBJ_KEYCODES = $(SRC_KEYCODES:.c=.o)
OBJ_OTHER = $(SRC_OTHER:.c=.o)
OBJ_LOADERS = $(SRC_LOADERS:.c=.o)
OBJ_TRANSFORM = $(SRC_TRANSFORM:.c=.o)
OBJ_RENDERING = $(SRC_RENDERING:.c=.o)
OBJ_CORECOMPONENT = $(SRC_CORECOMPONENT:.c=.o)
OBJ =	$(OBJ_M4F)
OBJ +=	$(OBJ_V4F)
OBJ +=	$(OBJ_V3F)
OBJ +=	$(OBJ_V2F)
OBJ +=	$(OBJ_QUAT)
OBJ +=	$(OBJ_MESH)
OBJ +=	$(OBJ_OTHER)
OBJ +=	$(OBJ_INPUT)
OBJ +=	$(OBJ_LOADERS)
OBJ +=	$(OBJ_KEYCODES)
OBJ +=	$(OBJ_TRANSFORM)
OBJ +=	$(OBJ_RENDERING)
OBJ +=	$(OBJ_CORECOMPONENT)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo library correctly linked

%.o: %.c
	$(CC) $(CFLAGS) $(PATH_HEADERS) -o $@ -c $<

clean:
	@rm -f $(OBJ)
	@echo removed binary files

fclean: clean
	@rm -f $(NAME)
	@echo removed library

re: fclean all

.PHONY: all clean fclean re
