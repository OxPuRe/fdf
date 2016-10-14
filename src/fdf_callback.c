/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_callback.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 09:46:28 by auverneu          #+#    #+#             */
/*   Updated: 2016/10/14 19:51:01 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int		fdf_key_p_callback(int keycode, t_fdf *fdf)
{
	if (keycode == FT_KEY_LARROW)
		fdf->scale.offset.x -= 5;
	else if (keycode == FT_KEY_RARROW)
		fdf->scale.offset.x += 5;
	else if (keycode == FT_KEY_DARROW)
		fdf->scale.offset.y += 5;
	else if (keycode == FT_KEY_UARROW)
		fdf->scale.offset.y -= 5;
	else if (keycode == FT_KEY_PUP)
		fdf->scale.scale.z += 1;
	else if (keycode == FT_KEY_PDOWN)
		fdf->scale.scale.z -= 1;
	fdf_print_map(fdf);
	return (0);
}

int		fdf_key_r_callback(int keycode, t_fdf *fdf)
{
	if (keycode == FT_KEY_ESC)
		fdf_exit(FDF_E_SUCCESS, fdf);
	return (0);
}

int		fdf_destroy_callback(t_fdf *fdf)
{
	fdf_exit(FDF_E_SUCCESS, fdf);
	return (0);
}
