/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 16:57:28 by auverneu          #+#    #+#             */
/*   Updated: 2016/09/22 20:24:52 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** This function concatenate 2 strings
** Return:	The result of the concatenation
**			NULL if there is an error in the memory allocation
*/

char		*ft_strjoin(const char *s1, const char *s2)
{
	char	*ret;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	ret = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (ret)
	{
		i = 0;
		while (*(s1 + i))
		{
			*(ret + i) = *(s1 + i);
			i++;
		}
		j = 0;
		while (*(s2 + j))
		{
			*(ret + i + j) = *(s2 + j);
			j++;
		}
		*(ret + i + j) = 0;
	}
	return (ret);
}
