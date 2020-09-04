/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fileutils_2_mac.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clde-ber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 16:41:20 by clde-ber          #+#    #+#             */
/*   Updated: 2020/09/03 16:50:26 by clde-ber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_mac.h"

int		is_map(char *line)
{
	int x;
	int count;

	x = 0;
	count = 0;
	while (line[x])
	{
		if (is_space(line[x]) || line[x] == '1')
			count++;
		x++;
	}
	if (x == count)
		return (1);
	return(0);
}
