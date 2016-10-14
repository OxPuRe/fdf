/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/29 03:26:57 by auverneu          #+#    #+#             */
/*   Updated: 2016/09/22 20:15:48 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** This function elevate the given number at the given power.
** Return: The number nb elevated to the power pw.
*/

int		ft_pow(int nb, int pw)
{
	if (pw == 0)
		return (1);
	else if (pw < 0)
		return (ft_pow(nb, pw + 1) / nb);
	else
		return (nb * ft_pow(nb, pw - 1));
}
