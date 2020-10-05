/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fileutils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clde-ber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 17:32:39 by clde-ber          #+#    #+#             */
/*   Updated: 2020/09/04 17:39:38 by clde-ber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		is_map(char *line)
{
	int x;
	int count;

	x = 0;
	count = 0;
	while (line[x])
	{
		if (is_space(line[x]) || line[x] == '1' || line[x] == '0'
		|| line[x] == '2' || line[x] == 'N' || line[x] == 'S' ||
		line[x] == 'E' || line[x] == 'W')
			count++;
		x++;
	}
	if (x == count)
		return (1);
	return (0);
}

void	doublons(char *line, t_player *player)
{
	if (is_map(line) == 0 &&
	is_empty_line(line) == 0 && ((ft_strlen(line) >= 1 &&
	((line[0] == 'R' && player->struct_screen.x != -1 &&
	player->struct_screen.y != -1) || (line[0] == 'C' &&
	player->ceil_color[3] != -1) || (line[0] == 'F' &&
	player->floor_color[3] != -1) || (line[0] == 'S' &&
	player->xpm_path_sp != 0)) && (is_space(line[1]) || line[1] == '\0'))
	|| (ft_strlen(line) >= 3 && (((line[2] && is_space(line[2])) ||
	line[2] == '\0')) && ((line[0] == 'N' && line[1] == 'O' &&
	player->xpm_path_no != 0) || (line[0] == 'S' && line[1] == 'O'
	&& player->xpm_path_so != 0) || (line[0] == 'E' && line[1] == 'A'
	&& player->xpm_path_ea != 0) || (line[0] == 'W' && line[1] == 'E'
	&& player->xpm_path_we != 0)))))
	{
		player->waste = write(1, "Error\nDoublons in IDs.\n", 23);
		exit_program(player, 0);
	}
}

int		is_number(char *to_cast)
{
	int i;

	i = 0;
	while (to_cast[i] && (ft_isdigit(to_cast[i]) ||
	is_space(to_cast[i])))
		i++;
	if (i == (int)ft_strlen(to_cast))
		return (1);
	return (0);
}

void	map_error2(int index, int y, t_player *player, char *line)
{
	if (((player->walls > index && y <= player->walls && y > index)
	|| (player->walls <= index && y <= index && y > player->walls)) &&
	line[y] != '1' && player->walls != 0)
	{
		player->waste =
		write(1, "Error\nMap must be surrounded by walls.\n", 39);
		exit_program(player, 0);
	}
}
