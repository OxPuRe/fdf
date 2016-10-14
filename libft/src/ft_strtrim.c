/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 17:20:14 by auverneu          #+#    #+#             */
/*   Updated: 2016/09/22 20:26:13 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** This function copy the string without the starting and ending blank spaces,
** \n and \t.
** Return:	The new string without blanks spaces.
**			NULL if there is an error in memory allocation.
*/

char		*ft_strtrim(const char *s)
{
	size_t	end;
	size_t	start;
	char	*dest;

	if (!s)
		return (NULL);
	start = 0;
	end = ft_strlen(s) - 1;
	while (*(s + start) == ' ' || *(s + start) == '\n' || *(s + start) == '\t')
		start++;
	if (start == end)
		return ("");
	while (*(s + end) == ' ' || *(s + end) == '\n' || *(s + end) == '\t')
		end--;
	dest = ft_strndup(s + start, end - start + 1);
	return (dest);
}
