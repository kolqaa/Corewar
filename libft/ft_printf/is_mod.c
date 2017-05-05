/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_mod.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimonov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 12:20:42 by nsimonov          #+#    #+#             */
/*   Updated: 2017/02/23 18:36:34 by nsimonov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	is_mod(char *format)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (format[i])
	{
		if (ft_isdigit(format[i]) == 1)
			flag = 1;
		if (is_modif(format[i]) == 1)
			flag = 1;
		if (is_flag(format[i]) == 1)
			flag = 1;
		i++;
	}
	if (flag)
		return (1);
	return (0);
}
