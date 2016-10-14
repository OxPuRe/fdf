/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 02:46:28 by auverneu          #+#    #+#             */
/*   Updated: 2016/09/01 00:43:10 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** This function revert the given string.
** Return: the original string reverted.
*/

char	*ft_strrev(char *s)
{
	return (ft_strnrev(s, 0, ft_strlen(s)));
}
