/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 16:12:54 by auverneu          #+#    #+#             */
/*   Updated: 2016/10/07 00:04:38 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** This function iterate the given function on the given linked list and store
** the result in a new linked list.
*/

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;

	new = (t_list*)malloc(sizeof(t_list));
	new = (*f)(lst);
	if (lst->next)
		new->next = ft_lstmap(lst->next, f);
	return (new);
}
