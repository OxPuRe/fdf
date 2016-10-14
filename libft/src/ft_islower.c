/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_islower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 18:02:51 by auverneu          #+#    #+#             */
/*   Updated: 2016/10/04 18:06:32 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** man 3 islower
*/

int	ft_islower(int c)
{
	if (c >= 97 && c <= 122)
		return (1);
	return (0);
}
