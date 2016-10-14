/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 16:31:50 by auverneu          #+#    #+#             */
/*   Updated: 2016/09/22 20:18:44 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** This function iterate the given function on the given string and store the
** result in a new string.
** Return:	The string containing the result of the iteration.
**			NULL if there is an error.
*/

char		*ft_strmap(const char *s, char (*f)(char))
{
	size_t	i;
	char	*ret;

	if (!s || !f)
		return (NULL);
	i = 0;
	ret = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (ret)
	{
		while (*(s + i))
		{
			*(ret + i) = (*f)(*(s + i));
			i++;
		}
		*(ret + i) = 0;
	}
	return (ret);
}
