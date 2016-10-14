/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 16:32:13 by auverneu          #+#    #+#             */
/*   Updated: 2016/09/22 20:12:38 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** This function iterate the given function on the given string passing the
** position of the current character as the first argument to the given function
** and store the result in a new string.
** Return:	The string containing the result of the iteration.
**			NULL if there is an error.
*/

char		*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*ret;

	if (!s || !f)
		return (0);
	i = 0;
	ret = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (ret)
	{
		while (*(s + i))
		{
			*(ret + i) = (*f)(i, *(s + i));
			i++;
		}
		*(ret + i) = 0;
	}
	return (ret);
}
