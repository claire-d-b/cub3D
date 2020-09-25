/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clde-ber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 08:32:09 by clde-ber          #+#    #+#             */
/*   Updated: 2020/09/20 15:48:37 by clde-ber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_mac.h"

void	map_error(t_player *player, char **map, int i, int j)
{
	if (map[i][j] != '1' && map[i][j] != 'S' && map[i][j] != 'N'
	&& map[i][j] != 'E' && map[i][j] != 'W')
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
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != '2' &&
			map[i][j] != 'N' && map[i][j] != 'S' && map[i][j] != 'E' &&
			map[i][j] != 'W')
				map[i][j] = '1';
			if (j == player->max - 1 || j == 0 || i == 0 || i
			== player->table_lenght - 1)
				map_error(player, map, i, j);
		}
		j = -1;
	}
}

void	screen_size(t_player *player)
{
	if (player->struct_screen.x > 2560)
		player->struct_screen.x = 2560;
	if (player->struct_screen.y > 1440)
		player->struct_screen.y = 1440;
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
