# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clde-ber <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/14 11:48:01 by clde-ber          #+#    #+#              #
#    Updated: 2020/08/20 15:08:45 by clde-ber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= main.c\
		gnl.c\
		gnlutils.c\
		window.c\
		map.c\
		raycast.c\
		texture.c\
		move.c\
		moveu.c\
		moved.c\
		mover.c\
		movel.c\
		camera.c\
		utils.c\
		split.c\
		parsefile.c\
		fileutils.c\
		utilsview.c\
		utilsmem.c\
		utilsnb.c\
		initvar.c\
		utilsraycast.c\
		image.c\
		utilssprite.c\
		drawsprite.c\
		xpm_data.c\

RENAME = mv a.out Cub3D
IMAGE =	--save
BITMAP = image.bmp
OBJ		= $(SRCS:.c=.o)
NAME		= Cub3D
CC		= gcc
INCL		= -I minilibx_opengl_20191021 -L minilibx_opengl_20191021 -l mlx -framework OpenGL -framework AppKit
RM		= rm -f
CFLAGS		= -g3 -fsanitize=address -Wall -Wextra -Werror
$(NAME):	$(OBJ)
			@$(CC) $(CFLAGS) $(SRCS) $(INCL)
			@$(RENAME)
			@./$(NAME)
all:		$(NAME)
bitmap:		$(OBJ)
			@$(CC) $(CFLAGS) $(SRCS) $(INCL)
			@$(RENAME)
clean:
		@$(RM) $(OBJ)
fclean:		clean
		@$(RM) $(NAME) $(BITMAP)
re:		fclean all
bmp:	fclean bitmap
		@./$(NAME) $(IMAGE)
.PHONY:		all clean fclean re
