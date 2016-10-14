/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 20:34:02 by auverneu          #+#    #+#             */
/*   Updated: 2016/09/22 20:18:40 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** man 3 strlen
*/

size_t		ft_strlen(const char *s)
{
	size_t	size;

	size = 0;
	while (*(s++))
		size++;
	return (size);
}
