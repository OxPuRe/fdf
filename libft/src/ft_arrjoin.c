/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 05:43:55 by auverneu          #+#    #+#             */
/*   Updated: 2016/08/06 03:33:24 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** This function concatenate an array of strings in a new alloced string.
** Return:	The result of the concatenatoion.
**			NULL if there is an error in allocation.
*/

char		*ft_arrjoin(char **arr, size_t size)
{
	char	*ret;
	size_t	len;
	size_t	i;

	i = 0;
	len = 0;
	while (i++ < size)
		len += ft_strlen(arr[i - 1]);
	ret = (char*)malloc((sizeof(char) + 1) * len);
	if (ret == NULL)
		return (NULL);
	i = 0;
	len = 0;
	while (i++ < size)
	{
		ft_strcpy(ret + len, arr[i - 1]);
		len += ft_strlen(arr[i - 1]);
	}
	return (ret);
}
