/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawsprite.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clde-ber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 11:36:12 by clde-ber          #+#    #+#             */
/*   Updated: 2020/10/14 14:56:17 by clde-ber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		init_var_sprite_start(t_player *player, int wall_h2, int wall_h,
int count)
{
	if (player->sprite[count][7] == 0)
		return ((int)(player->sprite[count][3] - (wall_h2 / 2) -
		((wall_h - wall_h2)) / 2));
	else if (player->sprite[count][3] == player->struct_screen.x - 1)
		return ((int)(player->sprite[count][7] + (wall_h2 / 2) +
		((wall_h - wall_h2)) / 2));
	else
		return ((int)(player->sprite[count][7] + (wall_h2 / 2)));
}

int		init_var_sprite_end(t_player *player, int wall_h2, int wall_h,
int count)
{
	if (player->sprite[count][7] == 0)
		return ((int)(player->sprite[count][3] - (wall_h2 / 2) -
		((wall_h - wall_h2)) / 2));
	else if (player->sprite[count][3] == player->struct_screen.x - 1)
		return ((int)(player->sprite[count][7] + (wall_h2 / 2) +
		((wall_h - wall_h2)) / 2));
	else
		return ((int)(player->sprite[count][3] - (wall_h2 / 2)));
}

void	draw_sprite_from_start(t_player *player, int i, int j, int count)
{
	unsigned int	col;
	int				start;
	int				wall_h;
	int				wall_h2;

	col = 0;
	wall_h = (int)(player->sprite[count][2]);
	wall_h2 = (int)((player->sprite[count][2] + player->sprite[count][6]) / 2);
	start = init_var_sprite_start(player, wall_h2, wall_h, count);
	if (j <= wall_h2 && i <= wall_h2 / 2 && i >= 0 && j >= 0)
		col = set_texture_sprite(player, j * player->ids.xpm_sprite_h /
		wall_h2, (wall_h2 / 2 - i) * player->ids.xpm_sprite_w / wall_h2);
	if (col > 0 && start - i <= player->sprite[count][12] && start - i >= player
->sprite[count][13] && player->struct_screen.y / 2 - wall_h2 / 2 + j >= 0
	&& player->struct_screen.y / 2 - wall_h2 / 2 + j < player->struct_screen.y)
		change_color(player, player->struct_screen.y / 2 - wall_h2 / 2 + j,
		start - i, col);
	if (j <= wall_h2 && i <= wall_h2 / 2 && i >= 0 && j >= 0)
		col = set_texture_sprite(player, j * player->ids.xpm_sprite_h /
		wall_h2, (wall_h2 / 2 + i) * player->ids.xpm_sprite_w / wall_h2);
	if (col > 0 && start + i <= player->sprite[count][12] && start + i >= player
->sprite[count][13] && player->struct_screen.y / 2 - wall_h2 / 2 + j >= 0
	&& player->struct_screen.y / 2 - wall_h2 / 2 + j < player->struct_screen.y)
		change_color(player, player->struct_screen.y / 2 - wall_h2 / 2 + j,
		start + i, col);
}

void	draw_sprite_from_end(t_player *player, int i, int j, int count)
{
	unsigned int	col;
	int				end;
	int				wall_h;
	int				wall_h2;

	col = 0;
	wall_h = (int)(player->sprite[count][2]);
	wall_h2 = (int)((player->sprite[count][2] + player->sprite[count][6]) / 2);
	end = init_var_sprite_end(player, wall_h2, wall_h, count);
	if (j <= wall_h2 && i <= wall_h2 / 2 && i >= 0 && j >= 0)
		col = set_texture_sprite(player, j * player->ids.xpm_sprite_h /
		wall_h2, (wall_h2 / 2 - i) * player->ids.xpm_sprite_w / wall_h2);
	if (col > 0 && end - i <= player->sprite[count][12] && end - i >= player
->sprite[count][13] && player->struct_screen.y / 2 - wall_h2 / 2 + j >= 0
	&& player->struct_screen.y / 2 - wall_h2 / 2 + j < player->struct_screen.y)
		change_color(player, player->struct_screen.y / 2 - wall_h2 / 2 + j,
		end - i, col);
	if (j <= wall_h2 && i <= wall_h2 / 2 && i >= 0 && j >= 0)
		col = set_texture_sprite(player, j * player->ids.xpm_sprite_h /
		wall_h2, (wall_h2 / 2 + i) * player->ids.xpm_sprite_w / wall_h2);
	if (col > 0 && end + i <= player->sprite[count][12] && end + i >= player
->sprite[count][13] && player->struct_screen.y / 2 - wall_h2 / 2 + j >= 0
	&& player->struct_screen.y / 2 - wall_h2 / 2 + j < player->struct_screen.y)
		change_color(player, player->struct_screen.y / 2 - wall_h2 / 2 + j,
		end + i, col);
}

void	draw_sprite(t_player *player, int i, int j, int count)
{
	if ((int)player->sprite[count][14] - (int)player->sprite[count][15] >= 0)
		draw_sprite_from_start(player, i, j, count);
	else
		draw_sprite_from_end(player, i, j, count);
}
