/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 15:33:45 by auverneu          #+#    #+#             */
/*   Updated: 2016/09/22 20:52:25 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** This function compare the n first characters of to string.
** Return:	1 if the compared characters are the same.
**			0 if not.
*/

int			ft_strnequ(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (!s1 || !s2)
		return (0);
	i = 0;
	while (*(s1 + i) == *(s2 + i) && *(s1 + i) && *(s2 + i) && i < n)
		i++;
	if (i && *(s1 + i) && *(s2 + i))
		i = i - 1;
	if ((*(s1 + i) == 0 && *(s2 + i) == 0) ||
		(*(s1 + i) == *(s2 + i) && i + 1 == n) || (i == 0))
		return (1);
	return (0);
}
