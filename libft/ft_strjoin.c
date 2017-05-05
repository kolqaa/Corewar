/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimonov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 19:53:16 by nsimonov          #+#    #+#             */
/*   Updated: 2016/12/05 21:52:55 by nsimonov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		j;
	int		k;
	int		lenofs1;
	size_t	len;
	char	*str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	lenofs1 = ft_strlen(s1);
	len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(len * sizeof(char) + 1);
	if (str == NULL)
		return (NULL);
	j = 0;
	k = 0;
	while (s1[k])
		str[j++] = s1[k++];
	k = 0;
	while (s2[k])
		str[lenofs1++] = s2[k++];
	str[lenofs1] = '\0';
	return (str);
}
