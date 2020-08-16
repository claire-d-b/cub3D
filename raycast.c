/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raymarch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clde-ber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 08:30:38 by clde-ber          #+#    #+#             */
/*   Updated: 2020/08/14 16:36:24 by clde-ber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void check_wall_sides(t_player *player, float d, float angle)
{
	if ((int)(player->ray_x + (d - EPSILON) * sin(angle)) - (int)player->struct_side.he == -1 &&
		(int)(player->ray_y + (d - EPSILON) * cos(angle)) - (int)player->struct_side.wi == 0 && player->p == '1')
		check_side_south(player);
	else if ((int)(player->ray_x + (d - EPSILON) * sin(angle)) - (int)player->struct_side.he == 1 &&
		(int)(player->ray_y + (d - EPSILON) * cos(angle)) - (int)player->struct_side.wi == 0 && player->p == '1')
		check_side_north(player);
	else if ((int)(player->ray_y + (d - EPSILON) * cos(angle)) - (int)player->struct_side.wi == -1 &&
		(int)(player->ray_x + (d - EPSILON) * sin(angle)) - (int)player->struct_side.he == 0 && player->p == '1')
		check_side_east(player);
	else if ((int)(player->ray_y + (d - EPSILON) * cos(angle)) - (int)player->struct_side.wi == 1 &&
		(int)(player->ray_x + (d - EPSILON) * sin(angle)) - (int)player->struct_side.he == 0 && player->p == '1')
		check_side_west(player);
}

void register_dist_minmax(t_player *player, float d, float angle, int i)
{
	if ((player->struct_screen.y / (d * cos(fabs(angle - player->teta)))) > player->sprite[i][2] || player->sprite[i][2] == 0)
		player->sprite[i][2] = (player->struct_screen.y / (d * cos(fabs(angle - player->teta))));
	if ((player->struct_screen.y / d > player->sprite[i][9] || player->sprite[i][9] == 0))
		player->sprite[i][9] = player->struct_screen.y / d;
	if (player->struct_screen.y / (d * cos(fabs(angle - player->teta))) < player->sprite[i][6] || player->sprite[i][6] == 0)
		player->sprite[i][6] = player->struct_screen.y / (d * cos(fabs(angle - player->teta)));
}

float raycast(t_player *player, char **map, float angle)
{
	float d;
	int i;
	
	printf("player->teta %f\n", fabs(angle - player->teta));
//	printf("player->table_lenght - 1 %d\n", player->table_lenght - 1);
//	printf("player->max - 1 %d\n", player->max - 1);
	init_var_raycast(&d, player, &i);
	while (player->p != '1')
	{
		if ((int)(player->ray_x + d * sin(angle)) > player->table_lenght - 1 || (int)(player->ray_x + d * sin(angle)) < 0
		|| (int)(player->ray_y + d * cos(angle)) > player->max - 1 || (int)(player->ray_y + d * cos(angle)) < 0)
			break ;
		player->p = map[(int)(player->ray_x + d * sin(angle))][(int)(player->ray_y + d * cos(angle))];
		if (player->p == '2')
		{
			i = 0;
			while (is_sprite(player->sprite[i]) && ((((int)player->sprite[i][0] != 
				(int)(player->ray_x + d * sin(angle)) || ((int)player->sprite[i][1] != 
					(int)(player->ray_y + d * cos(angle)))))))
				i++;
			if (!is_sprite(player->sprite[i]))
				register_sprite_start(i, player, angle, d);
			register_dist_minmax(player, d, angle, i);
			register_sprite_end(i, player, angle, d);
		//	player->boolean = 1;
		}
		d += EPSILON;
	}
	define_heightawidth(player, d, angle);
	check_wall_sides(player, d, angle);
	return (d * cos(fabs(angle - player->teta)));
}

void display_all(t_player *player)
{
	pivot_textures_sprite(0, 0, player);
	mlx_put_image_to_window(player->ids.mlx_ptr, player->ids.mlx_win,
    player->ids.img_ptr, 0, 0);
	if (player->start == 1 && player->save == 1)
		create_bmp(player);
	player->start = 0;
}

void display_view_x(t_player *player, float *teta, float *dist, float *wall_h)
{
	*teta = player->teta + VIEW_ANGLE/2 - player->struct_screen.i * VIEW_ANGLE
	/ (float)player->struct_screen.x;
	*dist = raycast(player, player->map, *teta);
	*wall_h = (player->struct_screen.y / 2) / *dist;
	player->struct_screen.j = 0;
}

void display_view(t_player *player)
{
	float teta;
	float dist;
	float wall_h;

	teta = 0;
	dist = 0;
	init_pixels(player, &wall_h);
	init_sprite(player);
	while (++player->struct_screen.i < player->struct_screen.x)
	{
		display_view_x(player, &teta, &dist, &wall_h);
	//	printf("dist %f\n", dist);
		while ((player->struct_screen.j < player->struct_screen.y / 2 - (int)wall_h))
			pivot_colors_c(player);
		while ((player->struct_screen.j < player->struct_screen.y / 2 + (int)wall_h))
        {
			if ((player->struct_side.south == 1 || player->struct_side.north == 1) && player->p == '1')
				pivot_textures_ns(player, dist);
			if ((player->struct_side.east == 1 || player->struct_side.west == 1) && player->p == '1')
				pivot_textures_ew(player, dist);
			player->struct_screen.j++;
        }
		while (player->struct_screen.j < player->struct_screen.y)
			pivot_colors_f(player);
	}
	display_all(player);
}
