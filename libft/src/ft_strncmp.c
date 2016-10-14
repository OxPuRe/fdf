/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 22:59:28 by auverneu          #+#    #+#             */
/*   Updated: 2016/09/22 20:18:57 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** man 3 strcmp
*/

int			ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*(s1 + i) != *(s2 + i))
		{
			if (*(unsigned char *)(s1 + i) < *(unsigned char *)(s2 + i))
				return (-1);
			else
				return (1);
		}
		else if (*(s1 + i) == '\0')
			return (0);
		i++;
	}
	return (0);
}
