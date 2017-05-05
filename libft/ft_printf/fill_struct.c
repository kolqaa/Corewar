/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimonov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 18:58:47 by nsimonov          #+#    #+#             */
/*   Updated: 2017/02/20 18:19:46 by nsimonov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	fill_struct(const char *format, t_mod *mod, va_list arg)
{
	int i;

	i = 0;
	while (ft_isdigit(format[i]) || is_modif(format[i]) || is_flag(format[i]))
	{
		if (ft_flag(format, &i, mod, arg) == 1)
			mod->flag = 1;
		if (ft_width(format, &i, mod) == 1)
			mod->flag = 1;
		if (ft_precision(format, &i, mod) == 1)
			mod->flag = 1;
		if (ft_lentgh(format, &i, mod) == 1)
			mod->flag = 1;
		i++;
	}
	if (mod->flag == 1)
		return (1);
	return (0);
}
