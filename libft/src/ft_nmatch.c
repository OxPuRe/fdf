/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nmatch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 23:06:26 by auverneu          #+#    #+#             */
/*   Updated: 2016/09/22 20:16:29 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int			ft_nmatch(char *s1, char *s2)
{
	if (*s1 != '\0' && *s2 == '*')
		return (ft_nmatch(s1 + 1, s2) + ft_nmatch(s1, s2 + 1));
	else if (*s1 == '\0' && *s2 == '*')
		return (ft_nmatch(s1, s2 + 1));
	else if (*s1 == *s2 && *s1 != '\0' && *s2 != '\0')
		return (ft_nmatch(s1 + 1, s2 + 1));
	else if (*s1 == *s2 && *s1 == '\0' && *s2 == '\0')
		return (1);
	return (0);
}
