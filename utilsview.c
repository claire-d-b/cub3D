/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsview.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clde-ber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 11:44:48 by clde-ber          #+#    #+#             */
/*   Updated: 2020/08/14 11:45:24 by clde-ber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned int rgb3(unsigned int r, unsigned int g, unsigned int b)
{
    return (r * 256 * 256) + (g * 256) + b;
}


int get_decimals(float height)
{
	int res;

	res = (int)((height - (int)height) * 100);
	return (res);
}
