/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsraymarch_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clde-ber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 14:16:07 by clde-ber          #+#    #+#             */
/*   Updated: 2020/10/03 14:16:10 by clde-ber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		is_not_wall(t_player *player, float angle, float d)
{
	if (player->p != '1' && (!(((int)(player->ray_x + d * sin(angle)) >
	player->table_lenght - 1 || (int)(player->ray_x + d * sin(angle)) < 0) ||
	((int)(player->ray_y + d * cos(angle)) > player->max - 1 ||
	(int)(player->ray_y + d * cos(angle)) < 0))))
		return (1);
	return (0);
}

int		is_not_sprite(t_player *player, float angle, float d)
{
	if ((!(((int)(player->ray_x + d * sin(angle)) >
	player->table_lenght - 1 || (int)(player->ray_x + d * sin(angle)) < 0) ||
	((int)(player->ray_y + d * cos(angle)) > player->max - 1 ||
	(int)(player->ray_y + d * cos(angle)) < 0))))
		return (1);
	return (0);
}

int		is_new(t_player *player, float d, float angle, int i)
{
	if (((int)player->sprite[i][4] != (int)(player->ray_x +
	d * sin(angle))) || ((int)player->sprite[i][5] !=
	(int)(player->ray_y + d * cos(angle))))
		return (1);
	return (0);
}

void	check_wall_dist_before_sprite(t_player *player, int count, float d)
{
	player->boolean++;
	player->distance = player->struct_screen.x / d;
	if (player->boolean == 2)
	{
		while (is_sprite(player->sprite[count]))
			count++;
		if (count > 0)
			player->sprite[count - 1][9] = player->distance;
	}
}
