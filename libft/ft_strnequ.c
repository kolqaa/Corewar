/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimonov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 18:00:02 by nsimonov          #+#    #+#             */
/*   Updated: 2016/12/05 22:04:22 by nsimonov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t i;

	if (s1 == NULL || s2 == NULL)
		return (0);
	i = 0;
	while (i < n && s1[i] == s2[i])
	{
		if (!s1[i] && !s2[i])
			return (1);
		i++;
	}
	if (i == n)
		return (1);
	return (0);
}
