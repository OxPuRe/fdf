/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 19:55:31 by auverneu          #+#    #+#             */
/*   Updated: 2016/06/08 07:38:16 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** This function write the given string to STDOUT and terminate it by \n.
** Return:	The number of chars written
**			-1 if an error occured
*/

size_t		ft_putendl(const char *s)
{
	size_t	ret;

	ret = ft_putstr(s);
	return (write(1, "\n", 1) > 0 ? ret + 1 : -1);
}
