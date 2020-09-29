/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clde-ber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 08:32:09 by clde-ber          #+#    #+#             */
/*   Updated: 2020/08/28 10:34:38 by clde-ber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		is_empty_line_count(char *line, int len)
{
	size_t i;
	size_t count;

	i = 0;
	count = 0;
	while (i < (size_t)len)
	{
		if (line[i] == ' ' || line[i] == '\t' || line[i] == '\n'
		|| line[i] == '\r' || line[i] == '\v' || line[i] == '\f')
			count++;
		i++;
	}
	if (i != count)
		return (0);
	return (1);
}

void	map_error(t_player *player, char **map, int i, int j)
{
	if (i && j && j < (int)ft_strlen(map[i]) &&
	((map[i - 1][j] != '1' && is_space(map[i - 1][j]) == 0) ||
	(map[i + 1] && map[i + 1][j] != '1' &&
	is_space(map[i + 1][j]) == 0) ||
	(map[i][j - 1] != '1' && is_space(map[i][j - 1]) == 0) ||
	(map[i][j + 1] != '1' && is_space(map[i][j + 1]) == 0)))
	{
		player->waste =
		write(1, "Error\nMap must be surrounded by walls.\n", 39);
		exit_program(player);
	}
}

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
			if (is_space(map[i][j]))
				map_error(player, map, i, j);
			else if ((i == 0 || i == player->table_lenght - 1 || j == 0)
			&& map[i][j] != '1')
			{
				player->waste = write(1,
				"Error.\nMap must be surrounded by walls.\n", 40);
				exit_program(player);
			}
		}
		j = -1;
	}
}

void	screen_size(t_player *player)
{
	int height;
	int width;

	height = 0;
	width = 0;
	mlx_get_screen_size(player->ids.mlx_ptr, &width,
	&height);
	if (player->struct_screen.x > width)
		player->struct_screen.x = width;
	if (player->struct_screen.y > height)
		player->struct_screen.y = height;
}

int		open_window(t_player *player, char const *title)
{
	screen_size(player);
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
