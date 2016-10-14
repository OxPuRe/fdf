/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 19:59:11 by auverneu          #+#    #+#             */
/*   Updated: 2016/08/13 06:15:07 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** This function write the given number to STDOUT.
** Return:	The size of the number
**			-1 if an error occured
*/

size_t		ft_putnbr(int n)
{
	size_t	ret;

	ret = 0;
	if (n == INT_MIN)
		return (ft_putstr("-2147483648"));
	if (n < 0)
	{
		ret = ft_putchar('-') > 0 ? 1 : -1;
		n = -n;
	}
	if (n / 10 > 0)
		ret += ft_putnbr(n / 10);
	return (ft_putchar(n % 10 + 48) > 0 ? ret + 1 : -1);
}
