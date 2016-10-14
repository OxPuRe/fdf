/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_col_grad.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 04:54:44 by auverneu          #+#    #+#             */
/*   Updated: 2016/10/13 13:45:07 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftg.h>

unsigned int		ft_get_col_grad(t_grad grad, int pos, int end)
{
	unsigned int	color;
	unsigned char	*col1;
	unsigned char	*col2;
	unsigned char	*final_col;

	col1 = (unsigned char *)&(grad.color_p1);
	col2 = (unsigned char *)&(grad.color_p2);
	final_col = (unsigned char*)&color;
	if (end == 0)
	{
		end = 2;
		pos = 1;
	}
	final_col[0] = col1[0] + (char)((col2[0] - col1[0]) * pos / end);
	final_col[1] = col1[1] + (char)((col2[1] - col1[1]) * pos / end);
	final_col[2] = col1[2] + (char)((col2[2] - col1[2]) * pos / end);
	final_col[3] = col1[3] + (char)((col2[3] - col1[3]) * pos / end);
	return (color);
}
