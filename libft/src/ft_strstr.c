/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 00:32:08 by auverneu          #+#    #+#             */
/*   Updated: 2016/09/22 20:20:14 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** man 3 strstr
*/

char		*ft_strstr(const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;
	size_t	len;

	len = ft_strlen(s2);
	if (len == 0)
		return ((char*)s1);
	i = 0;
	while (*(s1 + i))
	{
		j = 0;
		while (*(s1 + i + j) == *(s2 + j) && *(s2 + j))
			j++;
		if (j == len)
			return ((char*)(s1 + i));
		i++;
	}
	return (NULL);
}
