/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 23:22:05 by auverneu          #+#    #+#             */
/*   Updated: 2016/09/22 20:19:03 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** man 3 strncpy
*/

char		*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (*(src + i) && i < n)
	{
		*(dst + i) = *(src + i);
		i++;
	}
	while (i < n)
	{
		*(dst + i) = 0;
		i++;
	}
	return (dst);
}
