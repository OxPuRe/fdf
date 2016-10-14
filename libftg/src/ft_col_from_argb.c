/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_col_from_argb.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 05:29:52 by auverneu          #+#    #+#             */
/*   Updated: 2016/10/10 06:12:41 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftg.h>

unsigned int	ft_col_from_argb(unsigned char a, unsigned char r,
				unsigned char g, unsigned char b)
{
	return ((unsigned int)(a << 24U) + (unsigned int)(r << 16U) +
		(unsigned int)(g << 8U) + (unsigned int)b);
}
