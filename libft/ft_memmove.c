/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimonov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 19:55:37 by nsimonov          #+#    #+#             */
/*   Updated: 2016/12/05 21:00:09 by nsimonov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*dst1;
	unsigned char	*src1;

	dst1 = (unsigned char *)dst;
	src1 = (unsigned char *)src;
	i = 0;
	if (src1 < dst1)
	{
		while (len > i)
		{
			dst1[len - 1] = src1[len - 1];
			len--;
		}
	}
	else
		i = 0;
	while (i < len)
	{
		dst1[i] = src1[i];
		i++;
	}
	return (dst1);
}
