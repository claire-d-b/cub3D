/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clde-ber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 08:26:26 by clde-ber          #+#    #+#             */
/*   Updated: 2020/09/04 17:39:59 by clde-ber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		set_map_len(int y, t_player *player, char *line)
{
	int x;
	int count;

	x = 0;
	count = 0;
	player->map_start = (player->bool_start == 0) ? y : player->map_start;
	player->bool_start = 1;
	while (line[x])
	{
		if (!(is_space(line[x])))
			count++;
		x++;
	}
	if (player->max < count)
		player->max = count;
	return (1);
}

int		transform_map(char **map, int count, char *line, t_player *player)
{
	int y;
	int x;

	y = -1;
	x = 0;
	while (line[++y] && is_map(line))
	{
		if (is_space(line[y]) == 0)
		{
			map[count][x] = line[y];
			x++;
		}
		if ((count == 0 || count == player->table_lenght - 1 || y == 0 ||
		y == (int)ft_strlen(line) - 1) && line[y] != '1' &&
		is_space(line[y]) == 0)
		{
			player->waste =
			write(1, "Error\nMap must be surrounded by walls.\n", 39);
			exit_program(player);
		}
	}
	map[count][x] = '\0';
	return (1);
}

int		check_surr_walls(char **map, int i, int j)
{
	if ((((int)ft_strlen(map[i - 1]) - (int)ft_strlen(map[i])) > 2 && j >=
	(int)ft_strlen(map[i]) - 1 && map[i - 1][j] != '1')
	|| (((int)ft_strlen(map[i - 1]) - (int)ft_strlen(map[i])) < -2 &&
	((int)ft_strlen(map[i - 1]) - (int)ft_strlen(map[i])) < 0 &&
	j >= (int)ft_strlen(map[i - 1]) - 1 && map[i][j] != '1')
	|| (((int)ft_strlen(map[i - 1]) - (int)ft_strlen(map[i])) <= 2 &&
	((int)ft_strlen(map[i - 1]) - (int)ft_strlen(map[i])) > 0 &&
	j >= (int)ft_strlen(map[i]) - 1 && map[i - 1][j] != '1' &&
	map[i - 1][j + 1] != '1')
	|| (((int)ft_strlen(map[i - 1]) - (int)ft_strlen(map[i])) >= -2 &&
	((int)ft_strlen(map[i - 1]) - (int)ft_strlen(map[i])) < 0 &&
	j >= (int)ft_strlen(map[i - 1]) - 1 && map[i][j] != '1' &&
	map[i][j + 1] != '1'))
		return (1);
	return (0);
}

void	check_map(char *line, char **map, int count, t_player *player)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (line)
		free(line);
	map[count] = 0;
	parse_map(map, player);
	while (map[i])
	{
		while (map[i][j])
		{
			if (i && j && check_surr_walls(map, i, j))
			{
				player->waste =
				write(1, "Error\nMap must be surrounded by walls.\n", 39);
				exit_program(player);
			}
			j++;
		}
		i++;
		j = 0;
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
	i = 0;
	y = 0;
	fd = open(arg, O_RDONLY);
	if (!(map = malloc(sizeof(char *) * (lenght + 2))))
		return (0);
	while ((i = get_next_line(fd, &line)))
	{
		if (y >= player->map_start && count < (player->table_lenght))
		{
			if (!(map[count] = malloc(sizeof(char) * (player->max + 1))))
				return (0);
			count += transform_map(map, count, line, player);
		}
		y++;
		free(line);
	}
	check_map(line, map, count, player);
	return (map);
}
