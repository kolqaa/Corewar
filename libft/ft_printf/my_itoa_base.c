/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 10:23:50 by exam              #+#    #+#             */
/*   Updated: 2017/02/23 17:22:32 by nsimonov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*ft_strrev(char *array)
{
	int	i;
	int tmp;
	int len;

	i = 0;
	len = 0;
	tmp = 0;
	while (array[i++])
		len++;
	len--;
	i = 0;
	if (array[i] == '-')
		i++;
	while (i < len)
	{
		tmp = array[i];
		array[i] = array[len];
		array[len] = tmp;
		i++;
		len--;
	}
	return (array);
}

void	help_un(char *array, unsigned long long newnbr2, int base, char format)
{
	char	*bse;
	int		i;

	i = 0;
	if (format == 'X')
		bse = "0123456789ABCDEF";
	else
		bse = "0123456789abcdef";
	while (newnbr2)
	{
		array[i++] = bse[newnbr2 % base];
		newnbr2 = newnbr2 / base;
	}
	array[i] = '\0';
}

void	help_it(char *array, long long newnbr, int base, char format)
{
	char	*bse;
	int		i;

	i = 0;
	if (format == 'X')
		bse = "0123456789ABCDEF";
	else
		bse = "0123456789abcdef";
	while (newnbr)
	{
		array[i++] = bse[newnbr % base];
		newnbr = newnbr / base;
	}
	array[i] = '\0';
}

void	choose_valuecast(long long value, int base, char *array, char format)
{
	long long			newnbr;
	unsigned long long	newnbr2;

	if (value < 0)
	{
		newnbr2 = value;
		help_un(array, newnbr2, base, format);
	}
	else
	{
		newnbr = value;
		help_it(array, newnbr, base, format);
	}
	ft_strrev(array);
	my_putstr(array);
}

void	my_itoa_base(long long value, int base, char format)
{
	int		i;
	char	*array;

	if ((array = (char *)malloc(sizeof(char) * (32 + 1))) == NULL)
		return ;
	i = 0;
	if (value == 0)
	{
		array[i] = '0';
		array[i + 1] = '\0';
		my_putstr(array);
		return ;
	}
	choose_valuecast(value, base, array, format);
	free(array);
}
