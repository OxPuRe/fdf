/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 00:32:08 by auverneu          #+#    #+#             */
/*   Updated: 2016/09/22 20:19:35 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** man 3 strrchr
*/

char		*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (*(s + i))
		i++;
	if ((char)c == 0)
		return ((char*)(s + i));
	while (i > 0)
	{
		i--;
		if (*(s + i) == (char)c)
			return ((char*)(s + i));
	}
	return (NULL);
}
