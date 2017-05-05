/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimonov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 13:09:45 by nsimonov          #+#    #+#             */
/*   Updated: 2016/12/15 12:44:40 by nsimonov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *head;

	if (lst == NULL || f == NULL)
		return (NULL);
	new = f(lst);
	head = new;
	while (lst->next != NULL)
	{
		lst = lst->next;
		new->next = f(lst);
		new = new->next;
	}
	return (head);
}
