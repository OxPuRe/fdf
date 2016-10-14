/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 16:34:58 by auverneu          #+#    #+#             */
/*   Updated: 2016/09/22 20:19:13 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** This function allocate a chunk of memory to a string and set all the bytes
** to 0.
** Return:	The allocated string.
**			NULL if there is an error in memory allocation.
*/

char		*ft_strnew(size_t size)
{
	char	*ret;
	size_t	i;

	ret = (char *)malloc(sizeof(char) * (size + 1));
	if (ret)
	{
		i = 0;
		while (i <= size)
		{
			*(ret + i) = 0;
			i++;
		}
	}
	return (ret);
}
