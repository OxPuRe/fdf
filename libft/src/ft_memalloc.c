/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 22:20:02 by auverneu          #+#    #+#             */
/*   Updated: 2016/09/22 20:14:46 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** This function allocate a chunk of the given size in the memory and set every
** byte to 0.
** Return:	A pointer to the allocated chunk.
**			NULL if there is an error in memory allocation.
*/

void		*ft_memalloc(size_t size)
{
	void	*ret;

	ret = malloc(size);
	if (ret)
		ft_memset(ret, 0, size);
	return (ret);
}
