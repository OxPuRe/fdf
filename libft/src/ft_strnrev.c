/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnrev.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 00:08:33 by auverneu          #+#    #+#             */
/*   Updated: 2016/09/22 20:19:25 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** This function revert the given substring (delimited by begin and end) of the
** given string.
** Return: the original string with the substring reverted.
*/

char		*ft_strnrev(char *s, size_t begin, size_t end)
{
	char	*s1;
	char	*s2;

	if (!s || !*s)
		return (s);
	s1 = s + begin;
	s2 = s + end - 1;
	while (s1 < s2)
	{
		*s1 ^= *s2;
		*s2 ^= *s1;
		*s1 ^= *s2;
		s1++;
		s2--;
	}
	return (s);
}
