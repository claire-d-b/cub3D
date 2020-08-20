/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clde-ber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 08:31:43 by clde-ber          #+#    #+#             */
/*   Updated: 2020/08/20 13:03:06 by clde-ber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned int	set_texture_sprite(t_player *player, int y, int i)
{
	unsigned int color;

	if (((int)(((y * CELL_SIZE * 4) + (i * 4) + 3))) <= (CELL_SIZE * CELL_SIZE
	* 4) && (int)(((y * CELL_SIZE * 4) + (i * 4))) >= 0)
	{
		player->struct_side.pixel[0] =
		(unsigned int)player->ids.xpm_data_sprite[(int)((((y * (CELL_SIZE) * 4))
		+ (i * 4)))];
		player->struct_side.pixel[1] =
		(unsigned int)player->ids.xpm_data_sprite[(int)((((y * (CELL_SIZE) * 4))
		+ (i * 4))) + 1];
		player->struct_side.pixel[2] =
		(unsigned int)player->ids.xpm_data_sprite[(int)((((y * (CELL_SIZE) * 4))
		+ (i * 4))) + 2];
		player->struct_side.pixel[3] =
		(unsigned int)player->ids.xpm_data_sprite[(int)((((y * (CELL_SIZE) * 4))
		+ (i * 4))) + 3];
	}
	color = rgb3(player->struct_side.pixel[2], player->struct_side.pixel[1],
	player->struct_side.pixel[0]);
	return (color);
}

unsigned int	set_texture_south(t_player *player, int y, int i)
{
	unsigned int color;

	y = player->ry;
	i = player->rx;
	if (((int)(((player->ry * CELL_SIZE * 4) + (player->rx * 4) + 3))) <=
	(CELL_SIZE * CELL_SIZE * 4) && (int)(((player->ry * CELL_SIZE * 4) +
	(player->rx * 4))) >= 0)
	{
		player->struct_side.pixel[0] =
		(unsigned int)player->ids.xpm_data[(int)((((y * (CELL_SIZE) * 4)) +
		(i * 4)))];
		player->struct_side.pixel[1] =
		(unsigned int)player->ids.xpm_data[(int)((((y * (CELL_SIZE) * 4)) +
		(i * 4))) + 1];
		player->struct_side.pixel[2] =
		(unsigned int)player->ids.xpm_data[(int)((((y * (CELL_SIZE) * 4)) +
		(i * 4))) + 2];
		player->struct_side.pixel[3] =
		(unsigned int)player->ids.xpm_data[(int)((((y * (CELL_SIZE) * 4)) +
		(i * 4))) + 3];
	}
	color = rgb3(player->struct_side.pixel[2], player->struct_side.pixel[1],
	player->struct_side.pixel[0]);
	return (color);
}

unsigned int	set_texture_north(t_player *player, int y, int i)
{
	unsigned int color;

	y = player->ry;
	i = player->rx;
	if (((int)(((player->ry * CELL_SIZE * 4) + (player->rx * 4) + 3))) <=
	(CELL_SIZE * CELL_SIZE * 4) && (int)(((player->ry * CELL_SIZE * 4) +
	(player->rx * 4))) >= 0)
	{
		player->struct_side.pixel[0] =
		(unsigned int)player->ids.xpm_data2[(int)((((y * (CELL_SIZE) * 4)) +
		(i * 4)))];
		player->struct_side.pixel[1] =
		(unsigned int)player->ids.xpm_data2[(int)((((y * (CELL_SIZE) * 4)) +
		(i * 4))) + 1];
		player->struct_side.pixel[2] =
		(unsigned int)player->ids.xpm_data2[(int)((((y * (CELL_SIZE) * 4)) +
		(i * 4))) + 2];
		player->struct_side.pixel[3] =
		(unsigned int)player->ids.xpm_data2[(int)((((y * (CELL_SIZE) * 4)) +
		(i * 4))) + 3];
	}
	color = rgb3(player->struct_side.pixel[2], player->struct_side.pixel[1],
	player->struct_side.pixel[0]);
	return (color);
}

unsigned int	set_texture_east(t_player *player, int y, int i)
{
	unsigned int color;

	y = player->ry;
	i = player->rx;
	if (((int)(((player->ry * CELL_SIZE * 4) + (player->rx * 4) + 3))) <=
	(CELL_SIZE * CELL_SIZE * 4) && (int)(((player->ry * CELL_SIZE * 4) +
	(player->rx * 4))) >= 0)
	{
		player->struct_side.pixel[0] =
		(unsigned int)player->ids.xpm_data3[(int)(((y * (CELL_SIZE) * 4) +
		(i * 4)))];
		player->struct_side.pixel[1] =
		(unsigned int)player->ids.xpm_data3[(int)((((y * (CELL_SIZE) * 4) +
		(i * 4)))) + 1];
		player->struct_side.pixel[2] =
		(unsigned int)player->ids.xpm_data3[(int)((((y * (CELL_SIZE) * 4) +
		(i * 4)))) + 2];
		player->struct_side.pixel[3] =
		(unsigned int)player->ids.xpm_data3[(int)((((y * (CELL_SIZE) * 4) +
		(i * 4)))) + 3];
	}
	color = rgb3(player->struct_side.pixel[2], player->struct_side.pixel[1],
	player->struct_side.pixel[0]);
	return (color);
}

unsigned int	set_texture_west(t_player *player, int y, int i)
{
	unsigned int color;

	y = player->ry;
	i = player->rx;
	if (((int)(((player->ry * CELL_SIZE * 4) + (player->rx * 4) + 3))) <=
	(CELL_SIZE * CELL_SIZE * 4) && (int)(((player->ry * CELL_SIZE * 4) +
	(player->rx * 4))) >= 0)
	{
		player->struct_side.pixel[0] =
		(unsigned int)player->ids.xpm_data4[(y * CELL_SIZE * 4) +
		(i * 4)];
		player->struct_side.pixel[1] =
		(unsigned int)player->ids.xpm_data4[(y * CELL_SIZE * 4) +
		(i * 4) + 1];
		player->struct_side.pixel[2] =
		(unsigned int)player->ids.xpm_data4[(y * CELL_SIZE * 4) +
		(i * 4) + 2];
		player->struct_side.pixel[3] =
		(unsigned int)player->ids.xpm_data4[(y * CELL_SIZE * 4) +
		(i * 4) + 3];
	}
	color = rgb3(player->struct_side.pixel[2], player->struct_side.pixel[1],
	player->struct_side.pixel[0]);
	return (color);
}
