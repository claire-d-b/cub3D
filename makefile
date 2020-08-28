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
		utilsnb.c\
		initvar.c\
		utilsraymarch.c\
		image.c\
		utilssprite.c\
		drawsprite.c\
		xpm_data.c\
		bmp.c\
		placeplayer.c\

RENAME = mv a.out Cub3D
OBJ		= $(SRCS:.c=.o)
NAME		= Cub3D
BITMAP		= image.bmp
CC		= gcc
INCL		= -L. minilibx/libmlx.a -lXext -lX11 -lm -lbsd
RM		= rm -f
CFLAGS		= -g3 -fsanitize=address -O3 -Wall -Wextra -Werror
$(NAME):	$(OBJ)
			@$(CC) $(CFLAGS) $(SRCS) $(INCL)
			@$(RENAME)
all:		$(NAME)
bitmap:		$(OBJ)
			@$(CC) $(CFLAGS) $(SRCS) $(INCL)
			@$(RENAME)
clean:
		@$(RM) $(OBJ)
fclean:		clean
		@$(RM) $(NAME) $(BITMAP)
re:		fclean all
.PHONY:		all clean fclean re
