/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 17:20:25 by auverneu          #+#    #+#             */
/*   Updated: 2016/09/15 17:02:22 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static void		ft_tool(t_strc *gnl, int fd, int i)
{
	t_strc		*tmp;
	t_strc		*tmp2;

	if (i == 1)
	{
		tmp = gnl;
		while (tmp && tmp->fd != fd)
		{
			tmp2 = tmp;
			tmp = tmp->next;
		}
		tmp2->next = tmp->next;
		if (tmp->buf != NULL)
			ft_memdel((void **)&(tmp->buf));
		if (tmp->rest != NULL)
			ft_memdel((void **)&(tmp->rest));
		if (tmp != NULL)
			ft_memdel((void **)&(tmp));
		return ;
	}
	gnl->pos = (ft_strchr(gnl->buf, '\n') + 1) - gnl->buf;
	gnl->rest = ft_memalloc(gnl->buf - ft_strchr(gnl->buf, '\n'));
	if ((gnl->rest = ft_strchr(gnl->buf, '\n') + 1)[0] == '\0')
		gnl->rest = NULL;
	gnl->tmp = ft_strsub(gnl->buf, 0, (gnl->pos - 1));
}

static t_strc	*create_strc(int fd)
{
	t_strc	*new;

	if ((new = (t_strc *)ft_memalloc(sizeof(t_strc))))
	{
		if (!(new->buf = ft_memalloc(BUFF_SIZE + 1)))
		{
			ft_memdel((void **)&new);
			return (NULL);
		}
		new->fd = fd;
	}
	return (new);
}

static int		rd(t_strc *sv, int fd, char **line, char *tmp2)
{
	if (sv->ret == 0)
		return (0);
	while ((ft_strchr(sv->rest, '\n')) == NULL && sv->ret != 0)
	{
		sv->ret = read(fd, tmp2, BUFF_SIZE);
		tmp2[sv->ret] = '\0';
		sv->rest = ft_strjoin(sv->rest, tmp2);
	}
	if ((ft_strchr(sv->rest, '\n')) != NULL)
	{
		sv->pos = (ft_strchr(sv->rest, '\n') + 1) - sv->rest;
		sv->tmp = ft_strsub(sv->rest, 0, (sv->pos - 1));
		sv->rest = sv->rest + sv->pos;
		if (sv->rest[0] == '\0')
			sv->rest = NULL;
	}
	else
	{
		sv->tmp = sv->rest;
		sv->rest = NULL;
	}
	*line = sv->tmp;
	return (1);
}

static int		rd2(t_strc *sv, int fd, char **line, char *tmp2)
{
	if (sv->rest)
		return (rd(sv, fd, line, tmp2));
	if ((sv->ret = read(fd, sv->buf, BUFF_SIZE)) < 0)
		return (-1);
	if (sv->ret == 0)
		return (0);
	sv->buf[sv->ret] = '\0';
	while ((ft_strchr(sv->buf, '\n')) == NULL && sv->ret != 0)
	{
		sv->ret = read(fd, tmp2, BUFF_SIZE);
		tmp2[sv->ret] = '\0';
		sv->tmp = sv->buf;
		sv->buf = ft_strjoin(sv->buf, tmp2);
		ft_memdel((void **)&sv->tmp);
	}
	if (sv->ret != 0)
		ft_tool(sv, fd, 2);
	else
	{
		sv->tmp = sv->buf;
		sv->buf = NULL;
	}
	*line = sv->tmp;
	return (1);
}

int				ft_gnl(int const fd, char **line)
{
	static t_strc	*gnl;
	t_strc			*sv;
	char			*tmp2;
	int				ret;

	if (fd < 0 || line == NULL)
		return (-1);
	*line = NULL;
	tmp2 = ft_memalloc(BUFF_SIZE + 1);
	if (!gnl)
		gnl = create_strc(fd);
	sv = gnl;
	while (sv->next && sv->fd != fd)
		sv = sv->next;
	if (sv->fd != fd)
	{
		sv->next = create_strc(fd);
		sv = sv->next;
	}
	ret = rd2(sv, fd, line, tmp2);
	if (tmp2)
		ft_memdel((void **)&tmp2);
	if (ret == 0 && sv->rest)
		ft_tool(gnl, sv->fd, 1);
	return (ret);
}
