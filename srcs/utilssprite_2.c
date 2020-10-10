/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilssprite_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clde-ber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 14:16:26 by clde-ber          #+#    #+#             */
/*   Updated: 2020/10/03 14:16:29 by clde-ber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				create_sprite_tab(t_player *player)
{
	int count;
	int j;

	count = -1;
	j = -1;
	if (!(player->sprite = malloc(sizeof(float *) * (player->max *
	player->table_lenght + 1))))
		return (0);
	while (++count < player->max * player->table_lenght)
	{
		if (!(player->sprite[count] = malloc(sizeof(float) * 17)))
			return (0);
		while (++j < 16)
			player->sprite[count][j] = 0;
	}
	player->sprite[count] = NULL;
	return (0);
}

void			register_sprite_start(int i, t_player *player, float angle,
float d)
{
	player->sprite[i][4] = player->ray_x + (d) * sin(angle);
	player->sprite[i][5] = player->ray_y + (d) * cos(angle);
	player->sprite[i][7] = player->struct_screen.i;
	player->sprite[i][10] = player->struct_screen.x / (d * cos(fabs(angle
		- player->teta)));
	player->nb_sprites++;
}

void			register_sprite_end(int i, t_player *player, float angle,
float d)
{
	player->sprite[i][0] = player->ray_x + d * sin(angle);
	player->sprite[i][1] = player->ray_y + d * cos(angle);
	player->sprite[i][3] = player->struct_screen.i;
	player->sprite[i][13] = (player->sprite[i][13] == 0 && player->dist_wall
	> d * cos(fabs(angle - player->teta))) ?
	player->struct_screen.i : player->sprite[i][13];
	player->sprite[i][14] = (player->sprite[i][14] == 0 && player->dist_wall
	> d * cos(fabs(angle - player->teta))) ?
	(player->struct_screen.x) / (d * cos(fabs(angle - player->teta))) :
	player->sprite[i][14];
	player->sprite[i][12] = (player->dist_wall >
	d * cos(fabs(angle - player->teta))) ?
	player->struct_screen.i : player->sprite[i][12];
	player->sprite[i][15] = (player->dist_wall
	> d * cos(fabs(angle - player->teta))) ?
	(player->struct_screen.x) / (d * cos(fabs(angle - player->teta))) :
	player->sprite[i][15];
	player->sprite[i][9] = (player->map[(int)(player->ray_x + (d - EPSILON)
	* sin(angle))][(int)(player->ray_y + (d - EPSILON) * cos(angle))] != '2') ?
	(player->struct_screen.x) / (d * cos(fabs(angle - player->teta))) :
	player->sprite[i][9];
	player->boolean = 0;
}

void			register_dist_minmax(t_player *player, float d, float angle,
int i)
{
	if (((player->struct_screen.x) / (d * cos(fabs(angle - player->teta)))) >
	player->sprite[i][2] || player->sprite[i][2] == 0)
		player->sprite[i][2] = ((player->struct_screen.x) / (d * cos(fabs(angle
		- player->teta))));
	if (((player->struct_screen.x) / (d * cos(fabs(angle
		- player->teta))) > player->sprite[i][11] ||
	player->sprite[i][11] == 0))
		player->sprite[i][11] = (player->struct_screen.x) / (d * cos(fabs(angle
		- player->teta)));
	if ((player->struct_screen.x) / (d * cos(fabs(angle - player->teta))) <
	player->sprite[i][6] || player->sprite[i][6] == 0)
		player->sprite[i][6] = (player->struct_screen.x) / (d * cos(fabs(angle
		- player->teta)));
}

unsigned int	set_texture_sprite(t_player *player, int y, int i)
{
	unsigned int color;

	if (((((y * player->ids.xpm_sprite_w * 4) + (i * 4) + 3))) <=
	(player->ids.xpm_sprite_w * player->ids.xpm_sprite_h * 4) &&
	(((y * player->ids.xpm_sprite_w * 4) + (i * 4))) >= 0)
	{
		player->struct_side.pixel[0] =
		player->ids.xpm_data_sprite[((((y * (player->ids.xpm_sprite_w) * 4))
		+ (i * 4)))];
		player->struct_side.pixel[1] =
		player->ids.xpm_data_sprite[((((y * (player->ids.xpm_sprite_w) * 4))
		+ (i * 4))) + 1];
		player->struct_side.pixel[2] =
		player->ids.xpm_data_sprite[((((y * (player->ids.xpm_sprite_w) * 4))
		+ (i * 4))) + 2];
		player->struct_side.pixel[3] =
		player->ids.xpm_data_sprite[((((y * (player->ids.xpm_sprite_w) * 4))
		+ (i * 4))) + 3];
	}
	color = rgb3(player->struct_side.pixel[2], player->struct_side.pixel[1],
	player->struct_side.pixel[0]);
	return (color);
}
