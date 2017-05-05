/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimonov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 16:10:57 by nsimonov          #+#    #+#             */
/*   Updated: 2016/11/30 12:53:05 by nsimonov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int i;
	int newlen;

	newlen = len - ft_strlen(little);
	i = 0;
	while (big[i] && i <= newlen)
	{
		if (!(ft_strncmp(&big[i], little, ft_strlen(little))))
			return ((char *)big + i);
		i++;
	}
	return (0);
}
