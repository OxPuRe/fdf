/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 15:33:12 by auverneu          #+#    #+#             */
/*   Updated: 2016/09/22 20:23:21 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** Copy a substring of the given string starting from start to len.
** Return:	The copied string.
**			NULL if there is an error in memory allocation.
*/

char		*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	i;

	if (!s)
		return (NULL);
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (ret)
	{
		i = 0;
		while (i < len)
		{
			*(ret + i) = *(s + start + i);
			i++;
		}
		*(ret + i) = 0;
	}
	return (ret);
}
