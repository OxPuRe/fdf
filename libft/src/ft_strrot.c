/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 20:13:38 by auverneu          #+#    #+#             */
/*   Updated: 2016/09/01 00:35:40 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** This function left rotate the given string str the given (rot) times. If n is
** a negative value the function perform a rotation by right, if n is a positive
** value the function perform a rotation by left.
** Return:	The given str rotated.
*/

char			*ft_strrot(char *str, ssize_t n)
{
	size_t		len;
	size_t		rev;

	len = ft_strlen(str);
	if (n % (signed)len < 0)
		rev = len + n % (signed)len;
	else
		rev = n % (signed)len;
	if (n)
	{
		ft_strnrev(str, 0, rev);
		ft_strnrev(str, rev, len);
		ft_strnrev(str, 0, len);
	}
	return (str);
}
