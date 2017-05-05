/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddlast.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimonov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 16:40:18 by nsimonov          #+#    #+#             */
/*   Updated: 2016/12/15 15:12:18 by nsimonov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddlast(t_list **alst, t_list *new)
{
	t_list *temp;

	if (*alst == NULL)
	{
		*alst = new;
		return ;
	}
	temp = *alst;
	while (temp->next)
	{
		temp = temp->next;
	}
	temp->next = new;
}
