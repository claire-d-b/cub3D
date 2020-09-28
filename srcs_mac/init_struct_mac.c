/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clde-ber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 12:24:36 by clde-ber          #+#    #+#             */
/*   Updated: 2020/09/01 20:23:53 by clde-ber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_mac.h"

void	init_elements(t_player *player)
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
	player->walls = 0;
	while (i < 4)
	{
		player->ceil_color[i] = -1;
		player->floor_color[i] = -1;
		i++;
	}
}

void	init_struct_player(t_player *player)
{
	init_elements(player);
	player->map_start = 0;
	player->bool_start = 0;
	player->save = 0;
	player->nb_sprites = 0;
	player->sprite = 0;
	player->table_lenght = 0;
	player->max = 0;
	player->start = 1;
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
	player->boolean = 0;
	player->dist_wall = 0;
	player->dist_sprite = 0;
}

void	init_elements_exit(t_player *player)
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
	player->walls = 0;
	while (i < 4)
	{
		player->ceil_color[i] = 0;
		player->floor_color[i] = 0;
		i++;
	}
}

void	init_struct_player_exit(t_player *player)
{
	init_elements_exit(player);
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
	player->boolean = 0;
	player->dist_wall = 0;
	player->dist_sprite = 0;
}

void	init_struct_side_s_e(t_player *player)
{
	int i;

	i = 0;
	player->struct_side.west = 0;
	player->struct_side.east = 0;
	player->struct_side.south = 0;
	player->struct_side.north = 0;
	player->struct_side.he = 0;
	player->struct_side.wi = 0;
	while (i < 4)
	{
		player->struct_side.pixel[i] = 0;
		i++;
	}
}
