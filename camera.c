/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clde-ber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 08:23:48 by clde-ber          #+#    #+#             */
/*   Updated: 2020/08/14 11:33:23 by clde-ber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	camera_right(t_player *player)
{
	if ((int)player->teta <= (int)-M_PI)
		player->teta = M_PI;
	player->teta-=rotation;
}

void	camera_left(t_player *player)
{
	if ((int)player->teta >= (int)M_PI)
		player->teta = -M_PI;
	player->teta+=rotation;
}
