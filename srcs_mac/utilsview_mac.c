/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsview.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clde-ber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 11:44:48 by clde-ber          #+#    #+#             */
/*   Updated: 2020/09/20 16:45:02 by clde-ber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_mac.h"

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
	mlx_destroy_image(player->ids.mlx_ptr, player->ids.img_ptr);
	mlx_clear_window(player->ids.mlx_ptr, player->ids.mlx_win);
	mlx_destroy_window(player->ids.mlx_ptr, player->ids.mlx_win);
	if (player->sprite)
		ft_free_sprite(player->sprite);
	if (player->map)
		ft_free_tab(player->map);
	if (player->xpm_path_no)
		free(player->xpm_path_no);
	if (player->xpm_path_so)
		free(player->xpm_path_so);
	if (player->xpm_path_we)
		free(player->xpm_path_we);
	if (player->xpm_path_ea)
		free(player->xpm_path_ea);
	if (player->xpm_path_sp)
		free(player->xpm_path_sp);
	init_struct_player_exit(player);
	init_struct_screen_exit(player);
	init_struct_side_s_e(player);
	init_struct_bitmap_exit(player);
	exit(0);
	return (0);
}

void			check_wall_sides(t_player *player, float d, float angle)
{
	if ((int)(player->ray_x + (d - EPSILON) * sin(angle)) -
	(int)player->struct_side.he == -1 && (int)(player->ray_y + (d - EPSILON) *
	cos(angle)) - (int)player->struct_side.wi == 0 && player->p == '1')
		check_side_west(player);
	else if ((int)(player->ray_x + (d - EPSILON) * sin(angle)) -
	(int)player->struct_side.he == 1 && (int)(player->ray_y + (d - EPSILON) *
	cos(angle)) - (int)player->struct_side.wi == 0 && player->p == '1')
		check_side_east(player);
	else if ((int)(player->ray_y + (d - EPSILON) * cos(angle)) -
	(int)player->struct_side.wi == -1 && (int)(player->ray_x + (d - EPSILON) *
	sin(angle)) - (int)player->struct_side.he == 0 && player->p == '1')
		check_side_north(player);
	else if ((int)(player->ray_y + (d - EPSILON) * cos(angle)) -
	(int)player->struct_side.wi == 1 && (int)(player->ray_x + (d - EPSILON) *
	sin(angle)) - (int)player->struct_side.he == 0 && player->p == '1')
		check_side_south(player);
}
