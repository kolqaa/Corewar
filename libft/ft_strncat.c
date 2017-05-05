/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimonov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 16:53:44 by nsimonov          #+#    #+#             */
/*   Updated: 2016/12/05 21:57:22 by nsimonov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	count;

	j = 0;
	i = ft_strlen(s1);
	count = 0;
	while (j < n && s2[j])
		s1[i++] = s2[j++];
	s1[i] = '\0';
	return ((char *)s1);
}
