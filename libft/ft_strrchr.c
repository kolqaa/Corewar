/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimonov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 14:24:46 by nsimonov          #+#    #+#             */
/*   Updated: 2016/12/05 22:07:01 by nsimonov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	int		i;
	int		k;
	char	*str;

	str = (char *)s;
	i = 0;
	k = 0;
	while (str[i])
		i++;
	while (i >= 0)
	{
		if (str[i] == c)
			return (&str[i]);
		i--;
	}
	if (str[i] == c)
		return (&str[i]);
	return (NULL);
}
