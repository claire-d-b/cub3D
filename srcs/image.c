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

void	pivot_textures_ns(unsigned int col, int wall_h, t_player *player)
{
	if (player->struct_side.south == 1)
	{
		player->rx = (int)((get_decimals(player->struct_side.wi) *
		player->ids.xpm_img_w) / 100);
		player->ry = (int)(((player->struct_screen.j - player->struct_screen.y
		/ 2 + wall_h / 2) * player->ids.xpm_img_h) / wall_h);
		if (((int)(((player->struct_screen.j * player->struct_screen.x * 4)
		+ (player->struct_screen.i * 4) + 3))) <= (player->struct_screen.x *
		player->struct_screen.y * 4) && (int)(((player->struct_screen.j *
		player->struct_screen.x * 4) + (player->struct_screen.i * 4))) >= 0)
			col = set_texture_south(player, player->ry, player->rx);
	}
	if (player->struct_side.north == 1)
	{
		player->rx = (int)((get_decimals(player->struct_side.wi) *
		player->ids.xpm_img2_w) / 100);
		player->ry = (int)(((player->struct_screen.j - player->struct_screen.y
		/ 2 + wall_h / 2) * player->ids.xpm_img2_h) / wall_h);
		if (((int)(((player->struct_screen.j * player->struct_screen.x * 4)
		+ (player->struct_screen.i * 4) + 3))) <= (player->struct_screen.x *
		player->struct_screen.y * 4) && (int)(((player->struct_screen.j *
		player->struct_screen.x * 4) + (player->struct_screen.i * 4))) >= 0)
			col = set_texture_north(player, player->ry, player->rx);
	}
	change_color(player, player->struct_screen.j, player->struct_screen.i, col);
}

void	pivot_textures_ew(unsigned int col, int wall_h, t_player *player)
{
	if (player->struct_side.east == 1)
	{
		player->rx = (int)((get_decimals(player->struct_side.he) *
		player->ids.xpm_img3_w) / 100);
		player->ry = (int)(((player->struct_screen.j - player->struct_screen.y
		/ 2 + wall_h / 2) * player->ids.xpm_img3_h) / wall_h);
		if (((int)(((player->struct_screen.j * player->struct_screen.x * 4)
		+ (player->struct_screen.i * 4) + 3))) <= (player->struct_screen.x *
		player->struct_screen.y * 4) && (int)(((player->struct_screen.j *
		player->struct_screen.x * 4) + (player->struct_screen.i * 4))) >= 0)
			col = set_texture_east(player, player->ry, player->rx);
	}
	if (player->struct_side.west == 1)
	{
		player->rx = (int)((get_decimals(player->struct_side.he) *
		player->ids.xpm_img4_w) / 100);
		player->ry = (int)(((player->struct_screen.j - player->struct_screen.y
		/ 2 + wall_h / 2) * player->ids.xpm_img4_h) / wall_h);
		if (((int)(((player->struct_screen.j * player->struct_screen.x * 4)
		+ (player->struct_screen.i * 4) + 3))) <= (player->struct_screen.x *
		player->struct_screen.y * 4) && (int)(((player->struct_screen.j *
		player->struct_screen.x * 4) + (player->struct_screen.i * 4))) >= 0)
			col = set_texture_west(player, player->ry, player->rx);
	}
	change_color(player, player->struct_screen.j, player->struct_screen.i, col);
}
