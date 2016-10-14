/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 10:44:13 by auverneu          #+#    #+#             */
/*   Updated: 2016/10/10 11:13:39 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** atoi with a radix
*/

unsigned int		ft_atoi_base(const char *str, unsigned int base)
{
	unsigned int	nb;
	unsigned int	ret;

	ret = 0;
	if (base <= 1 || base > 16)
		return (0);
	while (ft_isspace(*str))
		str++;
	while (*str && ft_strchr(FT_XDIGIT, *str) != NULL)
	{
		if (*str >= '0' && *str <= '9')
			nb = *str - '0';
		else if (*str >= 'a' && *str <= 'f')
			nb = *str - 'a' + 10;
		else if (*str >= 'A' && *str <= 'F')
			nb = *str - 'A' + 10;
		else
			return (0);
		if (nb >= base)
			return (0);
		ret = ret * base + nb;
		str++;
	}
	return (ret);
}
