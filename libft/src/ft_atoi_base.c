/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 15:54:53 by auverneu          #+#    #+#             */
/*   Updated: 2016/10/17 18:12:52 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

unsigned int		ft_atoi_base(char *str, int base)
{
	unsigned int	nb;
	int				i;

	nb = 0;
	i = 0;
	
	while (str[i] == '\n' || str[i] == ' ' || str[i] == '\r' ||
			str[i] == '\f' || str[i] == '\v' || str[i] == '\t')
		i++;
	while ((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'a' && str[i] <= 'f')
		|| (str[i] >= 'A' && str[i] <= 'F'))
		i++;
	while ((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'a' && str[i] <= 'f')
		|| (str[i] >= 'A' && str[i] <= 'F'))
	{
		if (str[i] >= '0' && str[i] <= '9')
			nb = nb * base + str[i] - '0';
		else if (str[i] >= 'a' && str[i] <= 'f')
			nb = nb * base + str[i] - 'a' + 10;
		else if (str[i] >= 'A' && str[i] <= 'F')
			nb = nb * base + str[i] - 'A' + 10;
		i++;
	}
	return (nb);
}
