/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcsstrlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/05 02:58:06 by auverneu          #+#    #+#             */
/*   Updated: 2016/09/15 16:03:36 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** This function determine the lenght of a wide string converted to its unicode
** representation.
** Return:	- The lenght of the unicode representation of the given wide string.
** 			- (size_t)-1 if an error occurs
*/

size_t		ft_wcsstrlen(const wchar_t *wcs)
{
	size_t	len;
	int		wc_len;

	len = 0;
	while (*wcs)
	{
		wc_len = ft_wclen(*wcs);
		if (wc_len == -1)
			return ((size_t)-1);
		len += wc_len;
		wcs++;
	}
	return (len);
}
