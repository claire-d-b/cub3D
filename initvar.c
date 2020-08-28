/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initvar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clde-ber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 11:37:01 by clde-ber          #+#    #+#             */
/*   Updated: 2020/08/20 12:07:02 by clde-ber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void init_struct_screen(t_player *player)
{
	player->struct_screen.x = -1;
	player->struct_screen.y = -1;
	player->struct_screen.i = 0;
	player->struct_screen.j = 0;
}

void init_struct_player(t_player *player)
{
	int i;

	i = 0;
	player->key_r = 0;
	player->waste = 0;
	player->xpm_path_no = 0;
	player->xpm_path_so = 0;
	player->xpm_path_we = 0;
	player->xpm_path_ea = 0;
	player->xpm_path_sp = 0;
	while (i < 4)
	{
		player->ceil_color[i] = -1;
		player->floor_color[i] = -1;
		i++;
	}
	player->map_start = 0;
	player->bool_start = 0;
	player->save = 0;
	player->nb_sprites = 0;
	player->sprite = 0;
	player->table_lenght = 0;
	player->max = 0;
	player->start = 0;
	player->p = 0;
	player->distance = 0;
	player->x = 0;
	player->y = 0;
	player->ray_x = 0;
	player->ray_y = 0;
	player->ry = 0;
	player->rx = 0;
	player->teta = 0;
	player->map = 0;
}

void	init_struct_side(t_player *player)
{
	player->struct_side.north = 0;
	player->struct_side.south = 0;
	player->struct_side.east = 0;
	player->struct_side.west = 0;
}

void	init_pixels(t_player *player)
{
	player->struct_screen.i = -1;
	player->struct_screen.j = 0;
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
		while (j < 10)
		{
			player->sprite[i][j] = 0;
			j++;
		}
		j = 0;
		i++;
	}
}

void	init_map_dim(t_player *player)
{
	player->max = 0;
	player->table_lenght = 0;
}
