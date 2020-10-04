/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clde-ber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 08:26:26 by clde-ber          #+#    #+#             */
/*   Updated: 2020/09/19 13:18:32 by clde-ber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_mac.h"

int		set_map_len(int y, t_player *player, char *line)
{
	int x;

	x = 0;
	player->map_start = (player->bool_start == 0) ? y : player->map_start;
	player->bool_start = 1;
	while (line[x])
		x++;
	if (player->max < x)
		player->max = x;
	return (1);
}

int		transform_map(char **map, int count, char *line, t_player *player)
{
	int y;
	int index;

	y = -1;
	index = 0;
	while (line[++y] && is_map(line))
	{
		if (is_space(line[y]))
			index = y;
		map[count][y] = line[y];
		if (y && count && ((y == index && player->walls > index &&
		is_space(line[y + 1]) == 0) || (player->walls < index)) &&
		is_empty_line_count(line, y + 1) && is_empty_line(line) == 0
		&& index != 0)
			map_error2(index, y, player, line);
		player->walls = (is_space(line[y + 1]) == 0) ? index : player->walls;
	}
	map[count][y] = '\0';
	return (1);
}

int		check_surr_walls(char **map, int i, int j)
{
	int x;

	x = 0;
	if (((int)ft_strlen_nospace(map[i - 1]) -
	(int)ft_strlen_nospace(map[i])) > 0)
	{
		while (j + x < (int)ft_strlen_nospace(map[i - 1]))
		{
			if (map[i - 1][j + x] != '1')
				return (1);
			x++;
		}
	}
	if (((int)ft_strlen_nospace(map[i - 1]) -
	(int)ft_strlen_nospace(map[i])) < 0)
	{
		while (j + x < (int)ft_strlen_nospace(map[i]))
		{
			if (map[i][j + x] != '1')
				return (1);
			x++;
		}
	}
	return (0);
}

void	check_map(char **map, int count, t_player *player)
{
	int i;
	int j;

	i = -1;
	j = 0;
	map[count] = 0;
	parse_map(map, player);
	while (map[++i])
	{
		if (i && ((((int)ft_strlen_nospace(map[i - 1]) -
		(int)ft_strlen_nospace(map[i])) == 0 && (j = (int)ft_strlen_nospace(
		map[i]) - 1) && j > 0 && (map[i - 1][j] != '1' || map[i][j] != '1'))
		|| (((int)ft_strlen(map[i - 1]) - (int)ft_strlen(
		map[i])) > 0 && (j = (int)ft_strlen_nospace(map[i])) && j > 0 &&
		check_surr_walls(map, i, j)) || (((int)ft_strlen_nospace(map[i - 1])
		- (int)ft_strlen_nospace(map[i])) < 0 && (j = (int)ft_strlen_nospace(
		map[i - 1])) && j && check_surr_walls(map, i, j))) &&
		is_empty_line(map[i]) == 0)
		{
			player->waste =
			write(1, "Error\nMap must be surrounded by walls.\n", 39);
			exit_program(player);
		}
	}
}

char	**create_map(char **map, int lenght, t_player *player, char *arg)
{
	int		fd;
	int		i;
	char	*line;
	int		y;
	int		count;

	count = 0;
	y = -1;
	fd = open(arg, O_RDONLY);
	if (!(map = malloc(sizeof(char *) * (lenght + 2))))
		return (0);
	while ((i = get_next_line(fd, &line)) >= 0)
	{
		if (++y >= player->map_start && count < (player->table_lenght))
		{
			if (!(map[count] = malloc(sizeof(char) * (player->max + 1))))
				return (0);
			count += transform_map(map, count, line, player);
		}
		free(line);
		if (i == 0)
			break ;
	}
	check_map(map, count, player);
	return (map);
}
