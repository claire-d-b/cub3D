/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsraycast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clde-ber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 11:44:05 by clde-ber          #+#    #+#             */
/*   Updated: 2020/08/14 14:16:34 by clde-ber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void register_coordinates(t_player *player, double x, double y)
{
	player->struct_side.he = x;
	player->struct_side.wi = y;
}

void check_side_south(t_player *player)
{
	init_struct_side(player);
	player->struct_side.south = 1;
}

void check_side_north(t_player *player)
{
	init_struct_side(player);
	player->struct_side.north = 1;
}

void check_side_east(t_player *player)
{
	init_struct_side(player);
	player->struct_side.east = 1;
}

void check_side_west(t_player *player)
{
	init_struct_side(player);
	player->struct_side.west = 1;
}

void define_heightawidth(t_player *player, float d, float angle)
{
	player->struct_side.he = (player->ray_x + ((d - (2 * EPSILON)) * sin(angle)));
	player->struct_side.wi = (player->ray_y + ((d - (2 * EPSILON)) * cos(angle)));
	//	player->distance = (player->boolean == 0) ? player->struct_screen.y / d : player->distance;
	player->distance = player->struct_screen.y / (d - (2 * EPSILON));
}
