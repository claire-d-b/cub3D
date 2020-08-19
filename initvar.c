/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initvar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clde-ber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 11:37:01 by clde-ber          #+#    #+#             */
/*   Updated: 2020/08/18 14:59:45 by clde-ber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_struct_side(t_player *player)
{
	player->struct_side.north = 0;
	player->struct_side.south = 0;
	player->struct_side.east = 0;
	player->struct_side.west = 0;
}

void	init_pixels(t_player *player, double *wall)
{
	player->struct_screen.i = -1;
	player->struct_screen.j = 0;
	*wall = 0;
}

void	init_var_raycast(char *p, float *d, t_player *player, int *i)
{
	*p = '0';
	player->ray_x = (player->x / CELL_SIZE) - 1;
	player->ray_y = (player->y / CELL_SIZE) - 1;
	*d = 0;
	*i = 0;
}

void	init_sprite(t_player *player)
{
	int i;
	int j;

	i = 0;
	j = 0;
	player->nb_sprites = 0;
	while (player->sprite[i])
	{
		while (j < 11)
		{
			player->sprite[i][j] = 0;
			j++;
		}
		j = 0;
		i++;
	}
}
