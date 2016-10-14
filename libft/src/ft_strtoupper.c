/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoupper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 18:03:20 by auverneu          #+#    #+#             */
/*   Updated: 2016/10/04 18:18:08 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** This function transform all char of the string to upper case.
*/

char		*ft_strtoupper(char *s)
{
	size_t	i;

	i = 0;
	while (*(s + i))
	{
		*(s + i) = ft_toupper(*(s + i));
		i++;
	}
	return (s);
}
