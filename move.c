/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clde-ber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 11:22:57 by clde-ber          #+#    #+#             */
/*   Updated: 2020/08/20 12:05:35 by clde-ber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	walk_up(t_player *player)
{
	if (player->teta >= 0 || (int)player->teta == (int)-M_PI)
		walk_up_teta_pos(player);
	else
		walk_up_teta_neg(player);
}

void	walk_down(t_player *player)
{
	if (player->teta >= 0 || (int)player->teta == (int)-M_PI)
		walk_down_teta_pos(player);
	else
		walk_down_teta_neg(player);
}

void	walk_right(t_player *player)
{
	if (player->teta >= 0 || (int)player->teta == (int)-M_PI)
		walk_right_teta_pos(player);
	else
		walk_right_teta_neg(player);
}

void	walk_left(t_player *player)
{
	if (player->teta >= 0 || (int)player->teta == (int)-M_PI)
		walk_left_teta_pos(player);
	else
		walk_left_teta_neg(player);
}

int		key_press(int keycode, t_player *player)
{
	if (keycode == right_arrow)
		camera_right(player);
	if (keycode == left_arrow)
		camera_left(player);
	if (keycode == move_up)
		walk_up(player);
	if (keycode == move_down)
		walk_down(player);
	if (keycode == move_right)
		walk_left(player);
	if (keycode == move_left)
		walk_right(player);
	if (keycode == escape)
	{
		mlx_clear_window(player->ids.mlx_ptr, player->ids.mlx_win);
		mlx_destroy_window(player->ids.mlx_ptr, player->ids.mlx_win);
		exit_game(player);
	}
	else
	{
		delete_sprites(player);
		display_view(0, 0, 0, player);
	}
	return (0);
}
