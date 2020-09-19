/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raymarch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clde-ber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 08:30:38 by clde-ber          #+#    #+#             */
/*   Updated: 2020/09/19 12:07:56 by clde-ber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_mac.h"

int		is_not_wall(t_player *player, float angle, float d)
{
	if (player->p != '1' && (!(((int)(player->ray_x + d * sin(angle)) >
	player->table_lenght - 1 || (int)(player->ray_x + d * sin(angle)) < 0) ||
	((int)(player->ray_y + d * cos(angle)) > player->max - 1 ||
	(int)(player->ray_y + d * cos(angle)) < 0))))
		return (1);
	return (0);
}

float	raycast(t_player *player, char **map, float angle)
{
	float	d;
	int		i;
	int		count;

	count = 0;
	init_var_raycast(&player->p, &d, player, &i);
	while (is_not_wall(player, angle, d))
	{
		player->p = map[(int)(player->ray_x + d * sin(angle))]
		[(int)(player->ray_y + d * cos(angle))];
		if (player->p == '2')
		{
			i = 0;
			while (is_sprite(player->sprite[i]) && ((((int)player->sprite[i][4]
			!= (int)(player->ray_x + d * sin(angle)) || ((int)
			player->sprite[i][5] != (int)(player->ray_y + d * cos(angle)))))))
				i++;
			if (!is_sprite(player->sprite[i]))
			{
				init_struct_side_s(player, i);
				register_sprite_start(i, player, angle, d);
			}
			register_dist_minmax(player, d, angle, i);
			register_sprite_end(i, player, angle, d);
			player->boolean = 0;
		}
		d += EPSILON;
	}
	player->boolean++;
	player->distance = player->struct_screen.x / d;
	if (player->boolean == 2)
	{
		while (is_sprite(player->sprite[count]))
			count++;
		if (count > 0)
			player->sprite[count - 1][9] = player->distance;
	}
	define_heightawidth(player, d, angle);
	check_wall_sides(player, d, angle);
	return (d * cos(fabs(angle - player->teta)));
}

void	display_all(t_player *player)
{
	pivot_textures_sprite(-1, -1, player);
	mlx_put_image_to_window(player->ids.mlx_ptr, player->ids.mlx_win,
	player->ids.img_ptr, 0, 0);
	if (player->start == 1 && player->save == 1)
		create_bmp(player);
	player->start = 0;
}

void	display_view_x(t_player *player, float *teta, float *dist,
double *wall_h)
{
	*teta = player->teta + FOV / 2 - player->struct_screen.i * FOV
	/ (float)player->struct_screen.x;
	*dist = raycast(player, player->map, *teta);
	*wall_h = (player->struct_screen.x / 2) / *dist;
	player->struct_screen.j = 0;
}

void	display_view(float teta, float dist, double wall_h, t_player *player)
{
	init_pixels(player);
	init_sprite(player);
	player->boolean = 0;
	player->distance = 0;
	while (++player->struct_screen.i < player->struct_screen.x)
	{
		display_view_x(player, &teta, &dist, &wall_h);
		while ((player->struct_screen.j < player->struct_screen.y / 2
		- (int)wall_h))
			pivot_colors_c(player);
		while ((player->struct_screen.j < player->struct_screen.y / 2
		+ (int)wall_h))
		{
			if ((player->struct_side.south == 1 || player->struct_side.north
			== 1) && player->p == '1')
				pivot_textures_ns(0, (int)(player->struct_screen.x / dist),
				player);
			if ((player->struct_side.east == 1 || player->struct_side.west == 1)
			&& player->p == '1')
				pivot_textures_ew(0, (int)(player->struct_screen.x / dist),
				player);
			player->struct_screen.j++;
		}
		while (player->struct_screen.j < player->struct_screen.y)
			pivot_colors_f(player);
	}
	display_all(player);
}
