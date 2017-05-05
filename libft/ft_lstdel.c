/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimonov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 12:10:12 by nsimonov          #+#    #+#             */
/*   Updated: 2016/12/14 16:28:40 by nsimonov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *temp;

	if (*alst == NULL)
		return ;
	while ((*alst)->next != NULL)
	{
		temp = (*alst)->next;
		del((*alst)->content, (*alst)->content_size);
		free(*alst);
		*alst = temp;
	}
	del((*alst)->content, (*alst)->content_size);
	free(*alst);
	*alst = NULL;
}
