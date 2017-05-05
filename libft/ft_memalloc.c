/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimonov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 15:35:25 by nsimonov          #+#    #+#             */
/*   Updated: 2016/12/05 20:47:36 by nsimonov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memalloc(size_t size)
{
	void	*newmem;

	newmem = (void *)malloc(size);
	if (newmem == NULL)
		return (NULL);
	ft_memset(newmem, '\0', size + 1);
	return (newmem);
}
