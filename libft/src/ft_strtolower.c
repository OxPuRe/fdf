/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtolower.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 18:03:05 by auverneu          #+#    #+#             */
/*   Updated: 2016/10/04 18:18:11 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** This function transform all char of the string to lower case.
*/

char		*ft_strtolower(char *s)
{
	size_t	i;

	i = 0;
	while (*(s + i))
	{
		*(s + i) = ft_tolower(*(s + i));
		i++;
	}
	return (s);
}
