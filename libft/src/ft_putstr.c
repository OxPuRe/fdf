/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 19:41:08 by auverneu          #+#    #+#             */
/*   Updated: 2016/09/22 20:17:04 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** This function write the given string to STDOUT.
** Return:	The number of chars written
**			-1 if an error occured
*/

size_t		ft_putstr(const char *s)
{
	size_t	len;

	len = ft_strlen(s);
	return (write(1, s, len));
}
