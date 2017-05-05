/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimonov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 20:32:14 by nsimonov          #+#    #+#             */
/*   Updated: 2016/12/15 12:07:51 by nsimonov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char			*ft_strrev(char *str)
{
	int				i;
	int				len;
	char			temp;

	len = ft_strlen(str) - 1;
	i = 0;
	if (str[i] == '-')
		i++;
	while (len > i)
	{
		temp = str[len];
		str[len] = str[i];
		str[i] = temp;
		len--;
		i++;
	}
	return (str);
}

static int			ft_lnm(int n)
{
	int				count;
	unsigned int	i;

	count = 0;
	if (n > 0)
		i = n;
	if (n < 0)
	{
		i = -n;
		count++;
	}
	if (n == 0)
		return (1);
	while (i > 0)
	{
		i = i / 10;
		count++;
	}
	return (count);
}

char				*ft_itoa(int n)
{
	int				i;
	char			*str;
	unsigned int	j;

	i = 0;
	str = (char *)malloc(sizeof(char) * (ft_lnm(n) + 1));
	if (str == NULL)
		return (NULL);
	if (n >= 0)
		j = n;
	if (n < 0)
	{
		str[i] = '-';
		i++;
		j = -n;
	}
	while (j > 9)
	{
		str[i] = (j % 10) + '0';
		j = j / 10;
		i++;
	}
	str[i++] = j + '0';
	str[i] = '\0';
	return (ft_strrev(str));
}
