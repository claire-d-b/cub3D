/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsnb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clde-ber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 13:04:39 by clde-ber          #+#    #+#             */
/*   Updated: 2020/08/20 13:06:05 by clde-ber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_mac.h"

void	doublons(char *line, t_player *player)
{
	if (is_empty_line(line) == 0 && ((ft_strlen(line) >= 1 &&
	((line[0] == 'R' && player->struct_screen.x != -1 &&
	player->struct_screen.y != -1) || (line[0] != 'C' && player->ceil_color[3] != -1)
	 || (line[0] == 'F' && player->floor_color[3] != -1) || (line[0] == 'S' &&
	 player->xpm_path_sp != 0)) && (is_space(line[1]) || line[1] == '\0'))
	|| (ft_strlen(line) >= 3 && (((line[2] && is_space(line[2])) || line[2] == '\0'))
	&& ((line[0] == 'N' && line[1] == 'O' && player->xpm_path_no != 0) ||
	(line[0] == 'S' && line[1] == 'O' && player->xpm_path_so != 0) ||
	(line[0] == 'E' && line[1] == 'A' && player->xpm_path_ea != 0) ||
	(line[0] == 'W' && line[1] == 'E' && player->xpm_path_we != 0)))))
	 {
		 player->waste = write(1, "Error\nDoublons in IDs.\n", 23);
		 exit_program(player);
	 }
}

void	manage_lines(char *line, t_player *player)
{
	if (ft_strlen(line) >= 1 && !(line[0] == '1') && !(is_space(line[0])) &&
	is_empty_line(line) == 0 && ((line[0] != 'R' && line[0] != 'C' &&
	line[0] != 'F' && line[0] != 'S' && (is_space(line[1]) || line[1] == '\0')) ||
	(((line[2] && is_space(line[2])) || line[2] == '\0') && (((line[0] != 'N' && line[1] != 'O')
	|| (line[0] != 'N' && line[1] == 'O') || (line[0] == 'N' && line[1] != 'O')) &&
	((line[0] != 'S' && line[1] != 'O') || (line[0] != 'S' && line[1] == 'O') ||
	(line[0] == 'S' && line[1] != 'O')) && ((line[0] != 'E' && line[1] != 'A') ||
	(line[0] != 'E' && line[1] == 'A') || (line[0] == 'E' && line[1] != 'A')) &&
	((line[0] != 'W' && line[1] != 'E') || (line[0] != 'W' && line[1] == 'E') ||
	(line[0] == 'W' && line[1] != 'E'))))))
	{
		player->waste =
		write(1, "Error\nOnly IDs, map and empty lines are valid.\n", 47);
		exit_program(player);
	}
	doublons(line, player);
}

int		is_empty_line(char *line)
{
	size_t i;
	size_t count;

	i = 0;
	count = 0;
	if (line[0] == '\0')
		return (1);
	while (line[i])
	{
		if (line[i] == ' ' || line[i] == '\t' || line[i] == '\n'
		|| line[i] == '\r' || line[i] == '\v' || line[i] == '\f')
			count++;
		i++;
	}
	if (i != count)
		return (0);
	return (1);
}

int		ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int		ft_atoi(const char *str)
{
	int i;
	int j;
	int res;

	i = 0;
	j = 0;
	res = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			j = (str[i] == '-') ? -1 : 1;
		i++;
	}
	while (ft_isdigit(str[i]))
		res = res * 10 + (str[i++] - 48);
	if (res == -2147483648)
		return (res);
	if (j < 0)
		res = res * j;
	return (res);
}

int		is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\r' ||
	c == '\v' || c == '\f')
		return (1);
	return (0);
}