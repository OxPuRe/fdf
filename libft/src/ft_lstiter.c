/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 15:48:10 by auverneu          #+#    #+#             */
/*   Updated: 2016/10/07 00:05:28 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** This function iterate the given function on the given linked list.
*/

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	(*f)(lst);
	if (lst->next)
		ft_lstiter(lst->next, f);
}
