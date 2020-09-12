/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsraycast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clde-ber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 11:44:05 by clde-ber          #+#    #+#             */
/*   Updated: 2020/08/20 13:09:33 by clde-ber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//void	register_coordinates(t_player *player, double x, double y)
//{
//	player->struct_side.he = x;
//	player->struct_side.wi = y;
//}

void	check_side_south(t_player *player)
{
	init_struct_side(player);
	player->struct_side.south = 1;
}

void	check_side_north(t_player *player)
{
	init_struct_side(player);
	player->struct_side.north = 1;
}

void	check_side_east(t_player *player)
{
	init_struct_side(player);
	player->struct_side.east = 1;
}

void	check_side_west(t_player *player)
{
	init_struct_side(player);
	player->struct_side.west = 1;
}

void	check_side_south_s(t_player *player)
{
//	init_struct_side_s(player);
	player->struct_side.south_s = player->struct_screen.i;
}

void	check_side_north_s(t_player *player)
{
//	init_struct_side_s(player);
	player->struct_side.north_s = player->struct_screen.i;
}

void	check_side_east_s(t_player *player)
{
//	init_struct_side_s(player);
	player->struct_side.east_s = player->struct_screen.i;
}

void	check_side_west_s(t_player *player)
{
//	init_struct_side_s(player);
	player->struct_side.west_s = player->struct_screen.i;
}
