# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clde-ber <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/14 11:48:01 by clde-ber          #+#    #+#              #
#    Updated: 2020/08/18 11:38:02 by clde-ber         ###   ########.fr        #
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
		moveud.c\
		moverl.c\
		camera.c\
		utils.c\
		split.c\
		parsefile.c\
		utilsview.c\
		utilsmem.c\
		initvar.c\
		utilsraycast.c\
		image.c\
		drawsprite.c

RENAME = mv a.out Cub3D
IMAGE =	--save
BITMAP = image.bmp
OBJ		= $(SRCS:.c=.o)
NAME		= Cub3D
CC		= gcc
RUN_SRC			= -c
RUN_O			= -o
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
