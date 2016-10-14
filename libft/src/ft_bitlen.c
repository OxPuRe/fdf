/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bitlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/03 06:57:16 by auverneu          #+#    #+#             */
/*   Updated: 2016/08/06 03:37:17 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** This function count the lenght in bits of the number nb.
** Return:	the length of nb.
*/

size_t		ft_bitlen(unsigned long long nb)
{
	size_t	size;

	size = 0;
	while (nb)
	{
		nb >>= 1;
		size++;
	}
	return (size);
}
