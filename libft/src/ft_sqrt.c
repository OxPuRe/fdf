/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 18:59:06 by auverneu          #+#    #+#             */
/*   Updated: 2016/05/30 22:56:51 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** This function return the square root of the given number.
** Return: the square root of the number n.
*/

int		ft_sqrt(int n)
{
	if (n / 2 > 2)
		return (ft_sqrt(n / 2) + 1);
	else
		return (1);
}
