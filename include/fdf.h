/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 04:28:30 by auverneu          #+#    #+#             */
/*   Updated: 2016/10/14 18:41:05 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <libftg.h>
# include <libft.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

# define FDF_BASE_NAME	"fdf"
# define FDF_BASE_GRAD1	0x000000FF
# define FDF_BASE_GRAD2	0x00FF0000
# define FDF_BASE_COL	0x00FFFFFF
# define FDF_BASE_BG	0x0000101B
# define FDF_BASE_W		1000
# define FDF_BASE_H		1000
# define FDF_MAX_W		2560
# define FDF_MAX_H		1440
# define FDF_ARGS		"W:H:n:c:g:b:h"

enum
{
	FDF_E_SUCCESS,
	FDF_E_USE,
	FDF_E_STD,
	FDF_E_INVARG,
	FDF_E_ARGMIN,
	FDF_E_ARGPATH,
	FDF_E_PARSEFAIL,
	FDF_E_PARSEMAP
};

typedef struct			s_scale
{
	t_point				scale;
	t_point				offset;
}						t_scale;

typedef struct			s_opt
{
	char				*name;
	char				*path;
	int					width;
	int					height;
	unsigned int		color;
	unsigned int		background;
	t_grad				grad;
}						t_opt;

typedef struct			s_map
{
	char				color;
	int					x_max;
	int					y_max;
	int					z_max;
	int					z_min;
	int					*z;
	int					*colors;
}						t_map;

typedef struct			s_fdf
{
	void				*mlx;
	void				*win;
	void				*img;
	void				*bg;
	t_map				*map;
	t_scale				scale;
	t_opt				opts;
}						t_fdf;

void					fdf_get_colors(t_fdf *fdf);
void					fdf_parse_args(int ac, char **av, t_fdf *fdf);
void					fdf_parse_map(t_fdf *fdf);
void					fdf_scale_img(t_fdf *fdf);
void					fdf_exit(int err, t_fdf *fdf);

int						fdf_key_p_callback(int keycode, t_fdf *fdf);
int						fdf_key_r_callback(int keycode, t_fdf *fdf);
int						fdf_destroy_callback(t_fdf *fdf);
int						fdf_print_map(t_fdf *fdf);

#endif
