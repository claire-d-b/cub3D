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

void	set_game_elements(char *line, t_player *player)
{
	if (line[0] == 'R' && player->struct_screen.x == -1
	&& player->struct_screen.y == -1)
		if (set_resolution(0, player, line) == -1)
			exit_program(player);
	if (((line[0] == 'N' && line[1] == 'O')
	|| (line[0] == 'S' && line[1] == 'O')) &&
	(player->xpm_path_no == 0 || player->xpm_path_so == 0))
		if (set_path_to_texture_ns(0, player, line) == -1)
			exit_program(player);
	if (((line[0] == 'W' && line[1] == 'E')
	|| (line[0] == 'E' && line[1] == 'A')) &&
	(player->xpm_path_we == 0 || player->xpm_path_ea == 0))
		if (set_path_to_texture_ew(0, player, line) == -1)
			exit_program(player);
	if (line[0] == 'S' && line[1] != 'O' &&
	player->xpm_path_sp == 0)
		if (set_path_to_texture_sp(0, player, line) == -1)
			exit_program(player);
	if (line[0] == 'F' && player->floor_color[0] == -1)
		if (set_floor_color(0, player, line) == -1)
			exit_program(player);
	if (line[0] == 'C' && player->ceil_color[0] == -1)
		if (set_ceiling_color(0, player, line) == -1)
			exit_program(player);
	manage_lines(line, player);
}

int		pivot_file_checking(int len, t_player *player, char *line, int y)
{
	set_game_elements(line, player);
	if ((line[0] == ' ' || line[0] == '\t' || line[0] == '\n' ||
	line[0] == '\r' || line[0] == '\v' || line[0] == '\f' ||
	line[0] == '1' || line[0] == '2' || line[0] == '0') &&
	(ft_strchr(line, '1') || ft_strchr(line, '0')))
		len += set_map_len(y, player, line);
	return (len);
}

void	missing_elements(t_player *player, char *line)
{
	if (player->struct_screen.x < 0 || player->struct_screen.y < 0
	|| player->xpm_path_no == 0 || player->xpm_path_so == 0 ||
	player->xpm_path_we == 0 || player->xpm_path_ea == 0 ||
	player->xpm_path_sp == 0 || player->ceil_color[3] < 0 ||
	player->floor_color[3] < 0)
	{
		player->waste = write(1, "Error\nMissing info in file.\n", 28);
		exit_program(player);
	}
	if (player->table_lenght == 0)
	{
		player->waste = write(1, "Error\nMissing map in file.\n", 27);
		exit_program(player);
	}
	free(line);
	if (player->table_lenght < 3 || player->max < 3)
	{
		player->waste = write(1, "Error\nIncorrect map.\n", 21);
		exit_program(player);
	}
}

int		check_file(char *line, int fd, int i, t_player *player)
{
	int		y;

	y = 0;
	fd = open("map.cub", O_RDONLY);
	line = NULL;
	while ((i = get_next_line(fd, &line)) >= 0)
	{
		player->table_lenght += pivot_file_checking(0, player, line, y);
		if (i != 0)
			free(line);
		y++;
		if (i == 0)
			break ;
	}
	missing_elements(player, line);
	return (0);
}

int		set_resolution(int count, t_player *player, char *line)
{
	char **to_cast;

	to_cast = NULL;
	while (line[count++] && ft_isdigit(line[count]) == 0)
		if (line[count] == '\0')
		{
			player->waste =
			write(1, "Error\nPlease provide numbers as map res.", 40);
			return (-1);
		}
	to_cast = ft_split(&line[count], ' ');
	count = 0;
	while (to_cast[count] && ft_atoi(to_cast[count]) > 0)
		count++;
	if (!(count == 2))
	{
		player->waste = write(1, "Error\nWrong resolution ID.", 26);
		ft_free_tab(to_cast);
		return (-1);
	}
	player->struct_screen.x = ft_atoi(to_cast[0]);
	player->struct_screen.y = ft_atoi(to_cast[1]);
	ft_free_tab(to_cast);
	return (1);
}
