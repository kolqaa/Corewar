/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimonov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 16:54:35 by nsimonov          #+#    #+#             */
/*   Updated: 2017/02/18 10:41:08 by nsimonov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_atoi(const char *str)
{
	int	sign;
	int res;

	while (*str == ' ' || *str == '\n' || *str == '\r' || *str == '\v'
	|| *str == '\f' || *str == '\t')
		str++;
	res = 0;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		else
			sign = 1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = (res * 10) + (*str - '0');
		str++;
	}
	return (res * sign);
}
