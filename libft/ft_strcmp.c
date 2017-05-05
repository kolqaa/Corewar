/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimonov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 21:24:50 by nsimonov          #+#    #+#             */
/*   Updated: 2016/12/05 21:40:51 by nsimonov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i])
	{
		if (!s1[i] && !s2[i])
			return (0);
		i++;
	}
	if (s1[i] != s2[i] && (s1[i] > s2[i] || s2[i] > s1[i]))
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}
