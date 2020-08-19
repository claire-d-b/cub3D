/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawsprite.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clde-ber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 11:36:12 by clde-ber          #+#    #+#             */
/*   Updated: 2020/08/18 14:17:04 by clde-ber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	register_sprite_start(int i, t_player *player, float angle, float d)
{
	player->sprite[i][4] = player->ray_x + d * sin(angle);
	player->sprite[i][5] = player->ray_y + d * cos(angle);
	player->sprite[i][7] = player->struct_screen.i;
	player->sprite[i][8] = player->distance;
	player->nb_sprites++;
}

void	register_sprite_end(int i, t_player *player, float angle, float d)
{
	player->sprite[i][0] = player->ray_x + d * sin(angle);
	player->sprite[i][1] = player->ray_y + d * cos(angle);
	player->sprite[i][3] = player->struct_screen.i;
}

void	draw_sprite_from_end(t_player *player, int i, int j, int count)
{
	unsigned int	color;
	int				xposition_end;
	int				wall_h;

	wall_h = (int)((player->sprite[count][2]));
	xposition_end = (int)player->sprite[count][3];
	color = set_texture_sprite(player, (int)(j * 64 / wall_h),
	(int)(i * 64 / wall_h));
	if ((color > 10000000 && xposition_end - i >= 0 && xposition_end - i
	< player->struct_screen.x && player->struct_screen.y / 2 - wall_h / 2 + j
	>= 0 && player->struct_screen.y / 2 - wall_h / 2 + j <
	player->struct_screen.y))
		change_color(player, player->struct_screen.y / 2 - wall_h / 2 + j,
		xposition_end - i, 0xffffff);
}

void	draw_sprite_from_start(t_player *player, int i, int j, int count)
{
	unsigned int	color;
	int				xposition_start;
	int				wall_h;

	wall_h = (int)((player->sprite[count][2]));
	xposition_start = (int)player->sprite[count][7];
	color = set_texture_sprite(player, (int)(j * 64 / wall_h),
	(int)(i * 64 / wall_h));
	if ((color > 10000000 && xposition_start + i >= 0 && xposition_start + i
	< player->struct_screen.x && player->struct_screen.y / 2 - wall_h / 2 + j
	>= 0 && player->struct_screen.y / 2 - wall_h / 2 + j <
	player->struct_screen.y))
		change_color(player, player->struct_screen.y / 2 - wall_h / 2 + j,
		xposition_start + i, 0xffffff);
}

void	pivot_textures_sprite(int i, int j, t_player *player)
{
	int count;

	count = 0;
	while (player->sprite[count] && (int)player->sprite[count][0] != 0)
	{
		while (i <= (int)player->sprite[count][3] -
		(int)player->sprite[count][7])
		{
			while (j < (int)((player->sprite[count][2] +
			player->sprite[count][6]) / 2))
			{
				if ((player->sprite[count][8] < player->sprite[count][9])
				&& player->sprite[count][7] != 0)
					draw_sprite_from_start(player, i, j, count);
				else
					draw_sprite_from_end(player, i, j, count);
				j++;
			}
			j = 0;
			i++;
		}
		i = 0;
		j = 0;
		count++;
	}
}
