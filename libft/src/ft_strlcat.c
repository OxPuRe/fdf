/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 04:57:18 by auverneu          #+#    #+#             */
/*   Updated: 2016/09/22 20:18:22 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** man 3 strlcat
*/

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len;

	len = ft_strnlen(dst, size);
	return (len + ft_strlcpy(dst + len, src, size - len));
}
