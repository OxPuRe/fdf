/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_iso_pt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 03:34:24 by auverneu          #+#    #+#             */
/*   Updated: 2016/10/14 19:51:01 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftg.h>

t_point				ft_get_iso_pt(t_point pt, t_point scale, t_point offset)
{
	t_point			ret;

	ret.x = (pt.x - pt.y) * scale.x + offset.x;
	ret.y = (pt.x + pt.y) * scale.y - (pt.z * scale.z) + offset.y;
	return (ret);
}
