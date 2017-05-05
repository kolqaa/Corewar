/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_x.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimonov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 18:30:51 by nsimonov          #+#    #+#             */
/*   Updated: 2017/02/23 17:51:13 by nsimonov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	work_with_wmx(long long nb, t_mod *mod, char format)
{
	long long tmp;

	if (mod->precnum > lennum16(nb))
		tmp = mod->precnum;
	else
		tmp = lennum16(nb);
	if (mod->okto && nb != 0)
	{
		my_putstr((format == 'X' ? "0X" : "0x"));
		tmp = tmp + 2;
	}
	while (mod->precnum-- > lennum16(nb))
		my_putchar('0');
	my_itoa_base(nb, 16, format);
	while (mod->width-- > tmp)
		my_putchar(' ');
}

void	second_partx(long long nb, t_mod *mod, int flag, char format)
{
	while ((mod->precnum - lennum16(nb)) > 0)
	{
		my_putchar('0');
		mod->precnum--;
	}
	if (!flag)
		my_itoa_base(nb, 16, format);
}

void	work_with_elsex(long long nb, t_mod *mod, char format)
{
	long long	tmp;
	int			flag;

	flag = 0;
	if (mod->precnum == 0 && nb == 0 && mod->precision)
	{
		flag = 1;
		tmp = 0;
	}
	else if (mod->precnum > lennum16(nb))
		tmp = mod->precnum;
	else
		tmp = lennum16(nb);
	if (mod->okto && nb != 0 && mod->precision != 1)
		tmp = tmp + 2;
	if (mod->okto && mod->zero)
		my_putstr((format == 'X' ? "0X" : "0x"));
	while (mod->width-- > tmp)
		mod->zero ? my_putchar('0') : my_putchar(' ');
	if (mod->okto && !mod->zero && nb != 0)
		my_putstr((format == 'X' ? "0X" : "0x"));
	second_partx(nb, mod, flag, format);
}

void	for_x(char format, va_list arg, t_mod *mod)
{
	long long nb;

	nb = 0;
	if (mod->hh)
		nb = (unsigned char)va_arg(arg, int);
	else if (mod->l || format == 'X')
		nb = va_arg(arg, unsigned long int);
	else if (mod->h)
		nb = (unsigned short int)va_arg(arg, int);
	else if (mod->ll)
		nb = va_arg(arg, unsigned long long int);
	else if (mod->j)
		nb = (intmax_t)va_arg(arg, intmax_t);
	else if (mod->z)
		nb = (size_t)va_arg(arg, size_t);
	else
		nb = va_arg(arg, unsigned int);
	if ((mod->width || mod->wildcart) && (mod->min))
		work_with_wmx(nb, mod, format);
	else
		work_with_elsex(nb, mod, format);
}
