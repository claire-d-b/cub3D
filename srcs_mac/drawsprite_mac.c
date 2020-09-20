/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawsprite.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clde-ber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 11:36:12 by clde-ber          #+#    #+#             */
/*   Updated: 2020/09/20 17:33:10 by clde-ber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_mac.h"

void	register_sprite_start(int i, t_player *player, float angle, float d)
{
	player->sprite[i][4] = player->ray_x + (d) * sin(angle);
	player->sprite[i][5] = player->ray_y + (d) * cos(angle);
	player->sprite[i][7] = player->struct_screen.i;
	player->sprite[i][10] = player->struct_screen.x / d;
	if (player->distance > player->sprite[i][10])
		player->sprite[i][10] = player->distance;
	player->nb_sprites++;
}

void	register_sprite_end(int i, t_player *player, float angle, float d)
{
	player->sprite[i][0] = player->ray_x + (d) * sin(angle);
	player->sprite[i][1] = player->ray_y + (d) * cos(angle);
	player->sprite[i][18] = (player->sprite[i][18] == 0 && get_decimals(player->ray_y + d * cos(angle)) > 48 && 
	get_decimals(player->ray_y + d * cos(angle)) < 52) ?
	player->ray_x + d * sin(angle) : player->sprite[i][18];
	player->sprite[i][12] = (player->sprite[i][12] == 0 && get_decimals(player->ray_y + d * cos(angle)) > 48 && 
	get_decimals(player->ray_y + d * cos(angle)) < 52) ?
	player->struct_screen.i : player->sprite[i][12];
	player->sprite[i][14] = (get_decimals(player->ray_y + d * cos(angle)) > 48 && 
	get_decimals(player->ray_y + d * cos(angle)) < 52) ?
	player->struct_screen.i : player->sprite[i][14];
	player->sprite[i][2] = (get_decimals(player->ray_y + d * cos(angle)) > 48 && 
	get_decimals(player->ray_y + d * cos(angle)) < 52 && player->struct_screen.x / (d * cos(fabs(angle -
	player->teta))) < player->sprite[i][2]) ?
	player->struct_screen.x / (d * cos(fabs(angle - player->teta))) : player->sprite[i][2];
	player->sprite[i][16] = (get_decimals(player->ray_y + d * cos(angle)) > 48 && 
	get_decimals(player->ray_y + d * cos(angle)) < 52 && player->struct_screen.x / (d * cos(fabs(angle -
	player->teta))) > player->sprite[i][16]) ?
	player->struct_screen.x / (d * cos(fabs(angle - player->teta))) : player->sprite[i][16];
	player->sprite[i][19] = (player->sprite[i][19] == 0 && get_decimals(player->ray_x + d * sin(angle)) > 48 && 
	get_decimals(player->ray_x + d * sin(angle)) < 52) ?
	player->ray_y + d * cos(angle) : player->sprite[i][19];
	player->sprite[i][13] = (player->sprite[i][13] == 0 && get_decimals(player->ray_x + d * sin(angle)) > 48 && 
	get_decimals(player->ray_x + d * sin(angle)) < 52) ?
	player->struct_screen.i : player->sprite[i][13];
	player->sprite[i][15] = (get_decimals(player->ray_x + d * sin(angle)) > 48 && 
	get_decimals(player->ray_x + d * sin(angle)) < 52) ?
	player->struct_screen.i : player->sprite[i][15];
	player->sprite[i][6] = ((player->sprite[i][6] == 0 || player->struct_screen.x / (d * cos(fabs(angle -
	player->teta))) < player->sprite[i][6]) && get_decimals(player->ray_x + d * sin(angle)) > 48 && 
	get_decimals(player->ray_x + d * sin(angle)) < 52) ?
	player->struct_screen.x / (d * cos(fabs(angle - player->teta))) : player->sprite[i][6];
	player->sprite[i][17] = ((player->sprite[i][17] == 0 || player->struct_screen.x / (d * cos(fabs(angle -
	player->teta))) > player->sprite[i][17]) && get_decimals(player->ray_x + d * sin(angle)) > 48 && 
	get_decimals(player->ray_x + d * sin(angle)) < 52) ?
	player->struct_screen.x / (d * cos(fabs(angle - player->teta))) : player->sprite[i][17];
	player->sprite[i][3] = player->struct_screen.i;
	player->sprite[i][9] = (player->map[(int)(player->ray_x + (d - EPSILON) * sin(angle))][(int)(player->ray_y + (d - EPSILON) * cos(angle))] != '2' || player->sprite[i][9] == 0) ?
		(player->struct_screen.x) / d : player->sprite[i][9];
	check_sprite_sides(player, d, angle, i);
}

void	draw_sprite_from_start(t_player *player, int i, int j, int count)
{
	unsigned int	color;
	int				xposition_start;
	int				xposition_end;
	double			wall_h;

	color = 0;
	wall_h = (player->sprite[count][6] + player->sprite[count][17]) / 2;
	xposition_end =
	(int)(player->sprite[count][3] + (wall_h - (player->sprite[count][3] - player->sprite[count][7])));
	xposition_start =
	(int)(player->sprite[count][7] - (wall_h - (player->sprite[count][3] - player->sprite[count][7])));
	if (player->sprite[count][8] == 0
	&& j <= wall_h && (((get_decimals(player->sprite[count][19]) * wall_h / 100)) + i) <= wall_h &&
	(((get_decimals(player->sprite[count][19]) * wall_h / 100)) + i) >= 0 && j >= 0)
	{
		color = set_texture_sprite(player, j * player->ids.xpm_sprite_h /
		wall_h, (((get_decimals(player->sprite[count][19]) * wall_h / 100)) + i) * player->ids.xpm_sprite_w / wall_h);
	}
	if (player->sprite[count][8] == 1
	&& j <= wall_h && ((wall_h - (get_decimals(player->sprite[count][19]) * wall_h / 100)) + i) <= wall_h &&
	((wall_h - (get_decimals(player->sprite[count][19]) * wall_h / 100)) + i) >= 0 && j >= 0)
	{
		color = set_texture_sprite(player, j * player->ids.xpm_sprite_h /
		wall_h, ((wall_h - (get_decimals(player->sprite[count][19]) * wall_h / 100)) + i) * player->ids.xpm_sprite_w / wall_h);
	}

	if ((player->sprite[count][8] == 0 || player->sprite[count][8] == 1) &&
	color > 0 && player->sprite[count][7] + i <= player->sprite[count][3]
		&& player->sprite[count][7] + i >= player->sprite[count][7]
		&& player->struct_screen.y / 2 - wall_h / 2
		+ j >= 0 && player->struct_screen.y / 2 - wall_h / 2 + j <
		player->struct_screen.y)
			change_color(player, player->struct_screen.y / 2 - wall_h / 2 + j,
			player->sprite[count][7] + i , color);
	if ((player->sprite[count][8] == 3) &&
	j <= wall_h && (((get_decimals(player->sprite[count][18]) * wall_h / 100)) + i) <= wall_h &&
	(((get_decimals(player->sprite[count][18]) * wall_h / 100)) + i) >= 0 && j >= 0)
	{
		color = set_texture_sprite(player, j * player->ids.xpm_sprite_h /
		wall_h, (((get_decimals(player->sprite[count][18]) * wall_h / 100)) + i) * player->ids.xpm_sprite_w / wall_h);
	}
	if ((player->sprite[count][8] == 2) &&
	j <= wall_h && ((wall_h - (get_decimals(player->sprite[count][18]) * wall_h / 100)) + i) <= wall_h &&
	((wall_h - (get_decimals(player->sprite[count][18]) * wall_h / 100)) + i) >= 0 && j >= 0)
	{
		color = set_texture_sprite(player, j * player->ids.xpm_sprite_h /
		wall_h, ((wall_h - (get_decimals(player->sprite[count][18]) * wall_h / 100)) + i) * player->ids.xpm_sprite_w / wall_h);
	}
	if ((player->sprite[count][8] == 2 || player->sprite[count][8] == 3) &&
	color > 0 && player->sprite[count][7] + i <= player->sprite[count][3]
		&& player->sprite[count][7] + i >= player->sprite[count][7]
		&& player->struct_screen.y / 2 - wall_h / 2
		+ j >= 0 && player->struct_screen.y / 2 - wall_h / 2 + j <
		player->struct_screen.y)
			change_color(player, player->struct_screen.y / 2 - wall_h / 2 + j,
			player->sprite[count][7] + i , color);

}

void	pivot_textures_sprite(int i, int j, t_player *player)
{
	int count;

	count = 0;
	sort_sprite(player);
	while (player->sprite[count] && is_sprite(player->sprite[count]))
	{
		printf("count 8 %f\n", player->sprite[count][8]);
		printf("count %d\n", count);
	//	printf("player->sprite[count][10] - player->sprite[count][9] %f\n", player->sprite[count][10] - player->sprite[count][9]);
	//	if (player->sprite[count][10] - player->sprite[count][9] < 0)
	//		printf("AAAAAAAAAAAAA");
	//	printf("count 3 - count 7 %f\n", player->sprite[count][3] - player->sprite[count][7]);
	//	printf("wall_h %f\n", ((player->sprite[count][6] + player->sprite[count][2]) / 2));
	//	printf("get dec 1 %d\n", get_decimals(player->sprite[count][1]));
	//	printf("get dec 0 %d\n", get_decimals(player->sprite[count][0]));
		while (++i < player->struct_screen.x)
		{
			while (++j < (player->sprite[count][6] + player->sprite[count][17]) / 2)
			{
			//	if (player->sprite[count][7] + ((player->sprite[count][3]
			//	- player->sprite[count][7]) / 2) < player->struct_screen.x / 2)
				draw_sprite_from_start(player, i, j, count);
			//	else
			//	draw_sprite_from_end(player, i, j, count);

			}
			j = -1;
		}
		i = -1;
		j = -1;
		count++;
	}
}
