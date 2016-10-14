/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 09:45:21 by auverneu          #+#    #+#             */
/*   Updated: 2016/10/14 18:24:46 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static void	fdf_print_usage()
{
	ft_putendl_fd("Usage:\n"
		"-W:\n\tuse the next argument as the width of the window\n"
		"-H:\n\tuse the next argument as the height of the window\n"
		"-n:\n\tuse the next argument as the name of the window\n"
		"-c:\n\tuse the next argument as the color of the map\n"
		"-g:\n\tuse the next argument as the gradient to generate colors\n"
		"-b:\n\tuse the next argument as the background color of the window\n"
		"-h:\n\tprint this help\n", 1);
}

static void	fdf_free_fdf(t_fdf *fdf)
{
	if (fdf->map != NULL)
	{
		if ((fdf->map)->z != NULL)
			free((fdf->map)->z);
		if ((fdf->map)->colors != NULL)
			free((fdf->map)->colors);
		free(fdf->map);
	}
	if (fdf->mlx != NULL)
	{
		mlx_destroy_image(fdf->mlx, fdf->img);
		mlx_destroy_window(fdf->mlx, fdf->win);
	}
}

void		fdf_exit(int err, t_fdf *fdf)
{
	if (fdf != NULL)
		fdf_free_fdf(fdf);
	if (err == FDF_E_USE)
		fdf_print_usage();
	else if (err == FDF_E_STD)
		perror(NULL);
	else if (err == FDF_E_INVARG)
		ft_putendl_fd("Invalid argument.", 2);
	else if (err == FDF_E_ARGMIN)
		ft_putendl_fd("Error you must provide a least 1 argument.", 2);
	else if (err == FDF_E_ARGPATH)
		ft_putendl_fd("Please provide a path to the map file.", 2);
	else if (err == FDF_E_PARSEFAIL)
		ft_putendl_fd("One value is missing.", 2);
	else if (err == FDF_E_PARSEMAP)
		ft_putendl_fd("Error in map file.", 2);
	exit(err >= FDF_E_USE ? err - 1 : err);
}
