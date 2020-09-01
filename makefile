# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clde-ber <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/14 11:48:01 by clde-ber          #+#    #+#              #
#    Updated: 2020/08/28 10:34:50 by clde-ber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= main.c\
		gnl.c\
		gnlutils.c\
		window.c\
		map.c\
		raymarch.c\
		texture.c\
		move.c\
		playermove.c\
		camera.c\
		utils.c\
		split.c\
		parsefile.c\
		fileutils.c\
		utilsview.c\
		utilsmem.c\
		utilsparsing.c\
		initvar.c\
		utilsraymarch.c\
		image.c\
		utilssprite.c\
		drawsprite.c\
		xpm_data.c\
		bmp.c\
		placeplayer.c\
		init_struct.c\
		init_struct_2.c\
		utilstextures.c\
		args_error.c\

SRCS_MAC	= main_mac.c\
		gnl_mac.c\
		gnlutils_mac.c\
		window_mac.c\
		map_mac.c\
		raymarch_mac.c\
		texture_mac.c\
		move_mac.c\
		playermove_mac.c\
		camera_mac.c\
		utils_mac.c\
		split_mac.c\
		parsefile_mac.c\
		fileutils_mac.c\
		utilsview_mac.c\
		utilsmem_mac.c\
		utilsparsing_mac.c\
		initvar_mac.c\
		utilsraymarch_mac.c\
		image_mac.c\
		utilssprite_mac.c\
		drawsprite_mac.c\
		xpm_data_mac.c\
		bmp_mac.c\
		placeplayer_mac.c\
		init_struct_mac.c\
		init_struct_2_mac.c\
		utilstextures_mac.c\
		args_error_mac.c\

RENAME = mv a.out Cub3D
OBJ		= $(SRCS:.c=.o)
NAME		= Cub3D
BITMAP		= image.bmp
CC		= gcc
INCL		= -L. minilibx/libmlx.a -lXext -lX11 -lm -lbsd
INCL_MAC	= -I minilibx_opengl_20191021 -L minilibx_opengl_20191021 -l mlx -framework OpenGL -framework Appkit
RM		= rm -f
CFLAGS		= -g3 -fsanitize=address -O3 -Wall -Wextra -Werror
$(NAME):	$(OBJ)
			@$(CC) $(CFLAGS) $(SRCS) $(INCL)
			@$(RENAME)
all:		$(NAME)
mac:		$(OBJ)
			@$(CC) $(CFLAGS) $(SRCS_MAC) $(INCL_MAC)
			@$(RENAME)
			
bitmap:		$(OBJ)
			@$(CC) $(CFLAGS) $(SRCS) $(INCL)
			@$(RENAME)
clean:
		@$(RM) $(OBJ)
fclean:		clean
		@$(RM) $(NAME) $(BITMAP)
re:		fclean all
.PHONY:		all clean fclean re
