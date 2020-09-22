/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilstextures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clde-ber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 12:39:37 by clde-ber          #+#    #+#             */
/*   Updated: 2020/09/03 16:53:35 by clde-ber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_mac.h"

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
		exit_program(player);
	}
}

int		set_path_to_texture_no(char *to_record, t_player *player)
{
	if ((ft_strncmp((const char *)to_record, "./text1.xpm",
	ft_strlen(to_record)) != 0) || ft_strlen(to_record) <= 2)
	{
		player->waste = write(1, "Error\nWrong path to north texture.", 34);
		return (-1);
	}
	player->xpm_path_no = ft_strdup(to_record);
	return (1);
}

int		set_path_to_texture_so(char *to_record, t_player *player)
{
	if ((ft_strncmp((const char *)to_record, "./text2.xpm",
	ft_strlen(to_record)) != 0) || ft_strlen(to_record) <= 2)
	{
		player->waste = write(1, "Error\nWrong path to south texture.", 34);
		return (-1);
	}
	player->xpm_path_so = ft_strdup(to_record);
	return (1);
}

int		set_path_to_texture_we(char *to_record, t_player *player)
{
	if ((ft_strncmp((const char *)to_record, "./text3.xpm",
	ft_strlen(to_record)) != 0) || ft_strlen(to_record) <= 2)
	{
		player->waste = write(1, "Error\nWrong path to west texture.", 33);
		return (-1);
	}
	player->xpm_path_we = ft_strdup(to_record);
	return (1);
}

int		set_path_to_texture_ea(char *to_record, t_player *player)
{
	if ((ft_strncmp((const char *)to_record, "./text4.xpm",
	ft_strlen(to_record)) != 0) || ft_strlen(to_record) <= 2)
	{
		player->waste = write(1, "Error\nWrong path to east texture.", 33);
		return (-1);
	}
	player->xpm_path_ea = ft_strdup(to_record);
	return (1);
}
