/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilssprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clde-ber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 12:11:42 by clde-ber          #+#    #+#             */
/*   Updated: 2020/08/20 13:13:03 by clde-ber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	register_dist_minmax(t_player *player, float d, float angle, int i)
{
	if (((player->struct_screen.x) / (d * cos(fabs(angle - player->teta)))) >
	player->sprite[i][2] || player->sprite[i][2] == 0)
		player->sprite[i][2] = ((player->struct_screen.x) / (d * cos(fabs(angle
		- player->teta))));
	if (((player->struct_screen.x) / d > player->sprite[i][9] ||
	player->sprite[i][9] == 0))
		player->sprite[i][9] = (player->struct_screen.x) / d;
	if ((player->struct_screen.x) / (d * cos(fabs(angle - player->teta))) <
	player->sprite[i][6] || player->sprite[i][6] == 0)
		player->sprite[i][6] = (player->struct_screen.x) / (d * cos(fabs(angle
		- player->teta)));
}

int		is_sprite(float *sprite)
{
	int i;

	i = 0;
	if (sprite)
	{
		while (i < 10 && sprite[i] == 0)
			i++;
		return (i == 10) ? 0 : 1;
	}
	else
		return (0);
}

void	delete_sprites(t_player *player)
{
	if (player->map[(int)((player->x - 64) / 64)][(int)((player->y - 64) /
	64)] == '2')
		player->map[(int)((player->x - 64) / 64)][(int)((player->y - 64) /
		64)] = '0';
	if (player->map[(int)((player->x - 64) / 64) + 1][(int)((player->y - 64)
	/ 64)] == '2')
		player->map[(int)((player->x - 64) / 64) + 1][(int)((player->y - 64)
	/ 64)] = '0';
	if (player->map[(int)((player->x - 64) / 64)][(int)((player->y - 64) /
	64) + 1] == '2')
		player->map[(int)((player->x - 64) / 64)][(int)((player->y - 64) / 64)
		+ 1] = '0';
	if (player->map[(int)((player->x - 64) / 64) - 1][(int)((player->y - 64)
	/ 64)] == '2')
		player->map[(int)((player->x - 64) / 64) - 1][(int)((player->y - 64)
		/ 64)] = '0';
	if (player->map[(int)((player->x - 64) / 64)][(int)((player->y - 64) / 64)
	- 1] == '2')
		player->map[(int)((player->x - 64) / 64)][(int)((player->y - 64) / 64)
		- 1] = '0';
}

void	define_heightawidth(t_player *player, float d, float angle)
{
	player->struct_side.he = (player->ray_x + ((d - (2 * EPSILON)) *
	sin(angle)));
	player->struct_side.wi = (player->ray_y + ((d - (2 * EPSILON)) *
	cos(angle)));
	player->distance = (player->struct_screen.x) / (d - (2 * EPSILON));
}