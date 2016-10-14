/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_iso_seg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 03:46:47 by auverneu          #+#    #+#             */
/*   Updated: 2016/10/14 19:51:01 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftg.h>

t_seg				ft_get_iso_seg(t_seg seg, t_point scale, t_point offset)
{
	seg.p1 = ft_get_iso_pt(seg.p1, scale, offset);
	seg.p2 = ft_get_iso_pt(seg.p2, scale, offset);
	return (seg);
}
