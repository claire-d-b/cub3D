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
	while (line[x] && line[x] != ' ' && line[x] != '\t' && line[x] != '\n'
	&& line[x] != '\r' && line[x] != '\v' && line[x] != '\f' && line[x])
		x++;
	if (player->max < x)
		player->max = x;
	return (1);
}

int		transform_map(char **map, int count, char *line, t_player *player)
{
	int y;
	int x;

	y = -1;
	x = 0;
	while (line[++y] &&
	(line[y] == '0' || line[y] == '1' || line[y] == '2' || line[y] == 'N' ||
	line[y] == 'S' || line[y] == 'E' || line[y] == 'W' || is_space(line[y])))
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
			write(1, "Error\nMap must be surrounded by walls.\n", 39);
			exit_program(player);
		}
	}
	map[count][x] = '\0';
	return (1);
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
		while (i && ft_strlen(map[i - 1]) != ft_strlen(map[i]) && map[i - 1][j])
		{
			if (j > (int)ft_strlen(map[i]) && map[i - 1][j] != '1')
				if (map[i - 1][j] != '1')
				{
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
