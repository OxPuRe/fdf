/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 22:59:28 by auverneu          #+#    #+#             */
/*   Updated: 2016/09/22 20:17:31 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** man 3 strcmp
*/

int			ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (*((unsigned char*)s1 + i) && *((unsigned char*)s2 + i))
	{
		if (*(s1 + i) != *(s2 + i))
			return (*((unsigned char*)s1 + i) - *((unsigned char*)s2 + i));
		i++;
	}
	return (*((unsigned char*)s1 + i) - *((unsigned char*)s2 + i));
}
