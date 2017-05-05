/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimonov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 12:37:34 by nsimonov          #+#    #+#             */
/*   Updated: 2016/12/05 22:13:56 by nsimonov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	int		i;
	int		overall;
	int		end;
	int		begin;
	char	*str;

	if (s == NULL)
		return (NULL);
	end = ft_strlen(s) - 1;
	while (s[end] == ' ' || s[end] == '\n' || s[end] == '\t')
		end--;
	begin = 0;
	while ((s[begin] == ' ' || s[begin] == '\n' ||
			s[begin] == '\t') && (begin <= end))
		begin++;
	overall = end - begin + 1;
	str = (char *)malloc(overall * sizeof(char) + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < overall)
		str[i++] = s[begin++];
	str[i] = '\0';
	return (str);
}
