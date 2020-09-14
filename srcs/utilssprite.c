/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilssprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clde-ber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 12:11:42 by clde-ber          #+#    #+#             */
/*   Updated: 2020/08/28 10:30:04 by clde-ber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	register_dist_minmax(t_player *player, float d, float angle, int i)
{
	if (((player->struct_screen.x) / (d * cos(fabs(angle - player->teta)))) >
	player->sprite[i][2] || player->sprite[i][2] == 0)
		player->sprite[i][2] = ((player->struct_screen.x) / (d * cos(fabs(angle
		- player->teta))));
	if (((player->struct_screen.x) / (d * cos(fabs(angle - player->teta))) > player->sprite[i][9] ||
	player->sprite[i][9] == 0))
		player->sprite[i][9] = (player->struct_screen.x) / (d * cos(fabs(angle - player->teta)));
	if ((player->struct_screen.x) / (d * cos(fabs(angle - player->teta))) <
	player->sprite[i][6] || player->sprite[i][6] == 0)
		player->sprite[i][6] = (player->struct_screen.x) / (d * cos(fabs(angle
		- player->teta)));
}

int		is_sprite(float *sprite)
{
	int i;

	i = 0;
	if (sprite)
	{
		while (i < 11 && sprite[i] == 0)
			i++;
		return (i == 11) ? 0 : 1;
	}
	else
		return (0);
}

void	delete_sprites(t_player *player)
{
	if (player->map[(int)((player->x - CELL_SIZE) / CELL_SIZE)]
	[(int)((player->y - CELL_SIZE) / CELL_SIZE)] == '2')
		player->map[(int)((player->x - CELL_SIZE) / CELL_SIZE)]
		[(int)((player->y - CELL_SIZE) / CELL_SIZE)] = '0';
	if (player->map[(int)((player->x - CELL_SIZE) / CELL_SIZE) + 1]
	[(int)((player->y - CELL_SIZE) / CELL_SIZE)] == '2')
		player->map[(int)((player->x - CELL_SIZE) / CELL_SIZE) + 1]
		[(int)((player->y - CELL_SIZE) / CELL_SIZE)] = '0';
	if (player->map[(int)((player->x - CELL_SIZE) / CELL_SIZE)]
	[(int)((player->y - CELL_SIZE) / CELL_SIZE) + 1] == '2')
		player->map[(int)((player->x - CELL_SIZE) / CELL_SIZE)]
		[(int)((player->y - CELL_SIZE) / CELL_SIZE) + 1] = '0';
	if (player->map[(int)((player->x - CELL_SIZE) / CELL_SIZE) - 1]
	[(int)((player->y - CELL_SIZE) / CELL_SIZE)] == '2')
		player->map[(int)((player->x - CELL_SIZE) / CELL_SIZE) - 1]
		[(int)((player->y - CELL_SIZE) / CELL_SIZE)] = '0';
	if (player->map[(int)((player->x - CELL_SIZE) / CELL_SIZE)]
	[(int)((player->y - CELL_SIZE) / CELL_SIZE) - 1] == '2')
		player->map[(int)((player->x - CELL_SIZE) / CELL_SIZE)]
		[(int)((player->y - CELL_SIZE) / CELL_SIZE) - 1] = '0';
}

void	sort_sprite(t_player *player)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (player->sprite[i])
	{
		while (player->sprite[j])
		{
			if (player->sprite[j][9] < player->sprite[i][9] &&
			player->sprite[i][9] && player->sprite[j][9])
				ft_swap(&player->sprite[i], &player->sprite[j]);
			j++;
		}
		i++;
		j = i + 1;
	}
}

void	define_heightawidth(t_player *player, float d, float angle)
{
	player->struct_side.he = (player->ray_x + ((d - (2 * EPSILON)) *
	sin(angle)));
	player->struct_side.wi = (player->ray_y + ((d - (2 * EPSILON)) *
	cos(angle)));
}
