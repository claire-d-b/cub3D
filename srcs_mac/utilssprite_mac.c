/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilssprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clde-ber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 12:11:42 by clde-ber          #+#    #+#             */
/*   Updated: 2020/09/20 15:48:22 by clde-ber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_mac.h"

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
