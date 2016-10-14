/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_bg_img.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 21:13:29 by auverneu          #+#    #+#             */
/*   Updated: 2016/10/13 13:46:49 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftg.h>

int					ft_set_bg_img(void *img, unsigned int color)
{
	size_t			i;
	size_t			size;
	unsigned int	*imgbuff;

	imgbuff = (unsigned int *)((t_mlx_img *)img)->buffer;
	size = ((t_mlx_img *)img)->width * ((t_mlx_img *)img)->height;
	i = 0;
	while (i < size)
		imgbuff[i++] = color;
	return (1);
}
