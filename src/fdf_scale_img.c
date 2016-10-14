/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_scale_img.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 20:34:52 by auverneu          #+#    #+#             */
/*   Updated: 2016/10/14 19:51:01 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static int		fdf_iso_pt_x(int x, int y, t_fdf *fdf)
{
	t_point		pt;

	pt.x = x;
	pt.y = y;
	pt.z = 0;
	pt = ft_get_iso_pt(pt, fdf->scale.scale, fdf->scale.offset);
	return (pt.x);
}

static void		fdf_scale_x(t_fdf *fdf)
{
	int			f;
	t_point		max;
	t_point		pt;
	t_point		tmp;

	fdf->scale.offset.y = 0;
	fdf->scale.scale.z = 0;
	max.x = fdf->opts.width + 1;
	max.y = fdf->opts.height + 1;
	pt.z = 0;
	f = 1000;
	while ((max.x > fdf->opts.width | max.y > fdf->opts.height) && f > 0)
	{
		fdf->scale.scale.x = 3 * f;
		fdf->scale.scale.y = 1 * f;
		fdf->scale.offset.x = 0;
		fdf->scale.offset.x = -fdf_iso_pt_x(0, (fdf->map)->y_max - 1, fdf);
		max.x = fdf_iso_pt_x((fdf->map)->x_max - 1, 0, fdf);
		pt.x = (fdf->map)->x_max - 1;
		pt.y = (fdf->map)->y_max - 1;
		tmp = ft_get_iso_pt(pt, fdf->scale.scale, fdf->scale.offset);
		max.y = tmp.y;
		f--;
	}
	fdf->scale.offset.x += (fdf->opts.width - max.x) / 2;
}

static void		fdf_scale_y(t_fdf *fdf)
{
	int			f;
	int			max;
	t_point		pt;
	t_point		tmp;

	max = fdf->opts.height + 1;
	f = 1000;
	while ((max > fdf->opts.height) && f > 0)
	{
		fdf->scale.offset.y = 0;
		fdf->scale.scale.z = 2 * f;
		pt.x = 0;
		pt.y = 0;
		pt.z = (fdf->map)->z_max;
		tmp = ft_get_iso_pt(pt, fdf->scale.scale, fdf->scale.offset);
		fdf->scale.offset.y = -tmp.y;
		pt.x = (fdf->map)->x_max - 1;
		pt.y = (fdf->map)->y_max - 1;
		pt.z = (fdf->map)->z_min;
		tmp = ft_get_iso_pt(pt, fdf->scale.scale, fdf->scale.offset);
		max = tmp.y;
		f--;
	}
	fdf->scale.offset.y += (fdf->opts.height - max) / 2;
}

void			fdf_scale_img(t_fdf *fdf)
{
	fdf_scale_x(fdf);
	fdf_scale_y(fdf);
}
