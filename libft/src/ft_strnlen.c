/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 20:34:02 by auverneu          #+#    #+#             */
/*   Updated: 2016/09/22 20:19:16 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** man 3 strnlen
*/

size_t		ft_strnlen(const char *s, size_t maxlen)
{
	size_t	ret;

	ret = 0;
	while (*(s + ret) && ret < maxlen)
		ret++;
	return (ret);
}
