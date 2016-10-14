/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_caseeq.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 08:41:00 by auverneu          #+#    #+#             */
/*   Updated: 2016/05/30 22:24:04 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** This function make a case insensitive comaprison of 2 chars
** Return:	1 if it is the same char.
**			0 if it is not.
*/

int	ft_caseeq(char c1, char c2)
{
	if (((c1 <= 90 && c1 >= 65) && (c1 + 32 == c2)) ||
	((c2 <= 90 && c2 >= 65) && (c2 + 32 == c1)) || c1 == c2)
		return (1);
	return (0);
}
