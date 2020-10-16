# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clde-ber <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/14 11:48:01 by clde-ber          #+#    #+#              #
#    Updated: 2020/10/14 14:59:54 by clde-ber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= ./srcs/main.c\
		./srcs/gnl.c\
		./srcs/gnlutils.c\
		./srcs/window.c\
		./srcs/map.c\
		./srcs/raymarch.c\
		./srcs/texture.c\
		./srcs/move.c\
		./srcs/playermove.c\
		./srcs/camera.c\
		./srcs/utils.c\
		./srcs/split.c\
		./srcs/parsefile.c\
		./srcs/fileutils.c\
		./srcs/fileutils_2.c\
		./srcs/utilsview.c\
		./srcs/utilsmem.c\
		./srcs/utilsparsing.c\
		./srcs/initvar.c\
		./srcs/utilsraymarch.c\
		./srcs/image.c\
		./srcs/utilssprite.c\
		./srcs/drawsprite.c\
		./srcs/xpm_data.c\
		./srcs/bmp.c\
		./srcs/placeplayer.c\
		./srcs/init_struct.c\
		./srcs/init_struct_2.c\
		./srcs/utilstextures.c\
		./srcs/utilstextures_2.c\
		./srcs/args_error.c\
		./srcs/utilssprite_2.c\
		./srcs/utilsraymarch_2.c\
		./srcs/map_2.c\

SRCS_MAC	= ./srcs_mac/main_mac.c\
		./srcs_mac/gnl_mac.c\
		./srcs_mac/gnlutils_mac.c\
		./srcs_mac/window_mac.c\
		./srcs_mac/map_mac.c\
		./srcs_mac/raymarch_mac.c\
		./srcs_mac/texture_mac.c\
		./srcs_mac/move_mac.c\
		./srcs_mac/playermove_mac.c\
		./srcs_mac/camera_mac.c\
		./srcs_mac/utils_mac.c\
		./srcs_mac/split_mac.c\
		./srcs_mac/parsefile_mac.c\
		./srcs_mac/fileutils_mac.c\
		./srcs_mac/fileutils_2_mac.c\
		./srcs_mac/utilsview_mac.c\
		./srcs_mac/utilsmem_mac.c\
		./srcs_mac/utilsparsing_mac.c\
		./srcs_mac/initvar_mac.c\
		./srcs_mac/utilsraymarch_mac.c\
		./srcs_mac/image_mac.c\
		./srcs_mac/utilssprite_mac.c\
		./srcs_mac/drawsprite_mac.c\
		./srcs_mac/xpm_data_mac.c\
		./srcs_mac/bmp_mac.c\
		./srcs_mac/placeplayer_mac.c\
		./srcs_mac/init_struct_mac.c\
		./srcs_mac/init_struct_2_mac.c\
		./srcs_mac/utilstextures_mac.c\
		./srcs_mac/utilstextures_2_mac.c\
		./srcs_mac/args_error_mac.c\
		./srcs_mac/utilssprite_2_mac.c\
		./srcs_mac/utilsraymarch_2_mac.c\
		./srcs_mac/map_2_mac.c\

RENAME		= mv a.out Cub3D
OBJ			= $(SRCS:.c=.o)
OBJ_MAC		= $(SRCS_MAC:.c=.o)
NAME		= Cub3D
NAME_MAC	= Cub3D
BITMAP		= image.bmp
FS		= a.out.dSYM Cub3D.dSYM valgrind_log
CC			= gcc
INCL		= -L. ./srcs/minilibx/libmlx.a -lXext -lX11 -lm -lbsd
INCL_MAC	= -I ./srcs_mac/minilibx_opengl_20191021 -L ./srcs_mac/minilibx_opengl_20191021 -l mlx -framework OpenGL -framework Appkit
RM			= rm -f
RM_DIR		= rm -rf
CFLAGS		= -Wall -Wextra -Werror -g3 -fsanitize=address
$(NAME):		$(OBJ)
				@$(CC) $(CFLAGS) $(SRCS) $(INCL)
				@$(RENAME)
NAME_MAC:		$(OBJ_MAC)
				@$(CC) $(CFLAGS) $(SRCS_MAC) $(INCL_MAC)
				@$(RENAME)
all:			$(NAME)
mac:			$(OBJ_MAC)
				@$(CC) $(CFLAGS) $(SRCS_MAC) $(INCL_MAC)
				@$(RENAME)
clean:
				@$(RM) $(OBJ)
clean_mac:		
				@$(RM) $(OBJ_MAC) 
fclean:			clean
				@$(RM) $(NAME) $(BITMAP) 
				@$(RM_DIR) $(FS)
re:				fclean all
fclean_mac:		clean_mac
				@$(RM) $(NAME_MAC) $(BITMAP)
				@$(RM_DIR) $(FS)
re_mac:			$(OBJ_MAC)
				@$(RM) $(NAME_MAC) $(BITMAP)
				@$(CC) $(CFLAGS) $(SRCS_MAC) $(INCL_MAC)
				@$(RENAME)		
.PHONY:			all clean fclean re
