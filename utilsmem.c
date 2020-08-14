/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsmem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clde-ber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 11:45:39 by clde-ber          #+#    #+#             */
/*   Updated: 2020/08/14 12:13:49 by clde-ber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void *ft_free2(float **sprite)
{
	int i = 0;
	while (sprite[i])
	{
		free(sprite[i]);
		i++;
	}
	free(sprite[i]);
	free(sprite);
	return (NULL);
}

void *ft_free3(char **sprite)
{
	int i = 0;
	while (sprite[i])
	{
		free(sprite[i]);
		i++;
		printf("ici");
	}
	free(sprite[i]);
	free(sprite);
	return (NULL);
}
