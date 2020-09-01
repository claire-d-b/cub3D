/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clde-ber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 08:26:26 by clde-ber          #+#    #+#             */
/*   Updated: 2020/08/18 15:43:44 by clde-ber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	int x;

	x = -1;
	while (++x < player->max)
	{
		if (x < (int)ft_strlen(line) && (line[x] == '0' || line[x] == '1' ||
		line[x] == '2' || line[x] == 'N' || line[x] == 'S' || line[x] == 'E'
		|| line[x] == 'W'))
			map[count][x] = line[x];
		else if (line[0] != ' ' && line[0] != '\t' && line[0] != '\n' &&
		line[0] != '\r' && line[0] != '\v' && line[0] != '\f')
			map[count][x] = '1';
	}
	map[count][x] = '\0';
	return (1);
}

int		fill_last_line(char **map, int count, t_player *player)
{
	int y;

	y = 0;
	if (!(map[count] = malloc(sizeof(char) * (player->max + 1))))
		return (0);
	while (y < player->max)
		map[count][y++] = '1';
	map[count][y] = '\0';
	return (1);
}

void	check_map(char *line, char **map, int count, t_player *player)
{
	if (line)
	{
		fill_last_line(map, count, player);
		map[count + 1] = 0;
		free(line);
	}
	else
		map[count] = 0;
	parse_map(map, player);
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
