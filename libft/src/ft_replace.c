/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 17:52:57 by auverneu          #+#    #+#             */
/*   Updated: 2016/09/22 20:17:08 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** This function replace each occurence of the char repl by the char sub in
** the given length.
** Return: 1.
*/

int			ft_replace(char *str, char repl, char sub, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		if (*(str + i) == repl)
			*(str + i) = sub;
		i++;
	}
	return (1);
}
