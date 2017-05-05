/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint_chr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimonov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 11:44:16 by nsimonov          #+#    #+#             */
/*   Updated: 2016/12/15 15:12:41 by nsimonov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstprint_chr(t_list **alst)
{
	t_list *head;

	head = *alst;
	while (head != NULL)
	{
		ft_putstr(head->content);
		head = head->next;
		ft_putchar('\n');
	}
}
