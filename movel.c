/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clde-ber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 13:47:52 by clde-ber          #+#    #+#             */
/*   Updated: 2020/08/19 18:36:09 by clde-ber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	walk_left(t_player *player)
{
	if (player->teta >= 0 || (int)player->teta == (int)-M_PI)
		walk_left_teta_pos(player);
	else
		walk_left_teta_neg(player);
}

void	walk_left_teta_pos_diag(t_player *player)
{
	if (get_decimals(player->teta) == get_decimals(M_PI / 4))
	{
		if (player->map[(int)((player->x - CELL_SIZE) / CELL_SIZE) - 1][(int)((
	player->y + CELL_SIZE) / CELL_SIZE) - 1] != '1' && (int)((player->x -
	CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->x - CELL_SIZE) / CELL_SIZE)
	< player->table_lenght && (int)((player->y + CELL_SIZE) / CELL_SIZE) > 1 &&
	(int)((player->y + CELL_SIZE) / CELL_SIZE) < player->max)
		{
			player->x = player->x - CELL_SIZE;
			player->y = player->y + CELL_SIZE;
		}
	}
	else if (get_decimals(player->teta) == get_decimals((M_PI / 4) * 3))
	{
		if (player->map[(int)((player->x + CELL_SIZE) / CELL_SIZE) - 1][(int)((
	player->y + CELL_SIZE) / CELL_SIZE) - 1] != '1' && (int)((player->x +
	CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->x + CELL_SIZE) / CELL_SIZE)
	< player->table_lenght && (int)((player->y + CELL_SIZE) / CELL_SIZE) > 1 &&
	(int)((player->y + CELL_SIZE) / CELL_SIZE) < player->max)
		{
			player->x = player->x + CELL_SIZE;
			player->y = player->y + CELL_SIZE;
		}
	}
}

void	walk_left_teta_pos(t_player *player)
{
	if (get_decimals(player->teta) == get_decimals(M_PI / 4) ||
	get_decimals(player->teta) == get_decimals((M_PI / 4) * 3))
		walk_left_teta_pos_diag(player);
	else
	{
		if (player->teta >= 0 && player->teta < M_PI / 4)
			player->x = (player->map[(int)((player->x - CELL_SIZE) / CELL_SIZE)
			- 1][(int)(player->y / CELL_SIZE) - 1] != '1' && (int)((player->x -
			CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->x - CELL_SIZE) /
			CELL_SIZE) < player->table_lenght) ? player->x - CELL_SIZE :
			player->x;
		else if (player->teta > M_PI / 4 && player->teta < (M_PI / 4) * 3)
			player->y = (player->map[(int)(player->x / CELL_SIZE) - 1][(int)((
			player->y + CELL_SIZE) / CELL_SIZE) - 1] != '1' && (int)((player->y
			+ CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->y + CELL_SIZE) /
			CELL_SIZE) < player->max) ? player->y + CELL_SIZE : player->y;
		else
			player->x = (player->map[(int)((player->x + CELL_SIZE) / CELL_SIZE)
			- 1][(int)(player->y / CELL_SIZE) - 1] != '1' && (int)((player->x +
			CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->x + CELL_SIZE) /
			CELL_SIZE) < player->table_lenght) ? player->x + CELL_SIZE :
			player->x;
	}
}

void	walk_left_teta_neg_diag(t_player *player)
{
	if (get_decimals(player->teta) == get_decimals(-M_PI / 4))
	{
		if (player->map[(int)((player->x - CELL_SIZE) / CELL_SIZE) - 1][(int)((
	player->y - CELL_SIZE) / CELL_SIZE) - 1] != '1' && (int)((player->x -
	CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->x - CELL_SIZE) / CELL_SIZE) <
	player->table_lenght && (int)((player->y - CELL_SIZE) / CELL_SIZE) > 1 &&
	(int)((player->y - CELL_SIZE) / CELL_SIZE) < player->max)
		{
			player->x = player->x - CELL_SIZE;
			player->y = player->y - CELL_SIZE;
		}
	}
	else if (get_decimals(player->teta) == get_decimals(-(M_PI / 4) * 3))
	{
		if (player->map[(int)((player->x + CELL_SIZE) / CELL_SIZE) - 1][(int)((
	player->y - CELL_SIZE) / CELL_SIZE) - 1] != '1' && (int)((player->x +
	CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->x + CELL_SIZE) / CELL_SIZE) <
	player->table_lenght && (int)((player->y - CELL_SIZE) / CELL_SIZE) > 1 &&
	(int)((player->y - CELL_SIZE) / CELL_SIZE) < player->max)
		{
			player->x = player->x + CELL_SIZE;
			player->y = player->y - CELL_SIZE;
		}
	}
}

void	walk_left_teta_neg(t_player *player)
{
	if (get_decimals(player->teta) == get_decimals(-M_PI / 4) ||
	get_decimals(player->teta) == get_decimals(-(M_PI / 4) * 3))
		walk_left_teta_neg_diag(player);
	else
	{
		if (player->teta >= -M_PI && player->teta < -(M_PI / 4) * 3)
			player->x = (player->map[(int)((player->x + CELL_SIZE) / CELL_SIZE)
			- 1][(int)(player->y / CELL_SIZE) - 1] != '1' && (int)((player->x +
			CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->x + CELL_SIZE) /
			CELL_SIZE) < player->table_lenght) ? player->x + CELL_SIZE :
			player->x;
		else if (player->teta > (-(M_PI / 4) * 3) && player->teta < -M_PI / 4)
			player->y = (player->map[(int)(player->x / CELL_SIZE) - 1][(int)((
			player->y - CELL_SIZE) / CELL_SIZE) - 1] != '1' && (int)((player->y
			- CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->y - CELL_SIZE) /
			CELL_SIZE) < player->max) ? player->y - CELL_SIZE : player->y;
		else
			player->x = (player->map[(int)((player->x - CELL_SIZE) / CELL_SIZE)
			- 1][(int)(player->y / CELL_SIZE) - 1] != '1' && (int)((player->x -
			CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->x - CELL_SIZE) /
			CELL_SIZE) < player->table_lenght) ? player->x - CELL_SIZE :
			player->x;
	}
}
