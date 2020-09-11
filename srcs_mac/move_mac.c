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
	player->key_r = -1;
	if (keycode == RIGHT_ARROW)
		camera_right(player);
	if (keycode == LEFT_ARROW)
		camera_left(player);
	if (keycode == MOVE_UP)
		walk_up(player);
	if (keycode == MOVE_DOWN)
		walk_down(player);
	if (keycode == MOVE_RIGHT)
		walk_right(player);
	if (keycode == MOVE_LEFT)
		walk_left(player);
	if (keycode == ESCAPE)
		exit_game(player);
	else
	{
	//	delete_sprites(player);
		display_view(0, 0, 0, player);
	}
	return (0);
}

int		key_press(int keycode, t_player *player)
{
	if (player->key_r != -1)
	{
		if (keycode == RIGHT_ARROW)
			camera_right(player);
		if (keycode == LEFT_ARROW)
			camera_left(player);
		if (keycode == MOVE_UP)
			walk_up(player);
		if (keycode == MOVE_DOWN)
			walk_down(player);
		if (keycode == MOVE_RIGHT)
			walk_right(player);
		if (keycode == MOVE_LEFT)
			walk_left(player);
		if (keycode == ESCAPE)
			exit_game(player);
		else
		{
		//	delete_sprites(player);
			display_view(0, 0, 0, player);
		}
	}
	player->key_r = 0;
	return (0);
}
