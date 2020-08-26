/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moveud.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clde-ber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 08:29:21 by clde-ber          #+#    #+#             */
/*   Updated: 2020/08/19 18:29:00 by clde-ber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	walk_right(t_player *player)
{
		float stepx;
	float stepy;

	/*if (player->teta >= 0 && player->teta < M_PI / 2)
	{
		stepy = sin(fabs(player->teta));
		stepx = cos(fabs(player->teta));
	}
	else if (player->teta > 0 && player->teta >= M_PI / 2 && player->teta <= M_PI)
	{
		stepy = sin(fabs(player->teta) - M_PI / 2);
		stepx = cos(fabs(player->teta) - M_PI / 2);
	}
	else if (player->teta < 0 && player->teta >= -M_PI && player->teta < -M_PI / 2)
	{
		stepy = sin(fabs(player->teta) - M_PI / 2);
		stepx = cos(fabs(player->teta) - M_PI / 2);
	}
	else
	{
		stepy = sin(fabs(player->teta));
		stepx = cos(fabs(player->teta));
	}
	printf("%f\n", stepy); 
	printf("%f\n", stepx);*/
	stepx = -cos(player->teta);
	stepy = sin(player->teta);
if (player->map[(int)((player->x + stepx * CELL_SIZE / 4) / CELL_SIZE - 1)]
	[(int)((player->y + stepy * CELL_SIZE / 4) / CELL_SIZE - 1)] != '1')  
	{
	player->x += stepx * CELL_SIZE / 4;
	player->y += stepy * CELL_SIZE / 4;
	}
		//else
		//	walk_left_teta_neg(player, stepy, stepx);
}

void	walk_right_teta_pos_diag(t_player *player)
{
	if (get_decimals(player->teta) == get_decimals(M_PI / 4))
	{
		if (player->map[(int)((player->x + CELL_SIZE) / CELL_SIZE) - 1][(int)((
	player->y - CELL_SIZE) / CELL_SIZE) - 1] != '1' && ((player->x + CELL_SIZE)
	/ CELL_SIZE) > 0 && ((player->x + CELL_SIZE) / CELL_SIZE) <
	player->table_lenght && ((player->y - CELL_SIZE) / CELL_SIZE) > 1 &&
	((player->y - CELL_SIZE) / CELL_SIZE) < player->max)
		{
			player->x = player->x + CELL_SIZE;
			player->y = player->y - CELL_SIZE;
		}
	}
	else if (get_decimals(player->teta) == get_decimals((M_PI / 4) * 3))
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
}

void	walk_right_teta_pos(t_player *player)
{
	if (get_decimals(player->teta) == get_decimals(M_PI / 4) ||
	get_decimals(player->teta) == get_decimals((M_PI / 4) * 3))
		walk_right_teta_pos_diag(player);
	else
	{
		if (player->teta >= 0 && player->teta < M_PI / 4)
			player->x = (player->map[(int)((player->x + CELL_SIZE) /
			CELL_SIZE) - 1][(int)(player->y / CELL_SIZE) - 1] != '1' &&
			(int)((player->x + CELL_SIZE) / CELL_SIZE) > 1 &&
			(int)((player->x + CELL_SIZE) / CELL_SIZE) <
			player->table_lenght) ? player->x + CELL_SIZE : player->x;
		else if (player->teta > M_PI / 4 && player->teta < (M_PI / 4) * 3)
			player->y = (player->map[(int)(player->x / CELL_SIZE) - 1]
			[(int)((player->y - CELL_SIZE) / CELL_SIZE) - 1] != '1' &&
			(int)((player->y - CELL_SIZE) / CELL_SIZE) > 1 &&
			(int)((player->y - CELL_SIZE) / CELL_SIZE) < player->max) ?
			player->y - CELL_SIZE : player->y;
		else
			player->x = (player->map[(int)((player->x - CELL_SIZE) /
			CELL_SIZE) - 1][(int)(player->y / CELL_SIZE) - 1] != '1' &&
			(int)((player->x - CELL_SIZE) / CELL_SIZE) > 1 &&
			(int)((player->x - CELL_SIZE) / CELL_SIZE) <
			player->table_lenght) ? player->x - CELL_SIZE : player->x;
	}
}

void	walk_right_teta_neg_diag(t_player *player)
{
	if (get_decimals(player->teta) == get_decimals(-M_PI / 4))
	{
		if (player->map[(int)((player->x + CELL_SIZE) / CELL_SIZE) - 1][(int)((
	player->y + CELL_SIZE) / CELL_SIZE) - 1] != '1' && (int)((player->x +
	CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->x + CELL_SIZE) / CELL_SIZE)
	< player->table_lenght && (int)((player->y + CELL_SIZE) / CELL_SIZE) > 1
	&& (int)((player->y + CELL_SIZE) / CELL_SIZE) < player->max)
		{
			player->x = player->x + CELL_SIZE;
			player->y = player->y + CELL_SIZE;
		}
	}
	else if (get_decimals(player->teta) == get_decimals(-(M_PI / 4) * 3))
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
}

void	walk_right_teta_neg(t_player *player)
{
	if (get_decimals(player->teta) == get_decimals(-M_PI / 4) ||
	get_decimals(player->teta) == get_decimals(-(M_PI / 4) * 3))
		walk_right_teta_neg_diag(player);
	else
	{
		if (player->teta >= -M_PI && player->teta < -M_PI / 1.25)
			player->x = (player->map[(int)((player->x - CELL_SIZE) / CELL_SIZE)
			- 1][(int)(player->y / CELL_SIZE) - 1] != '1' && (int)((player->x
			- CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->x - CELL_SIZE) /
			CELL_SIZE) < player->table_lenght) ? player->x - CELL_SIZE :
			player->x;
		else if (player->teta > ((-M_PI / 4) * 3) && player->teta < -M_PI / 4)
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
