/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 18:03:36 by auverneu          #+#    #+#             */
/*   Updated: 2016/09/21 20:27:57 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** This function convert an int value to a string reprtesenting this value.
** Return:	a malloced string containing the ascii representation of the nb.
**			NULL if there is an error in memory allocation.
*/

static void	ft_tostr(unsigned int n, char *str)
{
	*str = n % 10 + 48;
	if (n / 10 != 0)
		ft_tostr(n / 10, str - 1);
}

char		*ft_itoa(int n)
{
	char	*ret;
	size_t	len;

	len = ft_ilen(n);
	ret = (char*)malloc(len + 1);
	if (ret == NULL)
		return (NULL);
	if (n < 0)
	{
		*ret = ('-');
		ft_tostr(-n, ret + (len - 1));
	}
	else
		ft_tostr(n, ret + (len - 1));
	*(ret + len) = 0;
	return (ret);
}
