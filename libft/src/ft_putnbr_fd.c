/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 20:05:29 by auverneu          #+#    #+#             */
/*   Updated: 2016/08/13 06:15:33 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** This function write the given number to the given file descriptor.
** Return:	The size of the number
**			-1 if an error occured
*/

size_t		ft_putnbr_fd(int n, int fd)
{
	size_t	ret;

	ret = 0;
	if (n == INT_MIN)
		return (ft_putstr_fd("-2147483648", fd));
	if (n < 0)
	{
		ret = ft_putchar_fd('-', fd) > 0 ? 1 : -1;
		n = -n;
	}
	if (n / 10 > 0)
		ret += ft_putnbr_fd(n / 10, fd);
	return (ft_putchar_fd(n % 10 + 48, fd) > 0 ? ret + 1 : -1);
}
