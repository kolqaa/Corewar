/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimonov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 13:26:01 by nsimonov          #+#    #+#             */
/*   Updated: 2016/12/05 21:53:56 by nsimonov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	int		i;
	int		j;
	size_t	k;
	int		raznica;

	raznica = size - ft_strlen(dst) - 1;
	if (raznica <= 0)
		return (size + ft_strlen(src));
	i = ft_strlen(dst);
	j = 0;
	k = ft_strlen(dst) + ft_strlen(src);
	while (src[j] && j < raznica)
	{
		dst[i++] = src[j++];
	}
	dst[i] = '\0';
	return (k);
}
