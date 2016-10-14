/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ilen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 18:54:02 by auverneu          #+#    #+#             */
/*   Updated: 2016/09/02 00:00:58 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** This function return the length of a given number in base 10.
** Return:	The length of the number.
*/

size_t		ft_ilen(int x)
{
	size_t	ret;

	ret = 0;
	if (x <= 0)
		ret++;
	while (x != 0)
	{
		x /= 10;
		ret++;
	}
	return (ret);
}
