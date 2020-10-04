/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raymarch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clde-ber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 08:30:38 by clde-ber          #+#    #+#             */
/*   Updated: 2020/08/28 10:01:22 by clde-ber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	raycast(t_player *player, char **map, float angle)
{
	float	d;
	int		i;

	init_var_raycast(&player->p, &d, player, &i);
	while (is_not_wall(player, angle, d))
	{
		player->p = map[(int)(player->ray_x + d * sin(angle))]
		[(int)(player->ray_y + d * cos(angle))];
		d += EPSILON;
	}
	define_heightawidth(player, d, angle);
	check_wall_sides(player, d, angle);
	return (d * cos(fabs(angle - player->teta)));
}

float	raycast_sprites(t_player *player, char **map, float angle)
{
	float	d;
	int		i;

	init_var_raycast(&player->p2, &d, player, &i);
	while (is_not_sprite(player, angle, d))
	{
		player->p2 = map[(int)(player->ray_x + d * sin(angle))]
		[(int)(player->ray_y + d * cos(angle))];
		if (player->p2 == '1')
			player->dist_wall = d * cos(fabs(angle - player->teta));
		if (player->p2 == '2')
		{
			i = 0;
			while (is_sprite(player->sprite[i]) && is_new(player, d, angle, i))
				i++;
			if (!is_sprite(player->sprite[i]))
				register_sprite_start(i, player, angle, d);
			register_dist_minmax(player, d, angle, i);
			register_sprite_end(i, player, angle, d);
		}
		d += EPSILON;
	}
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
	player->dist_sprite = raycast_sprites(player, player->map, *teta);
	*wall_h = (player->struct_screen.x / 2) / *dist;
	player->struct_screen.j = 0;
}

void	display_view(float teta, float dist, double wall_h, t_player *player)
{
	init_pixels(player);
	init_sprite(player);
	while (++player->struct_screen.i < player->struct_screen.x)
	{
		display_view_x(player, &teta, &dist, &wall_h);
		while ((player->struct_screen.j < player->struct_screen.y / 2
		- (int)wall_h))
			pivot_colors_c(player);
		while ((player->struct_screen.j < player->struct_screen.y / 2
		+ (int)wall_h))
		{
			if ((player->struct_side.east == 1 || player->struct_side.west
			== 1) && player->p == '1')
				pivot_textures_ew(0, (int)(player->struct_screen.x / dist),
				player);
			if ((player->struct_side.south == 1 || player->struct_side.north
			== 1) && player->p == '1')
				pivot_textures_ns(0, (int)(player->struct_screen.x / dist),
				player);
			player->struct_screen.j++;
		}
		while (player->struct_screen.j < player->struct_screen.y)
			pivot_colors_f(player);
	}
	display_all(player);
}
