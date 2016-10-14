/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 00:32:08 by auverneu          #+#    #+#             */
/*   Updated: 2016/09/22 20:18:52 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** man 3 strncat
*/

char		*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(s1);
	i = 0;
	while (*(s2 + i) && i < n)
	{
		*(s1 + len + i) = *(s2 + i);
		i++;
	}
	*(s1 + len + i) = 0;
	return (s1);
}
