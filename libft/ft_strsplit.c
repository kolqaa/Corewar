/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimonov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 14:28:39 by nsimonov          #+#    #+#             */
/*   Updated: 2016/12/15 12:09:25 by nsimonov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_wrdct(char const *s, char c)
{
	int			i;
	int			count;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			count++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (count);
}

static	int		ft_letcount(char const *s, char c)
{
	int			i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
	}
	return (i);
}

static char		**ft_write(const char *s1, char **s2, int *j, char c)
{
	int			z;

	z = 0;
	while (*s1 != c && *s1 != '\0')
	{
		s2[*j][z] = *s1;
		z++;
		s1++;
	}
	s2[*j][z] = '\0';
	(*j)++;
	return (s2);
}

char			**ft_strsplit(char const *s, char c)
{
	int			i;
	int			j;
	int			z;
	char		**ar;

	if (s == NULL)
		return (NULL);
	if ((ar = (char **)malloc(sizeof(char *) * (ft_wrdct(s, c) + 1))) == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		z = ft_letcount(&s[i], c);
		ar[j] = (char *)malloc(sizeof(char) * (z + 1));
		ar = ft_write(&(s[i]), ar, &j, c);
		i = z + i;
	}
	ar[j] = 0;
	return (ar);
}
