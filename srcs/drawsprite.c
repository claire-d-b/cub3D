/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawsprite.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clde-ber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 11:36:12 by clde-ber          #+#    #+#             */
/*   Updated: 2020/10/03 16:27:40 by clde-ber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_sprite_from_start(t_player *player, int i, int j, int count)
{
	unsigned int	color;
	int				xposition_start;
	int				wall_h;

	color = 0;
	wall_h = (int)((player->sprite[count][6] + player->sprite[count][2]) / 2);
	xposition_start =
	(int)(player->sprite[count][7] - (wall_h - (player->sprite[count][3] -
	player->sprite[count][7])));
	if (j <= wall_h && i <= wall_h && i >= 0 && j >= 0)
		color = set_texture_sprite(player, j * player->ids.xpm_sprite_h /
		wall_h, i * player->ids.xpm_sprite_w / wall_h);
	if (color > 0 && xposition_start + i <= player->sprite[count][12] &&
	xposition_start + i >= player->sprite[count][13]
	&& player->struct_screen.y / 2 - wall_h / 2 + j >= 0 &&
	player->struct_screen.y / 2 - wall_h / 2 + j < player->struct_screen.y)
		change_color(player, player->struct_screen.y / 2 - wall_h / 2 + j,
		xposition_start + i, color);
}

void	draw_sprite_from_end(t_player *player, int i, int j, int count)
{
	unsigned int	color;
	int				xposition_end;
	int				wall_h;

	color = 0;
	wall_h = (int)((player->sprite[count][6] + player->sprite[count][2]) / 2);
	xposition_end =
	(int)(player->sprite[count][3] + (wall_h - (player->sprite[count][3] -
	player->sprite[count][7])));
	if (j <= wall_h && i <= wall_h && i >= 0 && j >= 0)
		color = set_texture_sprite(player, j * player->ids.xpm_sprite_h /
		wall_h, i * player->ids.xpm_sprite_w / wall_h);
	if (color > 0 && xposition_end - i <= player->sprite[count][12] &&
	xposition_end - i >= player->sprite[count][13]
	&& player->struct_screen.y / 2 - wall_h / 2 + j >= 0 &&
	player->struct_screen.y / 2 - wall_h / 2 + j < player->struct_screen.y)
		change_color(player, player->struct_screen.y / 2 - wall_h / 2 + j,
		xposition_end - i, color);
}

void	draw_sprite(t_player *player, int i, int j, int count)
{
	if (((player->sprite[count][10] - player->sprite[count][9] >= 0
	|| player->sprite[count][7] == 0) && player->sprite[count][3] !=
	player->struct_screen.x - 1))
		draw_sprite_from_start(player, i, j, count);
	else
		draw_sprite_from_end(player, i, j, count);
}

void	pivot_textures_sprite(int i, int j, t_player *player)
{
	int count;

	count = 0;
	sort_sprite(player);
	while (player->sprite[count] && (int)player->sprite[count][0] != 0)
	{
		while (++i < (int)(((player->sprite[count][2] +
			player->sprite[count][6]) / 2)))
		{
			while (++j < (int)(((player->sprite[count][2] +
			player->sprite[count][6]) / 2)))
				draw_sprite(player, i, j, count);
			j = -1;
		}
		i = -1;
		j = -1;
		count++;
	}
}
