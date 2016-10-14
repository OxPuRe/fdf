/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 23:22:05 by auverneu          #+#    #+#             */
/*   Updated: 2016/09/22 20:17:51 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** This function compare 2 strings.
** Return:	1 if the 2 string are the sames.
**			0 if not.
*/

int			ft_strequ(const char *s1, const char *s2)
{
	size_t	i;

	if (!s1 || !s2)
		return (0);
	i = 0;
	while (*(s1 + i) == *(s2 + i) && *(s1 + i) && *(s2 + i))
		i++;
	if (*(s1 + i) == 0 && *(s2 + i) == 0)
		return (1);
	return (0);
}
