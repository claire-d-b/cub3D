/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clde-ber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 11:36:34 by clde-ber          #+#    #+#             */
/*   Updated: 2020/08/18 15:10:53 by clde-ber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	pivot_colors_c(t_player *player)
{
	change_color(player, player->struct_screen.j, player->struct_screen.i,
	player->ceil_color[3]);
	player->struct_screen.j++;
}

void	pivot_colors_f(t_player *player)
{
	change_color(player, player->struct_screen.j, player->struct_screen.i,
	player->floor_color[3]);
	player->struct_screen.j++;
}

void	pivot_textures_ns(t_player *player, float dist)
{
	unsigned int	col;
	int				wall_h;

	wall_h = (int)((player->struct_screen.x) / dist);
	col = 0;
	player->rx = (int)((get_decimals(player->struct_side.wi) * 64) / 100);
	player->ry = (int)(((player->struct_screen.j - player->struct_screen.y
	/ 2 + wall_h / 2) * 64) / wall_h);
	if (player->struct_side.south == 1)
	{
		if (((int)(((player->struct_screen.j * player->struct_screen.x * 4)
		+ (player->struct_screen.i * 4) + 3))) <= (player->struct_screen.x *
		player->struct_screen.y * 4) && (int)(((player->struct_screen.j *
		player->struct_screen.x * 4) + (player->struct_screen.i * 4))) >= 0)
			col = set_texture_south(player, player->ry, player->rx);
	}
	if (player->struct_side.north == 1)
	{
		if (((int)(((player->struct_screen.j * player->struct_screen.x * 4)
		+ (player->struct_screen.i * 4) + 3))) <= (player->struct_screen.x *
		player->struct_screen.y * 4) && (int)(((player->struct_screen.j *
		player->struct_screen.x * 4) + (player->struct_screen.i * 4))) >= 0)
			col = set_texture_north(player, player->ry, player->rx);
	}
	change_color(player, player->struct_screen.j, player->struct_screen.i, col);
}

void	pivot_textures_ew(t_player *player, float dist)
{
	unsigned int	col;
	int				wall_h;

	wall_h = (int)((player->struct_screen.x) / dist);
	col = 0;
	player->rx = (int)((get_decimals(player->struct_side.he) * 64) / 100);
	player->ry = (int)(((player->struct_screen.j - player->struct_screen.y
	/ 2 + wall_h / 2) * 64) / wall_h);
	if (player->struct_side.east == 1)
	{
		if (((int)(((player->struct_screen.j * player->struct_screen.x * 4)
		+ (player->struct_screen.i * 4) + 3))) <= (player->struct_screen.x *
		player->struct_screen.y * 4) && (int)(((player->struct_screen.j *
		player->struct_screen.x * 4) + (player->struct_screen.i * 4))) >= 0)
			col = set_texture_east(player, player->ry, player->rx);
	}
	if (player->struct_side.west == 1)
	{
		if (((int)(((player->struct_screen.j * player->struct_screen.x * 4)
		+ (player->struct_screen.i * 4) + 3))) <= (player->struct_screen.x *
		player->struct_screen.y * 4) && (int)(((player->struct_screen.j *
		player->struct_screen.x * 4) + (player->struct_screen.i * 4))) >= 0)
			col = set_texture_west(player, player->ry, player->rx);
	}
	change_color(player, player->struct_screen.j, player->struct_screen.i, col);
}
