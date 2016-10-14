/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 20:02:14 by auverneu          #+#    #+#             */
/*   Updated: 2016/09/22 20:16:57 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** This function write the given string to the given file descriptor.
** Return:	The number of chars written
**			-1 if an error occured
*/

size_t		ft_putstr_fd(const char *s, int fd)
{
	size_t	len;

	len = ft_strlen(s);
	return (write(fd, s, len));
}
