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
		if (is_space(line[x]) || line[x] == '1' || line[x] == '0' || line[x] == '2'
		|| line[x] == 'N' || line[x] == 'S' || line[x] == 'E' || line[x] == 'W')
			count++;
		x++;
	}
	if (x == count)
		return (1);
	return (0);
}
