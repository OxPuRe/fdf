/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pixel_put_img.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 16:49:21 by auverneu          #+#    #+#             */
/*   Updated: 2016/10/13 13:45:07 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftg.h>

int					ft_pixel_put_img(void *img, t_point pt, unsigned int color)
{
	int				width;
	unsigned int	*imgaddr;

	width = ((t_mlx_img *)img)->width;
	if (pt.x < 0 || pt.y < 0 || pt.x >= width ||
		pt.y >= ((t_mlx_img *)img)->height)
		return (0);
	imgaddr = (unsigned int *)((t_mlx_img *)img)->buffer;
	imgaddr[(size_t)(pt.y * width + pt.x)] = color;
	return (1);
}
