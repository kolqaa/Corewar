/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_p.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimonov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 13:37:00 by nsimonov          #+#    #+#             */
/*   Updated: 2017/02/23 18:21:43 by nsimonov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	work_with_wmp(long long nb, t_mod *mod, char format)
{
	long long tmp;

	if (mod->precnum > lennum16(nb))
		tmp = mod->precnum + 2;
	else
		tmp = lennum16(nb) + 2;
	my_putstr("0x");
	while (mod->precnum-- > lennum16(nb))
		my_putchar('0');
	my_itoa_base(nb, 16, format);
	while (mod->width-- > tmp)
		my_putchar(' ');
}

void	work_with_elsep(long long nb, t_mod *mod, char format)
{
	long long tmp;

	if (mod->precnum > lennum16(nb))
		tmp = mod->precnum + 2;
	else
		tmp = lennum16(nb) + 2;
	if (mod->okto && nb != 0 && mod->precision != 1)
		tmp = tmp + 2;
	while (mod->width > tmp)
	{
		my_putchar(' ');
		mod->width--;
	}
	my_putstr("0x");
	while ((mod->precnum - lennum16(nb)) > 0)
	{
		my_putchar('0');
		mod->precnum--;
	}
	if (nb != 0)
		my_itoa_base(nb, 16, format);
	else if (mod->width || mod->precnum > 0)
		my_putchar('0');
}

void	for_p(char format, va_list arg, t_mod *mod)
{
	long long nb;

	nb = va_arg(arg, unsigned long);
	if ((mod->width || mod->wildcart) && (mod->min))
		work_with_wmp(nb, mod, format);
	else
		work_with_elsep(nb, mod, format);
}
