/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_seg_put_img.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 22:41:50 by auverneu          #+#    #+#             */
/*   Updated: 2016/10/13 13:46:16 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftg.h>

static unsigned int	ft_abs(int n)
{
	return ((n > 0) ? (unsigned int)n : (unsigned int)-n);
}

static t_point		ft_get_inc(t_seg seg)
{
	t_point			inc;

	inc.x = (seg.p2.x - seg.p1.x > 0) ? 1 : -1;
	inc.y = (seg.p2.y - seg.p1.y > 0) ? 1 : -1;
	return (inc);
}

static int			ft_seg_put_x(void *img, t_seg seg, t_point delt, t_grad g)
{
	int				cumul;
	int				i;
	int				ret;
	unsigned int	color;
	t_point			inc;

	inc = ft_get_inc(seg);
	cumul = delt.x / 2;
	color = g.color_p1;
	ret = 1;
	i = 1;
	while (i <= delt.x)
	{
		seg.p1.x += inc.x;
		cumul += delt.y;
		if (cumul >= delt.x)
		{
			cumul -= delt.x;
			seg.p1.y += inc.y;
		}
		color = ft_get_col_grad(g, i, delt.x);
		ret = (ft_pixel_put_img(img, seg.p1, color)) ? ret : 0;
		i++;
	}
	return (ret);
}

static int			ft_seg_put_y(void *img, t_seg seg, t_point delt, t_grad g)
{
	int				cumul;
	int				i;
	int				ret;
	unsigned int	color;
	t_point			inc;

	inc = ft_get_inc(seg);
	cumul = delt.y / 2;
	color = g.color_p1;
	ret = 1;
	i = 1;
	while (i <= delt.y)
	{
		seg.p1.y += inc.y;
		cumul += delt.x;
		if (cumul >= delt.y)
		{
			cumul -= delt.y;
			seg.p1.x += inc.x;
		}
		color = ft_get_col_grad(g, i, delt.y);
		ret = (ft_pixel_put_img(img, seg.p1, color)) ? ret : 0;
		i++;
	}
	return (ret);
}

int					ft_seg_put_img(void *img, t_seg seg, t_grad gradient)
{
	int				ret;
	t_point			delt;

	delt.x = ft_abs(seg.p2.x - seg.p1.x);
	delt.y = ft_abs(seg.p2.y - seg.p1.y);
	ret = ft_pixel_put_img(img, seg.p1, gradient.color_p1);
	if (delt.x > delt.y)
		ret = (ft_seg_put_x(img, seg, delt, gradient)) ? ret : 0;
	else
		ret = (ft_seg_put_y(img, seg, delt, gradient)) ? ret : 0;
	return (ret);
}
