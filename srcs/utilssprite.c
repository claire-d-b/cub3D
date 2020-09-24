/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilssprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clde-ber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 12:11:42 by clde-ber          #+#    #+#             */
/*   Updated: 2020/08/28 10:30:04 by clde-ber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		is_sprite(float *sprite)
{
	int i;

	i = 0;
	if (sprite)
	{
		while (i < 14 && sprite[i] == 0)
			i++;
		return (i == 14) ? 0 : 1;
	}
	else
		return (0);
}

void	del_sprites1(t_player *player)
{
	if (player->map[(int)((player->x) / CELL_SIZE) - 1]
	[(int)((player->y) / CELL_SIZE) - 1] == '2')
		player->map[(int)((player->x) / CELL_SIZE) - 1]
		[(int)((player->y) / CELL_SIZE) - 1] = '0';
	if (player->map[(int)((player->x) / CELL_SIZE) - 1]
	[(int)((player->y) / CELL_SIZE)] == '2')
		player->map[(int)((player->x) / CELL_SIZE) - 1]
		[(int)((player->y) / CELL_SIZE)] = '0';
	if (player->map[(int)((player->x) / CELL_SIZE) - 1]
	[(int)((player->y) / CELL_SIZE) - 2] == '2')
		player->map[(int)((player->x) / CELL_SIZE) - 1]
		[(int)((player->y) / CELL_SIZE) - 2] = '0';
	if (player->map[(int)((player->x) / CELL_SIZE) - 2]
	[(int)((player->y) / CELL_SIZE) - 1] == '2')
		player->map[(int)((player->x) / CELL_SIZE) - 2]
		[(int)((player->y) / CELL_SIZE) - 1] = '0';
	if (player->map[(int)((player->x) / CELL_SIZE) - 2]
	[(int)((player->y) / CELL_SIZE)] == '2')
		player->map[(int)((player->x) / CELL_SIZE) - 2]
		[(int)((player->y) / CELL_SIZE)] = '0';
}

void	del_sprites2(t_player *player)
{
	if (player->map[(int)((player->x) / CELL_SIZE) - 2]
	[(int)((player->y) / CELL_SIZE) - 2] == '2')
		player->map[(int)((player->x) / CELL_SIZE) - 2]
		[(int)((player->y) / CELL_SIZE) - 2] = '0';
	if (player->map[(int)((player->x) / CELL_SIZE)]
	[(int)((player->y) / CELL_SIZE) - 1] == '2')
		player->map[(int)((player->x) / CELL_SIZE)]
		[(int)((player->y) / CELL_SIZE) - 1] = '0';
	if (player->map[(int)((player->x) / CELL_SIZE)]
	[(int)((player->y) / CELL_SIZE)] == '2')
		player->map[(int)((player->x) / CELL_SIZE)]
		[(int)((player->y) / CELL_SIZE)] = '0';
	if (player->map[(int)((player->x) / CELL_SIZE)]
	[(int)((player->y) / CELL_SIZE) - 2] == '2')
		player->map[(int)((player->x) / CELL_SIZE)]
		[(int)((player->y) / CELL_SIZE) - 2] = '0';
}

void	delete_sprites(t_player *player)
{
	del_sprites1(player);
	del_sprites2(player);
}

void	sort_sprite(t_player *player)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (player->sprite[i])
	{
		while (player->sprite[j])
		{
			if (player->sprite[j][11] < player->sprite[i][11] &&
			player->sprite[i][11] && player->sprite[j][11])
				ft_swap(&player->sprite[i], &player->sprite[j]);
			j++;
		}
		i++;
		j = i + 1;
	}
}
