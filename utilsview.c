/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsview.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clde-ber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 11:44:48 by clde-ber          #+#    #+#             */
/*   Updated: 2020/08/20 14:11:21 by clde-ber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned int	rgb3(unsigned int r, unsigned int g, unsigned int b)
{
	return (r * 256 * 256) + (g * 256) + b;
}

void			change_color(t_player *player, int y, int i, unsigned int color)
{
	if ((int)(((y * (player->struct_screen.x) * 4) + (i * 4) + 3)) <
	player->struct_screen.x * player->struct_screen.y * 4 && (int)(((
	y * (player->struct_screen.x) * 4) + (i * 4))) >= 0)
	{
		player->ids.img_data[(int)(((y * (player->struct_screen.x) * 4) +
		(i * 4)))] = color;
		player->ids.img_data[(int)(((y * (player->struct_screen.x) * 4) +
		(i * 4) + 1))] = color / 256;
		player->ids.img_data[(int)(((y * (player->struct_screen.x) * 4) +
		(i * 4) + 2))] = color / (256 * 256);
		player->ids.img_data[(int)(((y * (player->struct_screen.x) * 4) +
		(i * 4) + 3))] = 1;
	}
}

int				get_decimals(float height)
{
	int res;

	res = (int)((height - (int)height) * 100);
	return (res);
}

int				exit_game(t_player *player)
{
	mlx_clear_window(player->ids.mlx_ptr, player->ids.mlx_win);
	mlx_destroy_window(player->ids.mlx_ptr, player->ids.mlx_win);
	player->ids.mlx_ptr = 0;
	player->ids.mlx_win = 0;
	exit(0);
}

void			check_wall_sides(t_player *player, float d, float angle)
{
	if ((int)(player->ray_x + (d - EPSILON) * sin(angle)) -
	(int)player->struct_side.he == -1 && (int)(player->ray_y + (d - EPSILON) *
	cos(angle)) - (int)player->struct_side.wi == 0 && player->p == '1')
		check_side_south(player);
	else if ((int)(player->ray_x + (d + EPSILON) * sin(angle)) -
	(int)player->struct_side.he == 1 && (int)(player->ray_y + (d - EPSILON) *
	cos(angle)) - (int)player->struct_side.wi == 0 && player->p == '1')
		check_side_north(player);
	else if ((int)(player->ray_y + (d - EPSILON) * cos(angle)) -
	(int)player->struct_side.wi == -1 && (int)(player->ray_x + (d - EPSILON) *
	sin(angle)) - (int)player->struct_side.he == 0 && player->p == '1')
		check_side_east(player);
	else if ((int)(player->ray_y + (d - EPSILON) * cos(angle)) -
	(int)player->struct_side.wi == 1 && (int)(player->ray_x + (d - EPSILON) *
	sin(angle)) - (int)player->struct_side.he == 0 && player->p == '1')
		check_side_west(player);
}
