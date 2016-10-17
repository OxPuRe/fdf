/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 17:49:07 by auverneu          #+#    #+#             */
/*   Updated: 2016/05/09 23:23:22 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char			*ft_itoa_base(int value, int base)
{
	const char	*table;
	char		*a;
	int			len;

	len = 256;
	table = "0123456789ABCDEF";
	if (value == -2147483648 && base == 10)
		return ("-2147483648");
	a = (char *)malloc(sizeof(*a) * len);
	if (a == NULL)
		return (NULL);
	a[len] = '\0';
	len--;
	if (value == 0)
	{
		a[len] = '0';
		return (&(a[len]));
	}
	if (value < 0)
	{
		if (base == 10)
			a[0] = '-';
		value = -value;
	}
	while (value >= base)
	{
		a[len] = table[value % base];
		value /= base;
		len--;
	}
	a[len] = table[value % base];
	if (a[0] == '-')
		a[--len] = '-';
	return (&(a[len]));
}
