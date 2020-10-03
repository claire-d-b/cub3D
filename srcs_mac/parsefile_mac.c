/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsefile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clde-ber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 11:40:30 by clde-ber          #+#    #+#             */
/*   Updated: 2020/08/19 18:50:39 by clde-ber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_mac.h"

int	set_path_to_texture_ns(int count, t_player *player, char *line)
{
	char *to_record;

	if ((to_record = ft_strchr(line, '.')) &&
	is_empty_line(&to_record[11]))
	{
		if (line[count] == 'N' && line[count + 1] == 'O' && count == 0)
			set_path_to_texture_no(to_record, player);
		if (line[count] == 'S' && line[count + 1] == 'O' && count == 0)
			set_path_to_texture_so(to_record, player);
		return (1);
	}
	player->waste = write(1, "Error\nWalls texture path.\n", 26);
	exit_program(player);
	return (-1);
}

int	set_path_to_texture_ew(int count, t_player *player, char *line)
{
	char *to_record;

	if ((to_record = ft_strchr(line, '.')) &&
	is_empty_line(&to_record[11]))
	{
		if (line[count] == 'W' && line[count + 1] == 'E' && count == 0)
			set_path_to_texture_we(to_record, player);
		if (line[count] == 'E' && line[count + 1] == 'A' && count == 0)
			set_path_to_texture_ea(to_record, player);
		return (1);
	}
	player->waste = write(1, "Error\nWalls texture path.\n", 26);
	exit_program(player);
	return (-1);
}

int	set_path_to_texture_sp(int count, t_player *player, char *line, int i)
{
	char *to_record;

	if ((to_record = ft_strchr(line, '.')) &&
	is_empty_line(&to_record[12]))
	{
		if (line[count] == 'S' && line[count + 1] != 'O' && count == 0)
		{
			if ((ft_strncmp((const char *)to_record, "./sprite.xpm",
			12) != 0) || ft_strlen(to_record) <= 2)
			{
				player->waste =
				write(1, "Error\nWrong path to sprite texture.", 35);
				return (-1);
			}
			player->xpm_path_sp = ft_strdup(to_record);
			while (player->xpm_path_sp[++i])
				if (is_space(player->xpm_path_sp[i]))
					player->xpm_path_sp[i] = '\0';
		}
		return (1);
	}
	player->waste = write(1, "Error\nSprite texture path.\n", 27);
	exit_program(player);
	return (-1);
}

int	set_floor_color(int count, int i, t_player *player, char *line)
{
	char	**to_cast;
	int		j;

	j = 0;
	to_cast = NULL;
	while (line[++count])
		i = (line[count] == ',') ? i + 1 : i;
	if ((to_cast = ft_split(&line[1], ',')))
		while (to_cast[j] && is_number(to_cast[j]) &&
		ft_atoi(to_cast[j]) >= 0 && ft_atoi(to_cast[j]) <= 255)
			j++;
	if (j != 3 || i != 2)
	{
		player->waste = write(1, "Error\nWrong color ID [floor]\n", 29);
		if (to_cast)
			ft_free_tab(to_cast);
		return (-1);
	}
	player->floor_color[0] = ft_atoi(to_cast[0]);
	player->floor_color[1] = ft_atoi(to_cast[1]);
	player->floor_color[2] = ft_atoi(to_cast[2]);
	player->floor_color[3] = rgb3((unsigned int)player->floor_color[0],
	(unsigned int)player->floor_color[1], (unsigned int)player->floor_color[2]);
	ft_free_tab(to_cast);
	return (1);
}

int	set_ceiling_color(int count, int i, t_player *player, char *line)
{
	char	**to_cast;
	int		j;

	j = 0;
	to_cast = NULL;
	while (line[++count])
		i = (line[count] == ',') ? i + 1 : i;
	if ((to_cast = ft_split(&line[1], ',')))
		while (to_cast[j] && is_number(to_cast[j]) &&
		ft_atoi(to_cast[j]) >= 0 && ft_atoi(to_cast[j]) <= 255)
			j++;
	if (j != 3 || i != 2)
	{
		player->waste = write(1, "Error\nWrong color ID [ceiling]\n", 31);
		if (to_cast)
			ft_free_tab(to_cast);
		return (-1);
	}
	player->ceil_color[0] = ft_atoi(to_cast[0]);
	player->ceil_color[1] = ft_atoi(to_cast[1]);
	player->ceil_color[2] = ft_atoi(to_cast[2]);
	player->ceil_color[3] = rgb3((unsigned int)player->ceil_color[0],
	(unsigned int)player->ceil_color[1], (unsigned int)player->ceil_color[2]);
	ft_free_tab(to_cast);
	return (1);
}
