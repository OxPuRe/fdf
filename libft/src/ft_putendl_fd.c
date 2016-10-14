/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 20:03:17 by auverneu          #+#    #+#             */
/*   Updated: 2016/09/22 18:51:07 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** This function write the given string to the given file descriptor and
** terminate it by \n.
** Return:	The number of chars written
**			-1 if an error occured
*/

size_t		ft_putendl_fd(const char *s, int fd)
{
	size_t	ret;

	ret = ft_putstr_fd(s, fd);
	return (write(fd, "\n", 1) > 0 ? ret + 1 : -1);
}
