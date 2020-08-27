/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clde-ber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 08:32:09 by clde-ber          #+#    #+#             */
/*   Updated: 2020/08/20 14:42:30 by clde-ber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parse_map(char **map, t_player *player)
{
	int i;
	int j;

	i = -1;
	j = -1;
	while (map[++i])
	{
		while (map[i][++j])
		{
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != '2' &&
			map[i][j] != 'N' && map[i][j] != 'S' && map[i][j] != 'E' &&
			map[i][j] != 'W')
				map[i][j] = '1';
			if (j == player->max - 1 || j == 0 || i == 0 || i
			== player->table_lenght - 1)
			{
				if (map[i][j] != '1')
					map[i][j] = '1';
			}
		}
		j = -1;
	}
}

int		player_placement_error(int i, int j, t_player *player)
{
	if (i == 0 || i == player->table_lenght - 1 || j == 0 ||
	j == player->max - 1)
	{
		player->save = write(1, "Wrong player placement.\n", 24);
		return (-1);
	}
	return (1);
}

void	player_coord(int *count, t_player *player, int i, int j)
{
	player->map[i][j] = '0';
	*count += 1;
	player->x = (i + 1) * CELL_SIZE + (CELL_SIZE / 2);
	player->y = (j + 1) * CELL_SIZE + (CELL_SIZE / 2);
}

int		place_player(int i, int j, int count, t_player *player)
{
	while (++i < player->table_lenght)
	{
		while (++j < player->max)
		{
			if (player->map[i][j] == 'N' || player->map[i][j] == 'S' ||
			player->map[i][j] == 'E' || player->map[i][j] == 'W')
			{
				player_placement_error(i, j, player);
				if (i != 0 && i != player->table_lenght - 1 && j != 0 &&
				j != player->max - 1)
				{
					if (player->map[i][j] == 'N' || player->map[i][j] == 'S')
						player->teta = (player->map[i][j] == 'N') ? VIEW_ANGLE :
						-VIEW_ANGLE;
					if (player->map[i][j] == 'W' || player->map[i][j] == 'E')
						player->teta = (player->map[i][j] == 'W') ? 0 :
						VIEW_ANGLE * 2;
					player_coord(&count, player, i, j);
				}
			}
		}
		j = -1;
	}
	player->waste = (count != 1) ? player->save = write(1, "Error\nPlayer nb.\n", 16) : 0;
	return (count == 1) ? 1 : -1;
}

int		open_window(int count, int j, t_player *player, char const *title)
{
	int height;
	int width;

	height = 0;
	width = 0;
	if (!(player->sprite = malloc(sizeof(float *) * (player->max *
	player->table_lenght + 1))))
		return (0);
	while (++count < player->max * player->table_lenght)
	{
		if (!(player->sprite[count] = malloc(sizeof(float) * 11)))
			return (0);
		while (++j < 10)
			player->sprite[count][j] = 0;
	}
	player->sprite[count] = NULL;
	mlx_get_screen_size(player->ids.mlx_ptr, &width,
	&height);
	if (player->struct_screen.x > width)
		player->struct_screen.x = width;
	if (player->struct_screen.y > height)
		player->struct_screen.y = height;
	player->ids.mlx_win = mlx_new_window(player->ids.mlx_ptr,
	player->struct_screen.x, player->struct_screen.y, (char *)title);
	player->ids.img_ptr = mlx_new_image(player->ids.mlx_ptr,
	player->struct_screen.x, player->struct_screen.y);
	player->ids.img_data = mlx_get_data_addr(player->ids.img_ptr,
	&player->ids.img_bpp, &player->ids.img_size_line, &player->ids.img_endian);
	xpm_images(player);
	xpm_image_sprite(player);
	mlx_put_image_to_window(player->ids.mlx_ptr, player->ids.mlx_win,
	player->ids.img_ptr, 0, 0);
	return (1);
}
