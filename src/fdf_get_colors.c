/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_get_colors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 20:29:23 by auverneu          #+#    #+#             */
/*   Updated: 2016/10/14 19:51:01 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void			fdf_get_colors(t_fdf *fdf)
{
	size_t		i;
	size_t		max;

	i = 0;
	max = (size_t)((fdf->map)->x_max * (fdf->map)->y_max);
	while (i < max)
	{
		(fdf->map)->colors[i] = ft_get_col_grad(fdf->opts.grad, (fdf->map)->z[i]
			- (fdf->map)->z_min, (fdf->map)->z_max - (fdf->map)->z_min);
		i++;
	}
}
