/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_print_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 09:47:47 by auverneu          #+#    #+#             */
/*   Updated: 2016/10/14 19:51:01 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static t_seg	set_ord(t_map *map, int i, t_grad *grad)
{
	t_seg		seg;

	seg.p1.x = i % map->x_max;
	seg.p2.x = seg.p1.x + 1;
	seg.p1.y = i / map->x_max;
	seg.p2.y = seg.p1.y;
	seg.p1.z = map->z[i];
	seg.p2.z = map->z[i + 1];
	grad->color_p1 = map->colors[i];
	grad->color_p2 = map->colors[i + 1];
	return (seg);
}

static t_seg	set_abs(t_map *map, int i, t_grad *grad)
{
	t_seg		seg;

	seg.p1.x = i % map->x_max;
	seg.p2.x = seg.p1.x;
	seg.p1.y = i / map->x_max;
	seg.p2.y = seg.p1.y + 1;
	seg.p1.z = map->z[i];
	seg.p2.z = map->z[i + map->x_max];
	grad->color_p1 = map->colors[i];
	grad->color_p2 = map->colors[i + map->x_max];
	return (seg);
}

int		fdf_print_map(t_fdf *fdf)
{
	size_t		i;
	size_t		max;
	t_seg		seg;
	t_grad		grad;

	ft_set_bg_img(fdf->img, fdf->opts.background);
	max = (size_t)(fdf->map->x_max * fdf->map->y_max);
	i = 0;
	while (i < max)
	{
		if ((i + 1) % fdf->map->x_max)
		{
			seg = set_ord(fdf->map, i, &grad);
			seg = ft_get_iso_seg(seg, fdf->scale.scale, fdf->scale.offset);
			ft_seg_put_img(fdf->img, seg, grad);
		}
		if ((i / fdf->map->x_max) - (fdf->map->y_max - 1))
		{
			seg = set_abs(fdf->map, i, &grad);
			seg = ft_get_iso_seg(seg, fdf->scale.scale, fdf->scale.offset);
			ft_seg_put_img(fdf->img, seg, grad);
		}
		i++;
	}
	return (mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0));
}
