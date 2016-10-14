/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 22:58:02 by auverneu          #+#    #+#             */
/*   Updated: 2016/09/22 20:18:36 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** man 3 strlcpy
*/

size_t		ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size && size - 1)
	{
		while (i < size - 1)
		{
			*(dst + i) = *(src + i);
			if (!*(src + i))
				break ;
			i++;
		}
	}
	if (i == size - 1)
	{
		if (size != 0)
			*(dst + i) = 0;
		while (*(src + i))
			i++;
	}
	return (ft_strlen(src));
}
