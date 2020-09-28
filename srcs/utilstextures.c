/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilstextures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clde-ber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 12:39:37 by clde-ber          #+#    #+#             */
/*   Updated: 2020/09/04 17:35:58 by clde-ber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		set_path_to_texture_no(char *to_record, t_player *player)
{
	int i;

	i = 0;
	if ((((ft_strncmp((const char *)to_record, "./text1.xpm",
	11) != 0) && (ft_strncmp((const char *)to_record,
	"./text2.xpm", 11) != 0) &&
	(ft_strncmp((const char *)to_record, "./text3.xpm",
	11) != 0) && (ft_strncmp((const char *)to_record,
	"./text4.xpm", 11) != 0)) || ft_strlen(to_record) <= 2))
	{
		player->waste = write(1, "Error\nWrong path to west texture.", 34);
		return (-1);
	}
	player->xpm_path_no = ft_strdup(to_record);
	while(player->xpm_path_no[i])
	{
		if (is_space(player->xpm_path_no[i]))
			player->xpm_path_no[i] = '\0';
		i++;
	}
	return (1);
}

int		set_path_to_texture_so(char *to_record, t_player *player)
{
	int i;

	i = 0;
	if ((((ft_strncmp((const char *)to_record, "./text1.xpm",
	11) != 0) && (ft_strncmp((const char *)to_record,
	"./text2.xpm", 11) != 0) &&
	(ft_strncmp((const char *)to_record, "./text3.xpm",
	11) != 0) && (ft_strncmp((const char *)to_record,
	"./text4.xpm", 11) != 0)) || ft_strlen(to_record) <= 2))
	{
		player->waste = write(1, "Error\nWrong path to east texture.", 34);
		return (-1);
	}
	player->xpm_path_so = ft_strdup(to_record);
	while(player->xpm_path_so[i])
	{
		if (is_space(player->xpm_path_so[i]))
			player->xpm_path_so[i] = '\0';
		i++;
	}
	return (1);
}

int		set_path_to_texture_we(char *to_record, t_player *player)
{
	int i;

	i = 0;
	if ((((ft_strncmp((const char *)to_record, "./text1.xpm",
	11) != 0) && (ft_strncmp((const char *)to_record,
	"./text2.xpm", 11) != 0) &&
	(ft_strncmp((const char *)to_record, "./text3.xpm",
	11) != 0) && (ft_strncmp((const char *)to_record,
	"./text4.xpm", 11) != 0)) || ft_strlen(to_record) <= 2))
	{
		player->waste = write(1, "Error\nWrong path to north texture.", 33);
		return (-1);
	}
	player->xpm_path_we = ft_strdup(to_record);
	while(player->xpm_path_we[i])
	{
		if (is_space(player->xpm_path_we[i]))
			player->xpm_path_we[i] = '\0';
		i++;
	}
	return (1);
}

int		set_path_to_texture_ea(char *to_record, t_player *player)
{
	int i;

	i = 0;
	if ((((ft_strncmp((const char *)to_record, "./text1.xpm",
	11) != 0) && (ft_strncmp((const char *)to_record,
	"./text2.xpm", 11) != 0) &&
	(ft_strncmp((const char *)to_record, "./text3.xpm",
	11) != 0) && (ft_strncmp((const char *)to_record,
	"./text4.xpm", 11) != 0)) || ft_strlen(to_record) <= 2))
	{
		player->waste = write(1, "Error\nWrong path to south texture.", 33);
		return (-1);
	}
	player->xpm_path_ea = ft_strdup(to_record);
	while(player->xpm_path_ea[i])
	{
		if (is_space(player->xpm_path_ea[i]))
			player->xpm_path_ea[i] = '\0';
		i++;
	}
	return (1);
}
