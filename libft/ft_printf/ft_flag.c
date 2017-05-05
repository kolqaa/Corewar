/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimonov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 16:17:41 by nsimonov          #+#    #+#             */
/*   Updated: 2017/02/20 18:33:09 by nsimonov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_flag(const char *format, int *i, t_mod *mod, va_list arg)
{
	if (format[*i] == '-')
		mod->min = 1;
	if (format[*i] == '+')
		mod->plu = 1;
	if (format[*i] == '#')
		mod->okto = 1;
	if (format[*i] == '0')
		mod->zero = 1;
	if (format[*i] == ' ')
		mod->space = 1;
	if (format[*i] == '*' && format[*i - 1] != '.')
	{
		mod->wildcart = 1;
		mod->width = va_arg(arg, int);
	}
	if (format[*i] == '*' && format[*i - 1] == '.')
	{
		mod->wildcart = 1;
		mod->precnum = va_arg(arg, int);
	}
	if (mod->min || mod->plu || mod->okto || mod->zero ||
		mod->space || mod->wildcart)
		return (1);
	return (0);
}
