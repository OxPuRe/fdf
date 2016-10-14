/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 18:02:32 by auverneu          #+#    #+#             */
/*   Updated: 2016/09/05 06:28:05 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** man 3 bzero
*/

void	*ft_bzero(void *s, size_t n)
{
	ft_memset((unsigned char*)s, 0, n);
	return (s);
}