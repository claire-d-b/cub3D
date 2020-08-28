/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fileutils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clde-ber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 15:39:30 by clde-ber          #+#    #+#             */
/*   Updated: 2020/08/28 09:42:38 by clde-ber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	pivot_file_checking(t_player *player, char *line, int y)
{
	int len;

	len = 0;
	if (line[0] == 'R')
		set_resolution(0, player, line);
	if ((line[0] == 'N' && line[1] == 'O')
	|| (line[0] == 'S' && line[1] == 'O'))
		set_path_to_texture_ns(0, player, line);
	if ((line[0] == 'W' && line[1] == 'E')
	|| (line[0] == 'E' && line[1] == 'A'))
		set_path_to_texture_ew(0, player, line);
	if (line[0] == 'S' && line[1] != 'O')
		set_path_to_texture_sp(0, player, line);
	if (line[0] == 'F')
		set_floor_color(0, player, line);
	if (line[0] == 'C')
		set_ceiling_color(0, player, line);
	if (line[0] == ' ' || line[0] == '\t' || line[0] == '\n' ||
	line[0] == '\r' || line[0] == '\v' || line[0] == '\f' ||
	line[0] == '1' || line[0] == '2' || line[0] == '0')
		len += set_map_len(y, player, line);
	return (len);
}

int	check_file(char *line, int fd, int i, t_player *player)
{
	int		y;

	y = 0;
	fd = open("map.cub", O_RDONLY);
	line = NULL;
	while ((i = get_next_line(fd, &line)))
	{
		player->table_lenght += pivot_file_checking(player, line, y);
		free(line);
		y++;
	}
	if (!(line))
	{
		player->save = write(1, "Error\nMissing newline after map.", 32);
		return (-1);
	}
	else
		player->table_lenght++;
	free(line);
	if (player->table_lenght < 3 || player->max < 3)
	{
		player->save = write(1, "Error\nIncorrect map.", 20);
		return (-1);
	}
	return (0);
}

int	set_resolution(int count, t_player *player, char *line)
{
	char **to_cast;

	to_cast = NULL;
	while (line[count++] && ft_isdigit(line[count]) == 0)
		if (line[count] == '\0')
		{
			player->save =
			write(1, "Error\nPlease provide numbers as map res.", 40);
			return (-1);
		}
	to_cast = ft_split(&line[count], ' ');
	count = 0;
	while (to_cast[count] && ft_atoi(to_cast[count]) >= 0)
		count++;
	if (!(count == 2))
	{
		player->save = write(1, "Error\nWrong resolution ID.", 26);
		return (-1);
	}
	player->struct_screen.x = ft_atoi(to_cast[0]);
	player->struct_screen.y = ft_atoi(to_cast[1]);
	ft_free3(to_cast);
	return (1);
}
