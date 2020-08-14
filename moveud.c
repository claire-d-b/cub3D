/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moveud.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clde-ber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 08:29:21 by clde-ber          #+#    #+#             */
/*   Updated: 2020/08/14 11:40:03 by clde-ber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void walk_up_teta_pos(t_player *player)
{
    if (player->teta >= 0 && player->teta < M_PI / 4)
    	player->x = (player->map[(int)((player->x + CELL_SIZE)/ CELL_SIZE) - 1][(int)(player->y / 
		CELL_SIZE) - 1] != '1' && (int)((player->x + CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->x + CELL_SIZE) / 
		CELL_SIZE) < player->table_lenght) ? player->x + CELL_SIZE : player->x;
	else if (player->teta >= M_PI / 4 && player->teta < M_PI / 1.25)
			player->y = (player->map[(int)(player->x / CELL_SIZE) - 1][(int)((player->y - CELL_SIZE) / 
		CELL_SIZE) - 1] != '1' && (int)((player->y - CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->y - CELL_SIZE) / 
		CELL_SIZE) < player->max) ? player->y - CELL_SIZE : player->y;
	else
			player->x = (player->map[(int)((player->x - CELL_SIZE) / CELL_SIZE) - 1][(int)(player->y / 
		CELL_SIZE) - 1] != '1' && (int)((player->x - CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->x - CELL_SIZE) / 
		CELL_SIZE) < player->table_lenght) ? player->x - CELL_SIZE : player->x;
}

void walk_up_teta_neg(t_player *player)
{
   if (player->teta >= -M_PI && player->teta < -M_PI / 1.25)
			player->x = (player->map[(int)((player->x - CELL_SIZE) / CELL_SIZE) - 1][(int)(player->y / 
		CELL_SIZE) - 1] != '1' && (int)((player->x - CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->x - CELL_SIZE) / 
		CELL_SIZE) < player->table_lenght) ? player->x - CELL_SIZE : player->x;
		
	else if (player->teta >= (-M_PI / 1.25) && player->teta < -M_PI / 4)
			player->y = (player->map[(int)(player->x / CELL_SIZE) - 1][(int)((player->y + CELL_SIZE) / 
		CELL_SIZE) - 1] != '1' && (int)((player->y + CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->y + CELL_SIZE) / 
		CELL_SIZE) < player->max) ? player->y + CELL_SIZE : player->y;
	else
			player->x = (player->map[(int)((player->x + CELL_SIZE) / CELL_SIZE) - 1][(int)(player->y / 
		CELL_SIZE) - 1] != '1' && (int)((player->x + CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->x + CELL_SIZE) / 
		CELL_SIZE) < player->table_lenght) ? player->x + CELL_SIZE : player->x;
}

void walk_down_teta_pos(t_player *player)
{
   if (player->teta >= 0 && player->teta < M_PI / 4)
    	player->x = (player->map[(int)((player->x - CELL_SIZE) / CELL_SIZE) - 1][(int)(player->y / 
		CELL_SIZE) - 1] != '1' && (int)((player->x - CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->x - CELL_SIZE) / 
		CELL_SIZE) < player->table_lenght) ? player->x - CELL_SIZE : player->x;
		else if (player->teta >= M_PI / 4 && player->teta < M_PI / 1.25)
			player->y = (player->map[(int)(player->x / CELL_SIZE) - 1][(int)((player->y + CELL_SIZE) / 
		CELL_SIZE) - 1] != '1' && (int)((player->y + CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->y + CELL_SIZE) / 
		CELL_SIZE) < player->max) ? player->y + CELL_SIZE : player->y;
		else
			player->x = (player->map[(int)((player->x + CELL_SIZE) / CELL_SIZE) - 1][(int)(player->y / 
		CELL_SIZE) - 1] != '1' && (int)((player->x + CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->x + CELL_SIZE) / 
		CELL_SIZE) < player->table_lenght) ? player->x + CELL_SIZE : player->x;
}

void walk_down_teta_neg(t_player *player)
{
    if (player->teta >= -M_PI && player->teta < -M_PI / 1.25)
			player->x = (player->map[(int)((player->x + CELL_SIZE) / CELL_SIZE) - 1][(int)(player->y / 
		CELL_SIZE) - 1] != '1' && (int)((player->x + CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->x + CELL_SIZE) / 
		CELL_SIZE) < player->table_lenght) ? player->x + CELL_SIZE : player->x;
	else if (player->teta >= (-M_PI / 1.25) && player->teta < -M_PI / 4)
			 player->y = (player->map[(int)(player->x / CELL_SIZE) - 1][(int)((player->y - CELL_SIZE) / 
		CELL_SIZE) - 1] != '1' && (int)((player->y - CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->y - CELL_SIZE) / 
		CELL_SIZE) < player->max) ? player->y - CELL_SIZE : player->y;
	else
			player->x = (player->map[(int)((player->x - CELL_SIZE) / CELL_SIZE) - 1][(int)(player->y / 
		CELL_SIZE) - 1] != '1' && (int)((player->x - CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->x - CELL_SIZE) / 
		CELL_SIZE) < player->table_lenght) ? player->x - CELL_SIZE : player->x;
}
