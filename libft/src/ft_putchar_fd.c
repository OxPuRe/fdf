/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 20:00:58 by auverneu          #+#    #+#             */
/*   Updated: 2016/09/22 18:50:58 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** This function write the given char to the given file descriptor.
** Return:	The written char
**			-1 if an error occured
*/

int		ft_putchar_fd(int c, int fd)
{
	return (write(fd, &c, 1) > 0 ? c : -1);
}
