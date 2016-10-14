/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parse_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 14:23:01 by auverneu          #+#    #+#             */
/*   Updated: 2016/10/14 19:51:01 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static unsigned int	fdf_get_color_from_str(char *str)
{
	unsigned int	color;

	if (str && str[0] == '0' && (str[1] == 'x' || str[1] == 'X'))
		color = ft_atoi_base(str + 2, 16);
	else
		color = ft_atoi_base(str, 10);
	return (color);
}

static t_grad		fdf_get_grad_from_str(char *str)
{
	char			*ch_at;
	t_grad			gradient;

	ch_at = ft_strchr(str, ',');
	gradient.color_p1 = fdf_get_color_from_str(str);
	if (ch_at != NULL)
		gradient.color_p2 = fdf_get_color_from_str(ch_at + 1);
	else
		gradient.color_p2 = gradient.color_p1;
	return (gradient);
}

static void			fdf_add_opt(char ch, char *value, t_fdf *fdf)
{
	int				tmp;

	if (ch == 'W')
	{
		tmp = ft_atoi(value);
		fdf->opts.width = (tmp > 0 && tmp <= FDF_MAX_W) ?
			tmp : fdf->opts.width;
	}
	else if (ch == 'H')
	{
		tmp = ft_atoi(value);
		fdf->opts.height = (tmp > 0 && tmp <= FDF_MAX_H) ?
			tmp : fdf->opts.height;
	}
	else if (ch == 'n')
		fdf->opts.name = value;
	else if (ch == 'c')
		fdf->opts.color = fdf_get_color_from_str(value);
	else if (ch == 'g')
		fdf->opts.grad = fdf_get_grad_from_str(value);
	else if (ch == 'b')
		fdf->opts.background = fdf_get_color_from_str(value);
	else if (ch == 'h')
		fdf_exit(FDF_E_USE, fdf);
}

static int			fdf_parse_opt(int ac, char **av, int pos, t_fdf *fdf)
{
	size_t			i;
	char			*ch_at;

	i = 1;
	while (av[pos][i])
	{
		ch_at = ft_strchr(FDF_ARGS, av[pos][i]);
		if (ch_at != NULL && *ch_at)
		{
			if (pos + 1 < ac && ch_at[1] == ':' && av[pos][i + 1] == '\0')
			{
				fdf_add_opt(av[pos][i], av[pos + 1], fdf);
				return (1);
			}
			else if (ch_at[1] == ':')
				fdf_exit(FDF_E_PARSEFAIL, fdf);
			else
				fdf_add_opt(av[pos][i], NULL, fdf);
		}
		else
			fdf_exit(FDF_E_INVARG, fdf);
		i++;
	}
	return (0);
}

void				fdf_parse_args(int ac, char **av, t_fdf *fdf)
{
	int				i;

	fdf->opts.path = NULL;
	fdf->opts.name = FDF_BASE_NAME;
	fdf->opts.color = FDF_BASE_COL;
	fdf->opts.background = FDF_BASE_BG;
	fdf->opts.grad.color_p1 = FDF_BASE_GRAD1;
	fdf->opts.grad.color_p2 = FDF_BASE_GRAD2;
	fdf->opts.height = FDF_BASE_H;
	fdf->opts.width = FDF_BASE_W;
	i = 1;
	while (i < ac)
	{
		if (av[i][0] == '-')
			i += fdf_parse_opt(ac, av, i, fdf);
		else if (fdf->opts.path == NULL)
			fdf->opts.path = av[i];
		else
			fdf_exit(FDF_E_INVARG, fdf);
		i++;
	}
	if (fdf->opts.path == NULL)
		fdf_exit(FDF_E_ARGPATH, fdf);
}
