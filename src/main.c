/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 09:51:23 by auverneu          #+#    #+#             */
/*   Updated: 2016/10/14 19:51:01 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int			main(int ac, char **av)
{
	t_fdf	fdf;

	if (ac < 2)
		fdf_exit(FDF_E_ARGMIN, NULL);
	fdf.mlx = NULL;
	fdf.map = NULL;
	fdf_parse_args(ac, av, &fdf);
	fdf_parse_map(&fdf);
	fdf_scale_img(&fdf);
	fdf.mlx = mlx_init();
	fdf.win = mlx_new_window(fdf.mlx, fdf.opts.width, fdf.opts.height,
		fdf.opts.name);
	fdf.img = mlx_new_image(fdf.mlx, fdf.opts.width, fdf.opts.height);
	mlx_hook(fdf.win, 2, (1L<<0), fdf_key_p_callback, &fdf);
	mlx_hook(fdf.win, 3, (1L<<1), fdf_key_r_callback, &fdf);
	mlx_hook(fdf.win, 17, 0L, fdf_destroy_callback, &fdf);
	mlx_expose_hook(fdf.win, fdf_print_map, &fdf);
	mlx_loop(fdf.mlx);
	return (0);
}
