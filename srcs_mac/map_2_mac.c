/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_2_mac.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clde-ber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 14:39:00 by clde-ber          #+#    #+#             */
/*   Updated: 2020/10/14 12:43:04 by clde-ber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_mac.h"

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
	if (i && j &&
	((j < (int)ft_strlen(map[i - 1]) && map[i - 1][j] != '1' &&
	is_space(map[i - 1][j]) == 0 && is_empty_line(map[i - 1]) == 0) ||
	(map[i + 1] && j < (int)ft_strlen(map[i + 1]) && map[i + 1][j] != '1' &&
	is_space(map[i + 1][j]) == 0 && is_empty_line(map[i + 1]) == 0) ||
	(j < (int)ft_strlen(map[i]) && map[i][j - 1] != '1' &&
	is_space(map[i][j - 1]) == 0) || (j < (int)ft_strlen(map[i]) &&
	map[i][j + 1] != '1' && is_space(map[i][j + 1]) == 0)))
	{
		player->waste =
		write(1, "Error\nMap must be surrounded by walls.\n", 39);
		exit_program(player, map);
	}
}

int		check_walls(int x, int i, char **map, t_player *player)
{
	int j;

	j = 0;
	if (i && i < player->table_lenght)
	{
		while (i - x >= 0 && is_empty_line(map[i - x]))
			x++;
		while (j < (int)ft_strlen(map[i - x]))
		{
			if (map[i - x][j] != '1' && is_space(map[i - x][j]) == 0)
				return (1);
			j++;
		}
		x = 1;
		j = 0;
		while (i + x < player->table_lenght && is_empty_line(map[i + x]))
			x++;
		while (j < (int)ft_strlen(map[i + x]))
		{
			if (map[i + x][j] != '1' && is_space(map[i + x][j]) == 0)
				return (1);
			j++;
		}
	}
	return (0);
}

void	id_map_error(t_player *player)
{
	player->waste =
	write(1, "Error\nInvalid ID in map.\n", 25);
	exit_program(player, 0);
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
			if ((is_empty_line(map[i]) == 0 && is_space(map[i][j]) &&
			is_empty_line(&map[i][j]) == 0))
				map_error(player, map, i, j);
			if ((is_empty_line(map[i]) == 0 && (i == 0 || i ==
			player->table_lenght - 1 || j == 0) && map[i][j] != '1' &&
			(is_space(map[i][j]) == 0 || (map[i + 1] &&
			map[i + 1][j] != '1' && is_space(map[i][j])))) ||
			(is_empty_line(map[i]) && check_walls(1, i, map, player)))
			{
				player->waste = write(1,
				"Error\nMap must be surrounded by walls.\n", 39);
				exit_program(player, map);
			}
		}
		j = -1;
	}
}
