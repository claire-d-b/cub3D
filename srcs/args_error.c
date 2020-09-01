/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clde-ber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 19:36:49 by clde-ber          #+#    #+#             */
/*   Updated: 2020/09/01 21:07:21 by clde-ber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	two_args_plus_error(int nb_args, char **args, t_player *player)
{
	if (nb_args >= 3 && !ft_strchr(args[2], '.'))
		player->waste =
		write(1, "Error\nPlease provide a valid map file.\n", 39);
	else if (nb_args == 1)
		player->waste =
		write(1, "Error\nPlease provide at least one valid argument.\n", 50);
	else if (nb_args > 2 && !ft_strncmp(ft_strchr(args[2], '.'), ".cub", 4)
	&& (strncmp(args[1], "--save", 6) || ft_strlen(args[1]) != 6))
		player->waste =
		write(1, "Error\nThird argument is not valid.\n", 35);
	else if (nb_args > 2 && (ft_strncmp(ft_strchr(args[2], '.'), ".cub", 4) ||
	ft_strlen(ft_strchr(args[2], '.')) != 4) && !strncmp(args[1], "--save", 6))
		player->waste =
		write(1, "Error\nSecond argument is not valid.\n", 36);
	else if (nb_args > 3)
		player->waste =
		write(1, "Error\nPlease provide maximum two argments.\n", 43);
	else if (nb_args == 2 && ft_strncmp(ft_strchr(args[1], '.'), ".cub", 4))
		player->waste =
		write(1, "Error\nPlease provide a valid map file.\n", 39);
}

void	arg_error(int nb_args, char **args, t_player *player)
{
	if (nb_args == 3 && ft_strlen(args[1]) == 6 &&
	strncmp(args[1], "--save", 6) == 0)
		player->save = 1;
	if (nb_args > 2)
		two_args_plus_error(nb_args, args, player);
	else if (nb_args == 2)
	{
		if (!(ft_strchr(args[1], '.') && ft_strlen(ft_strchr(args[1], '.'))
		== 4 && !ft_strncmp(ft_strchr(args[1], '.'), ".cub", 4)))
			player->waste =
			write(1, "Error\nPlease provide a valid map file.\n", 39);
	}
	else
		player->waste =
		write(1, "Error\nPlease provide minimum one argment.\n", 42);
	if (player->waste)
		exit_program(player);
}
