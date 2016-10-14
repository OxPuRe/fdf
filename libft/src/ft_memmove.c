/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 21:03:43 by auverneu          #+#    #+#             */
/*   Updated: 2016/09/22 20:15:23 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** man 3 memmove
*/

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (src < dst)
	{
		while (len)
		{
			*((unsigned char *)dst + len - 1) =
				*((const unsigned char *)src + len - 1);
			len--;
		}
	}
	else
	{
		i = 0;
		while (i < len)
		{
			*((unsigned char *)dst + i) = *((const unsigned char *)src + i);
			i++;
		}
	}
	return (dst);
}
