/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimonov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 18:41:21 by nsimonov          #+#    #+#             */
/*   Updated: 2016/12/14 16:27:34 by nsimonov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *new;

	new = (t_list *)malloc(sizeof(*new));
	if (new == NULL)
		return (NULL);
	if (content == NULL)
	{
		new->content = NULL;
		new->next = NULL;
		new->content_size = 0;
	}
	else
	{
		new->content = (void *)malloc(content_size);
		if (new->content == NULL)
			return (NULL);
		new->content_size = content_size;
		new->content = ft_memcpy(new->content, content, content_size);
		new->next = NULL;
	}
	return (new);
}
