/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 03:51:06 by auverneu          #+#    #+#             */
/*   Updated: 2016/05/30 22:40:53 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** This function free the given pointer and set it to NULL.
*/

void	ft_memdel(void **ap)
{
	free(*ap);
	*ap = NULL;
}
