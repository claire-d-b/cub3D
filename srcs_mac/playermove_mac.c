/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moved.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clde-ber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 13:49:10 by clde-ber          #+#    #+#             */
/*   Updated: 2020/08/28 10:00:49 by clde-ber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_mac.h"

void	walk_down(t_player *player)
{
	float stepx;
	float stepy;

	stepx = -sin(player->teta);
	stepy = -cos(player->teta);
	if (player->map[(int)((player->x + stepx * CELL_SIZE) / CELL_SIZE - 1)]
	[(int)((player->y + stepy * CELL_SIZE) / CELL_SIZE - 1)] != '1')
	{
		player->x += stepx * CELL_SIZE / 4;
		player->y += stepy * CELL_SIZE / 4;
	}
}

void	walk_left(t_player *player)
{
	float stepx;
	float stepy;

	stepx = cos(player->teta);
	stepy = -sin(player->teta);
	if (player->map[(int)((player->x + stepx * CELL_SIZE) / CELL_SIZE - 1)]
	[(int)((player->y + stepy * CELL_SIZE) / CELL_SIZE - 1)] != '1')
	{
		player->x += stepx * CELL_SIZE / 4;
		player->y += stepy * CELL_SIZE / 4;
	}
}

void	walk_right(t_player *player)
{
	float stepx;
	float stepy;

	stepx = -cos(player->teta);
	stepy = sin(player->teta);
	if (player->map[(int)((player->x + stepx * CELL_SIZE) / CELL_SIZE - 1)]
	[(int)((player->y + stepy * CELL_SIZE) / CELL_SIZE - 1)] != '1')
	{
		player->x += stepx * CELL_SIZE / 4;
		player->y += stepy * CELL_SIZE / 4;
	}
}

void	walk_up(t_player *player)
{
	float stepx;
	float stepy;

	stepy = cos(player->teta);
	stepx = sin(player->teta);
	if (player->map[(int)((player->x + stepx * CELL_SIZE) / CELL_SIZE - 1)]
	[(int)((player->y + stepy * CELL_SIZE) / CELL_SIZE - 1)] != '1')
	{
		player->y += stepy * CELL_SIZE / 4;
		player->x += stepx * CELL_SIZE / 4;
	}
}
