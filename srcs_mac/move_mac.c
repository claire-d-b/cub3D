/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clde-ber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 11:22:57 by clde-ber          #+#    #+#             */
/*   Updated: 2020/09/11 16:00:03 by clde-ber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_mac.h"

int		key_release(int keycode, t_player *player)
{
	if (keycode == RIGHT_ARROW)
		player->camera_right = 0;
	if (keycode == LEFT_ARROW)
		player->camera_left = 0;
	if (keycode == MOVE_UP)
		player->walk_up = 0;
	if (keycode == MOVE_DOWN)
		player->walk_down = 0;
	if (keycode == MOVE_RIGHT)
		player->walk_right = 0;
	if (keycode == MOVE_LEFT)
		player->walk_left = 0;
	if (keycode == ESCAPE)
		exit_game(player);
	return (0);
}

int		key_press(int keycode, t_player *player)
{
		if (keycode == RIGHT_ARROW)
			player->camera_right = 1;
		if (keycode == LEFT_ARROW)
			player->camera_left = 1;
		if (keycode == MOVE_UP)
			player->walk_up = 1;
		if (keycode == MOVE_DOWN)
			player->walk_down = 1;
		if (keycode == MOVE_RIGHT)
			player->walk_right = 1;
		if (keycode == MOVE_LEFT)
			player->walk_left = 1;
		if (keycode == ESCAPE)
			exit_game(player);
	return (0);
}

int		moves(t_player *player)
{
	if (player->walk_up == 1)
		walk_up(player);
	if (player->walk_down == 1)
		walk_down(player);
	if (player->walk_right == 1)
		walk_right(player);
	if (player->walk_left == 1)
		walk_left(player);
	if (player->camera_right == 1)
		camera_right(player);
	if (player->camera_left == 1)
		camera_left(player);
	display_view(0, 0, 0, player);
	return (0);
}
