/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moverl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clde-ber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 08:28:53 by clde-ber          #+#    #+#             */
/*   Updated: 2020/08/18 12:17:27 by clde-ber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void walk_down_teta_pos(t_player *player) // down
{
printf("player->teta %f\n", player->teta);
printf("right");
printf("playerx %d\n", (int)((player->x - CELL_SIZE)/ CELL_SIZE) - 1);
printf("player->y %d\n", (int)((player->y - CELL_SIZE) / CELL_SIZE) - 1);

	if (get_decimals(player->teta) == get_decimals(M_PI/4))
	{
		printf("a");
		printf("%c\n", player->map[(int)((player->x - CELL_SIZE)/ CELL_SIZE) - 1][(int)((player->y - CELL_SIZE) / 
		CELL_SIZE) - 1]);
		if (player->map[(int)((player->x - CELL_SIZE)/ CELL_SIZE) - 1][(int)((player->y - CELL_SIZE) / 
		CELL_SIZE) - 1] != '1' && (int)((player->x - CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->x - CELL_SIZE) / 
		CELL_SIZE) < player->table_lenght && (int)((player->y - CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->y - CELL_SIZE) / 
		CELL_SIZE) < player->max)
		{player->x = player->x - CELL_SIZE;
		player->y = player->y - CELL_SIZE;}
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
		if (player->map[(int)((player->x - CELL_SIZE) / CELL_SIZE) - 1][(int)((player->y + CELL_SIZE) / 
		CELL_SIZE) - 1] != '1' && (int)((player->x - CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->x - CELL_SIZE) / 
		CELL_SIZE) < player->table_lenght && (int)((player->y + CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->y + CELL_SIZE) / 
		CELL_SIZE) < player->max)
		{player->x = player->x - CELL_SIZE;
		player->y = player->y + CELL_SIZE;}
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
    		player->y = (player->map[(int)(player->x / CELL_SIZE) - 1][(int)((player->y - CELL_SIZE) / 
			CELL_SIZE) - 1] != '1' && (int)((player->y - CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->y - CELL_SIZE) / 
			CELL_SIZE) < player->max) ? player->y - CELL_SIZE : player->y;
		else if (player->teta > M_PI / 4 && player->teta < (M_PI / 4) * 3)
			player->x = (player->map[(int)((player->x - CELL_SIZE) / CELL_SIZE) - 1][(int)(player->y / 
			CELL_SIZE) - 1] != '1' && (int)((player->x - CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->x - CELL_SIZE) / 
			CELL_SIZE) < player->table_lenght) ? player->x - CELL_SIZE : player->x;
		else
			player->y = (player->map[(int)(player->x / CELL_SIZE) - 1][(int)((player->y + CELL_SIZE) / 
			CELL_SIZE) - 1] != '1' && (int)((player->y + CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->y + CELL_SIZE) / 
			CELL_SIZE) < player->max) ? player->y + CELL_SIZE : player->y;
	}
}

void walk_up_teta_neg(t_player *player)
{
//printf("player->teta %f\n", player->teta);i
printf("right neg");
	if (get_decimals(player->teta) == get_decimals(-M_PI/4))
	{
		if (player->map[(int)((player->x - CELL_SIZE)/ CELL_SIZE) - 1][(int)((player->y + CELL_SIZE) / 
		CELL_SIZE) - 1] != '1' && (int)((player->x - CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->x - CELL_SIZE) / 
		CELL_SIZE) < player->table_lenght && (int)((player->y + CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->y + CELL_SIZE) / 
		CELL_SIZE) < player->max)
		{player->x = player->x - CELL_SIZE;
		player->y = player->y + CELL_SIZE;}
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
		if (player->map[(int)((player->x - CELL_SIZE)/ CELL_SIZE) - 1][(int)((player->y - CELL_SIZE) / 
		CELL_SIZE) - 1] != '1' && (int)((player->x - CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->x - CELL_SIZE) / 
		CELL_SIZE) < player->table_lenght && (int)((player->y - CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->y - CELL_SIZE) / 
		CELL_SIZE) < player->max)
		{player->x = player->x - CELL_SIZE;
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
		else
	{
		if (player->teta >= -M_PI && player->teta < -(M_PI / 4) * 3)
			player->y = (player->map[(int)(player->x / CELL_SIZE) - 1][(int)((player->y - CELL_SIZE) / 
			CELL_SIZE) - 1] != '1' && (int)((player->y - CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->y - CELL_SIZE) / 
			CELL_SIZE) < player->max) ? player->y - CELL_SIZE : player->y;
		else if (player->teta > (-(M_PI / 4) * 3) && player->teta < -M_PI / 4)
			player->x = (player->map[(int)((player->x - CELL_SIZE) / CELL_SIZE) - 1][(int)(player->y / 
			CELL_SIZE) - 1] != '1' && (int)((player->x - CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->x - CELL_SIZE) / 
			CELL_SIZE) < player->table_lenght) ? player->x - CELL_SIZE : player->x;
		else
			player->y = (player->map[(int)(player->x / CELL_SIZE) - 1][(int)((player->y + CELL_SIZE) / 
			CELL_SIZE) - 1] != '1' && (int)((player->y + CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->y + CELL_SIZE) / 
			CELL_SIZE) < player->max) ? player->y + CELL_SIZE : player->y;
	}
}

void walk_up_teta_pos(t_player *player) //up
{
	printf("player->teta %f\n", player->teta);
	printf("left");
	if (get_decimals(player->teta) == get_decimals(M_PI/4))
	{
		if (player->map[(int)((player->x + CELL_SIZE)/ CELL_SIZE) - 1][(int)((player->y + CELL_SIZE) / 
		CELL_SIZE) - 1] != '1' && ((player->x + CELL_SIZE) / CELL_SIZE) > 0 && ((player->x + CELL_SIZE) / 
		CELL_SIZE) < player->table_lenght && ((player->y + CELL_SIZE) / CELL_SIZE) > 1 && ((player->y + CELL_SIZE) / 
		CELL_SIZE) < player->max)
		{player->x = player->x + CELL_SIZE;
		player->y = player->y + CELL_SIZE;}
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
		if (player->map[(int)((player->x + CELL_SIZE)/ CELL_SIZE) - 1][(int)((player->y - CELL_SIZE) / 
		CELL_SIZE) - 1] != '1' && (int)((player->x + CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->x + CELL_SIZE) / 
		CELL_SIZE) < player->table_lenght && (int)((player->y - CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->y - CELL_SIZE) / 
		CELL_SIZE) < player->max)
		{player->x = player->x + CELL_SIZE;
		player->y = player->y - CELL_SIZE;}
	/*	player->x = (player->map[(int)((player->x + CELL_SIZE)/ CELL_SIZE) - 1][(int)((player->y - CELL_SIZE) / 
		CELL_SIZE) - 1] != '1' && (int)((player->x + CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->x + CELL_SIZE) / 
		CELL_SIZE) < player->table_lenght && (int)((player->y - CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->y - CELL_SIZE) / 
		CELL_SIZE) < player->max) ? player->x + CELL_SIZE : player->x;
		player->y = (player->map[(int)((player->x + CELL_SIZE)/ CELL_SIZE) - 1][(int)((player->y - CELL_SIZE) / 
		CELL_SIZE) - 1] != '1' && (int)((player->x + CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->x + CELL_SIZE) / 
		CELL_SIZE) < player->table_lenght && (int)((player->y - CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->y - CELL_SIZE) / 
		CELL_SIZE) < player->max) ? player->y - CELL_SIZE : player->y;*/
	}
	else
	{
    	if (player->teta >= 0 && player->teta < M_PI / 4)
    		player->y = (player->map[(int)(player->x / CELL_SIZE) - 1][(int)((player->y + CELL_SIZE) / 
			CELL_SIZE) - 1] != '1' && (int)((player->y + CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->y + CELL_SIZE) / 
			CELL_SIZE) < player->max) ? player->y + CELL_SIZE : player->y;
		else if (player->teta > M_PI / 4 && player->teta < (M_PI / 4) * 3)
				player->x = (player->map[(int)((player->x + CELL_SIZE) / CELL_SIZE) - 1][(int)(player->y 
				 / CELL_SIZE) - 1] != '1' && (int)((player->x + CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->x + 
			 	CELL_SIZE) / CELL_SIZE) < player->table_lenght) ? player->x + CELL_SIZE : player->x;
		else
			player->y = (player->map[(int)(player->x / CELL_SIZE) - 1][(int)((player->y - CELL_SIZE) / 
			CELL_SIZE) - 1] != '1' && (int)((player->y - CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->y - CELL_SIZE) /
			CELL_SIZE) < player->max) ? player->y - CELL_SIZE : player->y;
	}
}

void walk_down_teta_neg(t_player *player)
{
	printf("player->teta %f\n", player->teta);
	printf("left neg");
	if (get_decimals(player->teta) == get_decimals(-M_PI/4))
	{
		if (player->map[(int)((player->x + CELL_SIZE)/ CELL_SIZE) - 1][(int)((player->y - CELL_SIZE) / 
		CELL_SIZE) - 1] != '1' && (int)((player->x + CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->x + CELL_SIZE) / 
		CELL_SIZE) < player->table_lenght && (int)((player->y - CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->y - CELL_SIZE) / 
		CELL_SIZE) < player->max)
		{player->x = player->x + CELL_SIZE;
		player->y = player->y - CELL_SIZE;}
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
		if (player->map[(int)((player->x + CELL_SIZE)/ CELL_SIZE) - 1][(int)((player->y + CELL_SIZE) / 
		CELL_SIZE) - 1] != '1' && (int)((player->x + CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->x + CELL_SIZE) / 
		CELL_SIZE) < player->table_lenght && (int)((player->y + CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->y + CELL_SIZE) / 
		CELL_SIZE) < player->max)
		{player->x = player->x + CELL_SIZE;
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
	else
	{
    	if (player->teta >= -M_PI && player->teta < -(M_PI / 4) * 3)
			player->y = (player->map[(int)(player->x / CELL_SIZE) - 1][(int)((player->y + CELL_SIZE) / 
			CELL_SIZE) - 1] != '1' && (int)((player->y + CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->y + CELL_SIZE) / 
			CELL_SIZE) < player->max) ? player->y + CELL_SIZE : player->y;
		else if (player->teta > (-(M_PI / 4) * 3) && player->teta < -M_PI / 4)
			 player->x = (player->map[(int)((player->x + CELL_SIZE) / CELL_SIZE) - 1][(int)(player->y / 
			CELL_SIZE) - 1] != '1' && (int)((player->x + CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->x + CELL_SIZE) / 
			CELL_SIZE) < player->table_lenght) ? player->x + CELL_SIZE : player->x;
		else
			player->y = (player->map[(int)(player->x / CELL_SIZE) - 1][(int)((player->y - CELL_SIZE) / 
			CELL_SIZE) - 1] != '1' && (int)((player->y - CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->y - CELL_SIZE) / 
			CELL_SIZE) < player->max) ? player->y - CELL_SIZE : player->y;
	}
}
