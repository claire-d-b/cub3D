/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsmem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clde-ber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 11:45:39 by clde-ber          #+#    #+#             */
/*   Updated: 2020/08/20 13:07:13 by clde-ber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*ft_free_sprite(float **sprite)
{
	int i;

	i = 0;
	while (sprite[i])
	{
		free(sprite[i]);
		i++;
	}
	free(sprite[i]);
	free(sprite);
	return (NULL);
}

void	*ft_free_tab(char **sprite)
{
	int i;

	i = 0;
	while (sprite[i])
	{
		free(sprite[i]);
		i++;
	}
	free(sprite[i]);
	free(sprite);
	return (NULL);
}
