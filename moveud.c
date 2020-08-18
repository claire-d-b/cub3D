/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moveud.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clde-ber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 08:29:21 by clde-ber          #+#    #+#             */
/*   Updated: 2020/08/18 12:18:21 by clde-ber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void walk_left_teta_pos(t_player *player) // GAUCHE
{
	printf("up");
	if (get_decimals(player->teta) == get_decimals(M_PI/4))
	{
		printf("a");
		printf("%c\n", player->map[(int)((player->x - CELL_SIZE)/ CELL_SIZE) - 1][(int)((player->y + CELL_SIZE) /
		CELL_SIZE) - 1]);
		if (player->map[(int)((player->x - CELL_SIZE)/ CELL_SIZE) - 1][(int)((player->y + CELL_SIZE) /
		CELL_SIZE) - 1] != '1' && (int)((player->x - CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->x - CELL_SIZE) /
		CELL_SIZE) < player->table_lenght && (int)((player->y + CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->y + CELL_SIZE) /
		CELL_SIZE) < player->max)
		{player->x = player->x - CELL_SIZE;
		player->y = player->y + CELL_SIZE;}
	/*	player->x = (player->map[(int)((player->x - CELL_SIZE)/ CELL_SIZE) - 1][(int)((player->y - CELL_SIZE) /
		CELL_SIZE) - 1] != '1' && (int)((player->x - CELL_SIZE) / CELL_SIZE) > 0 && (int)((player->x - CELL_SIZE) /
		CELL_SIZE) < player->table_lenght && (int)((player->y - CELL_SIZE) / CELL_SIZE) > 0 && (int)((player->y - CELL_SIZE) /
		CELL_SIZE) < player->max) ? player->x - CELL_SIZE : player->x;
		player->y = (player->map[(int)((player->x - CELL_SIZE)/ CELL_SIZE) - 1][(int)((player->y - CELL_SIZE) /
		CELL_SIZE) - 1] != '1' && (int)((player->x - CELL_SIZE) / CELL_SIZE) > 0 && (int)((player->x - CELL_SIZE) /
		CELL_SIZE) < player->table_lenght && (int)((player->y - CELL_SIZE) / CELL_SIZE) > 0 && (int)((player->y - CELL_SIZE) /
		CELL_SIZE) < player->max) ? player->y - CELL_SIZE : player->y;*/
	}
/*	else if (get_decimals(player->teta) == get_decimals((M_PI/4)*3))
	{
		if (player->map[(int)((player->x + CELL_SIZE)/ CELL_SIZE) - 1][(int)((player->y - CELL_SIZE) /
		CELL_SIZE) - 1] != '1' && (int)((player->x + CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->x + CELL_SIZE) /
		CELL_SIZE) < player->table_lenght && (int)((player->y - CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->y - CELL_SIZE) /
		CELL_SIZE) < player->max)
		player->x = player->x + CELL_SIZE;
		player->y = player->y - CELL_SIZE;
		player->x = (player->map[(int)((player->x + CELL_SIZE)/ CELL_SIZE) - 1][(int)((player->y - CELL_SIZE) /
		CELL_SIZE) - 1] != '1' && (int)((player->x + CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->x + CELL_SIZE) /
		CELL_SIZE) < player->table_lenght && (int)((player->y - CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->y - CELL_SIZE) /
		CELL_SIZE) < player->max) ? player->x + CELL_SIZE : player->x;
		player->y = (player->map[(int)((player->x + CELL_SIZE)/ CELL_SIZE) - 1][(int)((player->y - CELL_SIZE) /
		CELL_SIZE) - 1] != '1' && (int)((player->x + CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->x + CELL_SIZE) /
		CELL_SIZE) < player->table_lenght && (int)((player->y - CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->y - CELL_SIZE) /
		CELL_SIZE) < player->max) ? player->y - CELL_SIZE : player->y;
	}*/
	else if (get_decimals(player->teta) == get_decimals((M_PI/4)*3))
	{
		if (player->map[(int)((player->x + CELL_SIZE)/ CELL_SIZE) - 1][(int)((player->y + CELL_SIZE) /
		CELL_SIZE) - 1] != '1' && (int)((player->x + CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->x + CELL_SIZE) /
		CELL_SIZE) < player->table_lenght && (int)((player->y + CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->y + CELL_SIZE) /
		CELL_SIZE) < player->max)
		{player->x = player->x + CELL_SIZE;
		player->y = player->y + CELL_SIZE;}
	/*	player->x = (player->map[(int)((player->x + CELL_SIZE)/ CELL_SIZE) - 1][(int)((player->y - CELL_SIZE) /
		CELL_SIZE) - 1] != '1' && (int)((player->x + CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->x + CELL_SIZE) /
		CELL_SIZE) < player->table_lenght && (int)((player->y - CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->y - CELL_SIZE) /
		CELL_SIZE) < player->max) ? player->x + CELL_SIZE : player->x;
		player->y = (player->map[(int)((player->x + CELL_SIZE)/ CELL_SIZE) - 1][(int)((player->y - CELL_SIZE) /
		CELL_SIZE) - 1] != '1' && (int)((player->x + CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->x + CELL_SIZE) /
		CELL_SIZE) < player->table_lenght && (int)((player->y - CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->y - CELL_SIZE) /
		CELL_SIZE) < player->max) ? player->y - CELL_SIZE : player->y;*/
	}
else{
   if (player->teta >= 0 && player->teta < M_PI / 4)
    	player->x = (player->map[(int)((player->x - CELL_SIZE) / CELL_SIZE) - 1][(int)(player->y / 
		CELL_SIZE) - 1] != '1' && (int)((player->x - CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->x - CELL_SIZE) / 
		CELL_SIZE) < player->table_lenght) ? player->x - CELL_SIZE : player->x;
		else if (player->teta > M_PI / 4 && player->teta < (M_PI / 4) * 3)
			player->y = (player->map[(int)(player->x / CELL_SIZE) - 1][(int)((player->y + CELL_SIZE) / 
		CELL_SIZE) - 1] != '1' && (int)((player->y + CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->y + CELL_SIZE) / 
		CELL_SIZE) < player->max) ? player->y + CELL_SIZE : player->y;
		else
			player->x = (player->map[(int)((player->x + CELL_SIZE) / CELL_SIZE) - 1][(int)(player->y / 
		CELL_SIZE) - 1] != '1' && (int)((player->x + CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->x + CELL_SIZE) / 
		CELL_SIZE) < player->table_lenght) ? player->x + CELL_SIZE : player->x;}

}

void walk_left_teta_neg(t_player *player) //GAUCHE
{
if (get_decimals(player->teta) == get_decimals(-M_PI/4))
	{
		if (player->map[(int)((player->x - CELL_SIZE)/ CELL_SIZE) - 1][(int)((player->y - CELL_SIZE) /
		CELL_SIZE) - 1] != '1' && (int)((player->x - CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->x - CELL_SIZE) /
		CELL_SIZE) < player->table_lenght && (int)((player->y - CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->y - CELL_SIZE) /
		CELL_SIZE) < player->max)
		{player->x = player->x - CELL_SIZE;
		player->y = player->y - CELL_SIZE;}
		/*player->x = (player->map[(int)((player->x - CELL_SIZE)/ CELL_SIZE) - 1][(int)((player->y + CELL_SIZE) /
		CELL_SIZE) - 1] != '1' && (int)((player->x - CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->x - CELL_SIZE) /
		CELL_SIZE) < player->table_lenght && (int)((player->y + CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->y + CELL_SIZE) /
		CELL_SIZE) < player->max) ? player->x - CELL_SIZE : player->x;
		player->y = (player->map[(int)((player->x - CELL_SIZE)/ CELL_SIZE) - 1][(int)((player->y + CELL_SIZE) /
		CELL_SIZE) - 1] != '1' && (int)((player->x - CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->x - CELL_SIZE) /
		CELL_SIZE) < player->table_lenght && (int)((player->y + CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->y + CELL_SIZE) /
		CELL_SIZE) < player->max) ? player->y + CELL_SIZE : player->y;*/
	}
/*	else if (get_decimals(player->teta) == get_decimals(-(M_PI/4)*3))
	{
		if (player->map[(int)((player->x + CELL_SIZE)/ CELL_SIZE) - 1][(int)((player->y + CELL_SIZE) /
		CELL_SIZE) - 1] != '1' && (int)((player->x + CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->x + CELL_SIZE) /
		CELL_SIZE) < player->table_lenght && (int)((player->y + CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->y + CELL_SIZE) /
		CELL_SIZE) < player->max)
		player->x = player->x + CELL_SIZE;
		player->y = player->y + CELL_SIZE;
		player->x = (player->map[(int)((player->x + CELL_SIZE)/ CELL_SIZE) - 1][(int)((player->y + CELL_SIZE) /
		CELL_SIZE) - 1] != '1' && (int)((player->x + CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->x + CELL_SIZE) /
		CELL_SIZE) < player->table_lenght && (int)((player->y + CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->y + CELL_SIZE) /
		CELL_SIZE) < player->max) ? player->x + CELL_SIZE : player->x;
		player->y = (player->map[(int)((player->x + CELL_SIZE)/ CELL_SIZE) - 1][(int)((player->y + CELL_SIZE) /
		CELL_SIZE) - 1] != '1' && (int)((player->x + CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->x + CELL_SIZE) /
		CELL_SIZE) < player->table_lenght && (int)((player->y + CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->y + CELL_SIZE) /
		CELL_SIZE) < player->max) ? player->y + CELL_SIZE : player->y;*/
else if (get_decimals(player->teta) == get_decimals(-(M_PI/4)*3))
	{
		if (player->map[(int)((player->x + CELL_SIZE)/ CELL_SIZE) - 1][(int)((player->y - CELL_SIZE) /
		CELL_SIZE) - 1] != '1' && (int)((player->x + CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->x + CELL_SIZE) /
		CELL_SIZE) < player->table_lenght && (int)((player->y - CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->y - CELL_SIZE) /
		CELL_SIZE) < player->max)
		{player->x = player->x + CELL_SIZE;
		player->y = player->y - CELL_SIZE;}
	/*	player->x = (player->map[(int)((player->x - CELL_SIZE)/ CELL_SIZE) - 1][(int)((player->y - CELL_SIZE) /
		CELL_SIZE) - 1] != '1' && (int)((player->x - CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->x - CELL_SIZE) /
		CELL_SIZE) < player->table_lenght && (int)((player->y - CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->y - CELL_SIZE) /
		CELL_SIZE) < player->max) ? player->x - CELL_SIZE : player->x;
		player->y = (player->map[(int)((player->x - CELL_SIZE)/ CELL_SIZE) - 1][(int)((player->y - CELL_SIZE) /
		CELL_SIZE) - 1] != '1' && (int)((player->x - CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->x - CELL_SIZE) /
		CELL_SIZE) < player->table_lenght && (int)((player->y - CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->y - CELL_SIZE) /
		CELL_SIZE) < player->max) ? player->y - CELL_SIZE : player->y;*/
	}
else{
    if (player->teta >= -M_PI && player->teta < -M_PI / 1.25)
			player->x = (player->map[(int)((player->x + CELL_SIZE) / CELL_SIZE) - 1][(int)(player->y / 
		CELL_SIZE) - 1] != '1' && (int)((player->x + CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->x + CELL_SIZE) / 
		CELL_SIZE) < player->table_lenght) ? player->x + CELL_SIZE : player->x;
	else if (player->teta > (-(M_PI / 4) * 3) && player->teta < -M_PI / 4)
			 player->y = (player->map[(int)(player->x / CELL_SIZE) - 1][(int)((player->y - CELL_SIZE) / 
		CELL_SIZE) - 1] != '1' && (int)((player->y - CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->y - CELL_SIZE) / 
		CELL_SIZE) < player->max) ? player->y - CELL_SIZE : player->y;
	else
			player->x = (player->map[(int)((player->x - CELL_SIZE) / CELL_SIZE) - 1][(int)(player->y / 
		CELL_SIZE) - 1] != '1' && (int)((player->x - CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->x - CELL_SIZE) / 
		CELL_SIZE) < player->table_lenght) ? player->x - CELL_SIZE : player->x;}

}

void walk_right_teta_pos(t_player *player) //droite
{
	if (get_decimals(player->teta) == get_decimals(M_PI/4))
	{
		if (player->map[(int)((player->x + CELL_SIZE)/ CELL_SIZE) - 1][(int)((player->y - CELL_SIZE) /
		CELL_SIZE) - 1] != '1' && ((player->x + CELL_SIZE) / CELL_SIZE) > 0 && ((player->x + CELL_SIZE) /
		CELL_SIZE) < player->table_lenght && ((player->y - CELL_SIZE) / CELL_SIZE) > 1 && ((player->y - CELL_SIZE) /
		CELL_SIZE) < player->max)
		{player->x = player->x + CELL_SIZE;
		player->y = player->y - CELL_SIZE;}
		/*player->x = (player->map[(int)((player->x + CELL_SIZE)/ CELL_SIZE) - 1][(int)((player->y + CELL_SIZE) /
		CELL_SIZE) - 1] != '1' && ((player->x + CELL_SIZE) / CELL_SIZE) > 0 && ((player->x + CELL_SIZE) /
		CELL_SIZE) < player->table_lenght && ((player->y + CELL_SIZE) / CELL_SIZE) > 0 && ((player->y + CELL_SIZE) /
		CELL_SIZE) < player->max) ? player->x + CELL_SIZE : player->x;
		player->y = (player->map[(int)((player->x + CELL_SIZE)/ CELL_SIZE) - 1][(int)((player->y + CELL_SIZE) /
		CELL_SIZE) - 1] != '1' && ((player->x + CELL_SIZE) / CELL_SIZE) > 0 && ((player->x + CELL_SIZE) /
		CELL_SIZE) < player->table_lenght && ((player->y + CELL_SIZE) / CELL_SIZE) > 0 && ((player->y + CELL_SIZE) /
		CELL_SIZE) < player->max) ? player->y + CELL_SIZE : player->y;*/
	}
	/*else if (get_decimals(player->teta) == get_decimals((M_PI/4)*3))
	{
		if (player->map[(int)((player->x - CELL_SIZE) / CELL_SIZE) - 1][(int)((player->y + CELL_SIZE) /
		CELL_SIZE) - 1] != '1' && (int)((player->x - CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->x - CELL_SIZE) /
		CELL_SIZE) < player->table_lenght && (int)((player->y + CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->y + CELL_SIZE) /
		CELL_SIZE) < player->max)
		{player->x = player->x - CELL_SIZE;
		player->y = player->y + CELL_SIZE;}
		player->x = (player->map[(int)((player->x - CELL_SIZE) / CELL_SIZE) - 1][(int)((player->y + CELL_SIZE) /
		CELL_SIZE) - 1] != '1' && (int)((player->x - CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->x - CELL_SIZE) /
		CELL_SIZE) <= player->table_lenght && (int)((player->y + CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->y + CELL_SIZE) /
		CELL_SIZE) <= player->max) ? player->x - CELL_SIZE : player->x;
		player->y = (player->map[(int)((player->x - CELL_SIZE) / CELL_SIZE) - 1][(int)((player->y + CELL_SIZE) /
		CELL_SIZE) - 1] != '1' && (int)((player->x - CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->x - CELL_SIZE) /
		CELL_SIZE) <= player->table_lenght && (int)((player->y + CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->y + CELL_SIZE) /
		CELL_SIZE) <= player->max) ? player->y + CELL_SIZE : player->y;*/
else if (get_decimals(player->teta) == get_decimals((M_PI/4)*3))
	{
		if (player->map[(int)((player->x - CELL_SIZE) / CELL_SIZE) - 1][(int)((player->y - CELL_SIZE) /
		CELL_SIZE) - 1] != '1' && (int)((player->x - CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->x - CELL_SIZE) /
		CELL_SIZE) < player->table_lenght && (int)((player->y - CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->y - CELL_SIZE) /
		CELL_SIZE) < player->max)
		{player->x = player->x - CELL_SIZE;
		player->y = player->y - CELL_SIZE;}
		/*player->x = (player->map[(int)((player->x - CELL_SIZE) / CELL_SIZE) - 1][(int)((player->y + CELL_SIZE) /
		CELL_SIZE) - 1] != '1' && (int)((player->x - CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->x - CELL_SIZE) /
		CELL_SIZE) <= player->table_lenght && (int)((player->y + CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->y + CELL_SIZE) /
		CELL_SIZE) <= player->max) ? player->x - CELL_SIZE : player->x;
		player->y = (player->map[(int)((player->x - CELL_SIZE) / CELL_SIZE) - 1][(int)((player->y + CELL_SIZE) /
		CELL_SIZE) - 1] != '1' && (int)((player->x - CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->x - CELL_SIZE) /
		CELL_SIZE) <= player->table_lenght && (int)((player->y + CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->y + CELL_SIZE) /
		CELL_SIZE) <= player->max) ? player->y + CELL_SIZE : player->y;*/
	}

	else
		{
    if (player->teta >= 0 && player->teta < M_PI / 4)
    	player->x = (player->map[(int)((player->x + CELL_SIZE)/ CELL_SIZE) - 1][(int)(player->y / 
		CELL_SIZE) - 1] != '1' && (int)((player->x + CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->x + CELL_SIZE) / 
		CELL_SIZE) < player->table_lenght) ? player->x + CELL_SIZE : player->x;
	else if (player->teta > M_PI / 4 && player->teta < (M_PI / 4) * 3)
			player->y = (player->map[(int)(player->x / CELL_SIZE) - 1][(int)((player->y - CELL_SIZE) / 
		CELL_SIZE) - 1] != '1' && (int)((player->y - CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->y - CELL_SIZE) / 
		CELL_SIZE) < player->max) ? player->y - CELL_SIZE : player->y;
	else
			player->x = (player->map[(int)((player->x - CELL_SIZE) / CELL_SIZE) - 1][(int)(player->y / 
		CELL_SIZE) - 1] != '1' && (int)((player->x - CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->x - CELL_SIZE) / 
		CELL_SIZE) < player->table_lenght) ? player->x - CELL_SIZE : player->x;
		}


}

void walk_right_teta_neg(t_player *player)
{
	if (get_decimals(player->teta) == get_decimals(-M_PI/4))
	{
		if (player->map[(int)((player->x + CELL_SIZE)/ CELL_SIZE) - 1][(int)((player->y + CELL_SIZE) /
		CELL_SIZE) - 1] != '1' && (int)((player->x + CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->x + CELL_SIZE) /
		CELL_SIZE) < player->table_lenght && (int)((player->y + CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->y + CELL_SIZE) /
		CELL_SIZE) < player->max)
		{player->x = player->x + CELL_SIZE;
		player->y = player->y + CELL_SIZE;}
	/*	player->x = (player->map[(int)((player->x - CELL_SIZE)/ CELL_SIZE) - 1][(int)((player->y + CELL_SIZE) /
		CELL_SIZE) - 1] != '1' && (int)((player->x - CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->x - CELL_SIZE) /
		CELL_SIZE) < player->table_lenght && (int)((player->y + CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->y + CELL_SIZE) /
		CELL_SIZE) < player->max) ? player->x - CELL_SIZE : player->x;
		player->y = (player->map[(int)((player->x - CELL_SIZE)/ CELL_SIZE) - 1][(int)((player->y + CELL_SIZE) /
		CELL_SIZE) - 1] != '1' && (int)((player->x - CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->x - CELL_SIZE) /
		CELL_SIZE) < player->table_lenght && (int)((player->y + CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->y + CELL_SIZE) /
		CELL_SIZE) < player->max) ? player->y + CELL_SIZE : player->y;*/
	}
	else if (get_decimals(player->teta) == get_decimals(-(M_PI/4)*3))
	{
		if (player->map[(int)((player->x - CELL_SIZE)/ CELL_SIZE) - 1][(int)((player->y + CELL_SIZE) /
		CELL_SIZE) - 1] != '1' && (int)((player->x - CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->x - CELL_SIZE) /
		CELL_SIZE) < player->table_lenght && (int)((player->y + CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->y + CELL_SIZE) /
		CELL_SIZE) < player->max)
		{player->x = player->x - CELL_SIZE;
		player->y = player->y + CELL_SIZE;}
	/*	player->x = (player->map[(int)((player->x - CELL_SIZE)/ CELL_SIZE) - 1][(int)((player->y - CELL_SIZE) /
		CELL_SIZE) - 1] != '1' && (int)((player->x - CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->x - CELL_SIZE) /
		CELL_SIZE) < player->table_lenght && (int)((player->y - CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->y - CELL_SIZE) /
		CELL_SIZE) < player->max) ? player->x - CELL_SIZE : player->x;
		player->y = (player->map[(int)((player->x - CELL_SIZE)/ CELL_SIZE) - 1][(int)((player->y - CELL_SIZE) /
		CELL_SIZE) - 1] != '1' && (int)((player->x - CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->x - CELL_SIZE) /
		CELL_SIZE) < player->table_lenght && (int)((player->y - CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->y - CELL_SIZE) /
		CELL_SIZE) < player->max) ? player->y - CELL_SIZE : player->y;*/
	}

	else
		{
   if (player->teta >= -M_PI && player->teta < -M_PI / 1.25)
			player->x = (player->map[(int)((player->x - CELL_SIZE) / CELL_SIZE) - 1][(int)(player->y / 
		CELL_SIZE) - 1] != '1' && (int)((player->x - CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->x - CELL_SIZE) / 
		CELL_SIZE) < player->table_lenght) ? player->x - CELL_SIZE : player->x;
		
	else if (player->teta > ((-M_PI / 4)* 3) && player->teta < -M_PI / 4)
			player->y = (player->map[(int)(player->x / CELL_SIZE) - 1][(int)((player->y + CELL_SIZE) / 
		CELL_SIZE) - 1] != '1' && (int)((player->y + CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->y + CELL_SIZE) / 
		CELL_SIZE) < player->max) ? player->y + CELL_SIZE : player->y;
	else
			player->x = (player->map[(int)((player->x + CELL_SIZE) / CELL_SIZE) - 1][(int)(player->y / 
		CELL_SIZE) - 1] != '1' && (int)((player->x + CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->x + CELL_SIZE) / 
		CELL_SIZE) < player->table_lenght) ? player->x + CELL_SIZE : player->x;
		}

}
