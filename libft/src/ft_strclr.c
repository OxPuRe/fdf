/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 16:17:43 by auverneu          #+#    #+#             */
/*   Updated: 2016/09/22 20:04:48 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** This function set all the byte of the string s to 0.
*/

void	ft_strclr(char *s)
{
	size_t	i;

	if (!s)
		return ;
	i = 0;
	while (*(s + i))
	{
		*(s + i) = 0;
		i++;
	}
}
