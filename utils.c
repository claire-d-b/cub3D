/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clde-ber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 11:43:41 by clde-ber          #+#    #+#             */
/*   Updated: 2020/08/28 09:47:23 by clde-ber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*ptr;

	i = 0;
	if (!(ptr = malloc(sizeof(char) * (ft_strlen((char *)s1) + 1))))
		return (0);
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	void	*ptr;

	i = 0;
	if (!(ptr = (void *)malloc(count * size)))
		return (0);
	while (i < count * size)
	{
		((char *)ptr)[i] = 0;
		i++;
	}
	return (ptr);
}

char	*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	while (*str && *str != (char)c)
		str++;
	return (*str == c ? str : NULL);
}

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s2[i] && i + 1 < n)
	{
		if ((s1[i] != s2[i]))
			break ;
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	ft_swap(float **a, float **b)
{
	float *tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
