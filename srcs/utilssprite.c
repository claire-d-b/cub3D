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
		while (i < 16 && sprite[i] == 0)
			i++;
		return (i == 16) ? 0 : 1;
	}
	else
		return (0);
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

void	pivot_textures_sprite(int i, int j, t_player *player)
{
	int count;

	count = 0;
	sort_sprite(player);
	while (player->sprite[count] && (int)player->sprite[count][0] != 0)
	{
		if ((int)(((player->sprite[count][6] + player->sprite[count][2])
		/ 2)) <= player->struct_screen.y)
		{
			while (++i < (int)(((player->sprite[count][6] +
			player->sprite[count][2]) / 2)))
			{
				while (++j < (int)(((player->sprite[count][6] +
				player->sprite[count][2]) / 2)))
					draw_sprite(player, i, j, count);
				j = -1;
			}
		}
		i = -1;
		j = -1;
		count++;
	}
}
