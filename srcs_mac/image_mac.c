/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clde-ber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 11:36:34 by clde-ber          #+#    #+#             */
/*   Updated: 2020/08/28 10:00:13 by clde-ber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_mac.h"

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

void	pivot_textures_ew(unsigned int col, int wall_h, t_player *player)
{
	if (player->struct_side.east == 1)
	{
		if (((int)(((player->struct_screen.j * player->struct_screen.x * 4)
		+ (player->struct_screen.i * 4) + 3))) <= (player->struct_screen.x *
		player->struct_screen.y * 4) && (int)(((player->struct_screen.j *
		player->struct_screen.x * 4) + (player->struct_screen.i * 4))) >= 0)
			col = set_texture_east(player, wall_h);
	}
	if (player->struct_side.west == 1)
	{
		if (((int)(((player->struct_screen.j * player->struct_screen.x * 4)
		+ (player->struct_screen.i * 4) + 3))) <= (player->struct_screen.x *
		player->struct_screen.y * 4) && (int)(((player->struct_screen.j *
		player->struct_screen.x * 4) + (player->struct_screen.i * 4))) >= 0)
			col = set_texture_west(player, wall_h);
	}
	change_color(player, player->struct_screen.j, player->struct_screen.i, col);
}

void	pivot_textures_ns(unsigned int col, int wall_h, t_player *player)
{
	if (player->struct_side.south == 1)
	{
		if (((int)(((player->struct_screen.j * player->struct_screen.x * 4)
		+ (player->struct_screen.i * 4) + 3))) <= (player->struct_screen.x *
		player->struct_screen.y * 4) && (int)(((player->struct_screen.j *
		player->struct_screen.x * 4) + (player->struct_screen.i * 4))) >= 0)
			col = set_texture_south(player, wall_h);
	}
	if (player->struct_side.north == 1)
	{
		if (((int)(((player->struct_screen.j * player->struct_screen.x * 4)
		+ (player->struct_screen.i * 4) + 3))) <= (player->struct_screen.x *
		player->struct_screen.y * 4) && (int)(((player->struct_screen.j *
		player->struct_screen.x * 4) + (player->struct_screen.i * 4))) >= 0)
			col = set_texture_north(player, wall_h);
	}
	change_color(player, player->struct_screen.j, player->struct_screen.i, col);
}
