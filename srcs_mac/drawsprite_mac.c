/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawsprite.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clde-ber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 11:36:12 by clde-ber          #+#    #+#             */
/*   Updated: 2020/09/11 17:01:16 by clde-ber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_mac.h"

void	register_sprite_start(int i, t_player *player, float angle, float d)
{
	player->sprite[i][4] = player->ray_x + d * sin(angle);
	player->sprite[i][5] = player->ray_y + d * cos(angle);
	player->sprite[i][7] = player->struct_screen.i;
	check_sprite_sides(player, d, angle, i);
	player->nb_sprites++;
}

void	register_sprite_end(int i, t_player *player, float angle, float d)
{
	player->sprite[i][0] = player->ray_x + d * sin(angle);
	player->sprite[i][1] = player->ray_y + d * cos(angle);
	player->sprite[i][3] = player->struct_screen.i;
//	check_sprite_sides(player, d, angle, i);
}
/*
void	draw_sprite_from_end(t_player *player, int i, int j, int count)
{
	unsigned int	color;
	int				xposition_start;
	double			wall_h;
	double			dist2;
	double			ratio;

	wall_h = ((player->sprite[count][2] + player->sprite[count][6]) / 2);
	xposition_start = (int)player->sprite[count][7];
	dist2 = (player->sprite[count][10] == 0 || player->sprite[count][10] == 1) ? 
	get_decimals(player->sprite[count][5]) * wall_h / 100 :
	get_decimals(player->sprite[count][4]) * wall_h / 100;
	ratio = dist2; 
	if (j < wall_h && i < wall_h && i >= 0 && j >= 0)
	{
		color = set_texture_sprite(player, j * player->ids.xpm_sprite_h /
		wall_h, player->ids.xpm_sprite_w - i * player->ids.xpm_sprite_w / wall_h);
		if ((color > 0 && xposition_start - ratio + wall_h - i >= player->sprite[count][7] &&
		xposition_start - ratio + wall_h - i <= player->sprite[count][3]
		&& player->struct_screen.y / 2 - wall_h / 2
		+ j >= 0 && player->struct_screen.y / 2 - wall_h / 2 + j <
		player->struct_screen.y))
			change_color(player, player->struct_screen.y / 2 - wall_h / 2 + j,
			xposition_start - ratio + wall_h - i, color);
	}
}*/

void	draw_sprite_from_start(t_player *player, int i, int j, int count)
{
	unsigned int	color;
	int				xposition_start;
	double			wall_h;
	double			dist2;
	double			ratio;

	color = 0;
	wall_h = ((player->sprite[count][2] + player->sprite[count][6]) / 2);
/*	if (player->sprite[count][10] == 0 || player->sprite[count][10] == 1) 
		dist2 = (player->sprite[count][10] == 0) ? get_decimals(player->sprite[count][5]) * wall_h / 100 :
		wall_h - (get_decimals(player->sprite[count][5]) * wall_h / 100);
	else
		dist2 = (player->sprite[count][10] == 2) ? wall_h - (get_decimals(player->sprite[count][4]) * wall_h / 100) :
	get_decimals(player->sprite[count][4]) * wall_h / 100;*/
	if (player->struct_side.north_s == 1 || player->struct_side.south_s == 1)
		dist2 = (player->struct_side.south_s == 1) ? get_decimals(player->sprite[count][5]) * wall_h / 100
		: get_decimals(player->sprite[count][4]) * wall_h / 100;
	else
		dist2 = (player->struct_side.west_s == 1) ? wall_h - get_decimals(player->sprite[count][5]) * wall_h / 100 :
		wall_h - get_decimals(player->sprite[count][4]) * wall_h / 100;
	ratio = dist2;
	xposition_start = (int)player->sprite[count][7] - ratio + wall_h;
	if (j < wall_h && i < wall_h && i >= 0 && j >= 0)
	{
		color = set_texture_sprite(player, j * player->ids.xpm_sprite_h /
		wall_h, i * player->ids.xpm_sprite_w / wall_h);
	}
	if ((color > 0 && xposition_start - i <= player->sprite[count][3]
		&& xposition_start - i >= player->sprite[count][7]
		&& player->struct_screen.y / 2 - wall_h / 2
		+ j >= 0 && player->struct_screen.y / 2 - wall_h / 2 + j <
		player->struct_screen.y))
			change_color(player, player->struct_screen.y / 2 - wall_h / 2 + j,
			xposition_start - i, color);
}

void	pivot_textures_sprite(int i, int j, t_player *player)
{
	int count;

	count = 0;
	sort_sprite(player);
	while (player->sprite[count] && (int)player->sprite[count][0] != 0)
	{
		while (++i < player->struct_screen.x + (int)(((player->sprite[count][2] +
			player->sprite[count][6]) / 2)))
		{
			while (++j < (int)(((player->sprite[count][2] +
			player->sprite[count][6]) / 2)))
			{
			//	if (player->sprite[count][7] + ((player->sprite[count][3]
			//	- player->sprite[count][7]) / 2) < player->struct_screen.x / 2)
				draw_sprite_from_start(player, i, j, count);
			//	else
			//	draw_sprite_from_end(player, i, j, count);

			}
			j = 0;
		}
		i = 0;
		j = 0;
		count++;
	}
}
