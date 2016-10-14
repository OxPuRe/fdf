/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parse_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 01:38:02 by auverneu          #+#    #+#             */
/*   Updated: 2016/10/14 19:51:01 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static int		fdf_parseline(char *line, t_map *map, int i)
{
	while (*line)
	{
		if (ft_isdigit(*line) || *line == '-' || *line == '+')
		{
			map->z[i++] = ft_atoi(line);
			map->z_max = ft_max(map->z_max, map->z[i - 1]);
			map->z_min = ft_min(map->z_min, map->z[i - 1]);
			while (ft_isdigit(*line) || *line == '-' || *line == '+')
				line++;
			if (map->color && line[0] == ',' && line[1] == '0' &&
				(line[2] == 'x' || line[2] == 'X'))
			{
				line += 3;
				map->colors[i - 1] = ft_atoi_base(line, 16);

				while (*line && ft_strchr(FT_XDIGIT, *line) != NULL)
					line++;
			}
		}
		else
			line++;
	}
	return (i);
}

static void		fdf_parse(int fd, t_fdf *fdf)
{
	char		*line;
	size_t		i;
	size_t		size;

	size = (size_t)((fdf->map)->x_max * (fdf->map)->y_max);
	(fdf->map)->z = (int *)malloc(sizeof(int) * size);
	(fdf->map)->colors = (int *)malloc(sizeof(int) * size);
	if ((fdf->map)->z == NULL || (fdf->map)->colors == NULL)
		fdf_exit(FDF_E_STD, fdf);
	ft_memset_int((fdf->map)->colors, fdf->opts.color, size);
	i = 0;
	while (i < size)
	{
		if (ft_gnl(fd, &line) < 0)
			fdf_exit(FDF_E_STD, fdf);
		i = fdf_parseline(line, fdf->map, i);
	}
}

static int		fdf_countnb(char *line, t_map *map)
{
	int			count;

	count = 0;
	if (*line == '\0')
		return (0);
	while (*line)
	{
		if (ft_isdigit(*line) || *line == '-' || *line == '+')
		{
			while (ft_isdigit(*line) || *line == '-' || *line == '+')
				line++;
			count++;
			if (line[0] == ',' && line[1] == '0' &&
				(line[2] == 'x' || line[2] == 'X'))
			{
				line += 3;
				map->color = 1;
				while (*line && ft_strchr(FT_XDIGIT, *line) != NULL)
					line++;
			}
		}
		else
			line++;
	}
	return (count);
}

static void		fdf_parsesize(int fd, t_fdf *fdf)
{
	int			gnl;
	char		*line;

	fdf->map = (t_map *)malloc(sizeof(t_map));
	if (fdf->map == NULL)
		fdf_exit(FDF_E_STD, fdf);
	(fdf->map)->colors = NULL;
	(fdf->map)->z = NULL;
	(fdf->map)->color = 0;
	(fdf->map)->z_max = 0;
	(fdf->map)->z_min = 0;
	(fdf->map)->y_max = (ft_gnl(fd, &line) > 0) ? 1 : 0;
	(fdf->map)->x_max = fdf_countnb(line, fdf->map);
	while ((gnl = ft_gnl(fd, &line)))
	{
		if (gnl < 0)
			fdf_exit(FDF_E_STD, fdf);
		if (fdf_countnb(line, fdf->map) != (fdf->map)->x_max)
			fdf_exit(FDF_E_PARSEMAP, fdf);
		(fdf->map)->y_max++;
	}
}

void			fdf_parse_map(t_fdf *fdf)
{
	int			fd;

	fd = open(fdf->opts.path, O_RDONLY);
	if (fd < 0)
		fdf_exit(FDF_E_STD, fdf);
	fdf_parsesize(fd, fdf);
	close(fd);
	fd = open(fdf->opts.path, O_RDONLY);
	if (fd < 0)
		fdf_exit(FDF_E_STD, fdf);
	fdf_parse(fd, fdf);
	if (!(fdf->map)->color)
		fdf_get_colors(fdf);
	close(fd);
}
