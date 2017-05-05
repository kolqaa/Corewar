/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimonov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 14:00:01 by nsimonov          #+#    #+#             */
/*   Updated: 2017/02/23 18:34:35 by nsimonov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	print_if(int flag, long long nb, long long tmp, t_mod *mod)
{
	if (!flag)
		my_formin(nb);
	while (mod->width-- > tmp)
		my_putchar(' ');
}

void	print_sign(long long nb, t_mod *mod)
{
	if (nb < 0)
		my_putchar('-');
	else if (nb >= 0 && (mod->plu || mod->space))
		my_putchar(mod->plu ? '+' : ' ');
}

void	work_with_wm(long long nb, t_mod *mod)
{
	long long	tmp;
	int			flag;

	flag = 0;
	if (mod->width < 0)
		mod->width *= -1;
	if (mod->precnum > lennum(nb))
		tmp = mod->precnum;
	else
		tmp = lennum(nb);
	if (mod->precnum == 0 && nb == 0 && mod->precision)
	{
		flag = 1;
		tmp = 0;
	}
	if (mod->plu || mod->space || nb < 0)
		tmp++;
	if (nb < 0)
		my_putchar('-');
	else if (mod->plu || mod->space)
		mod->plu ? my_putchar('+') : my_putchar(' ');
	while (mod->precnum-- > lennum(nb))
		my_putchar('0');
	print_if(flag, nb, tmp, mod);
}

void	work_with_else(long long nb, t_mod *mod)
{
	if (mod->precnum < 0)
	{
		mod->precnum = 0;
		mod->precision = 0;
	}
	if (mod->precision)
		mod->zero = 0;
	while (mod->width - IS_SIGN > MAX(lennum(nb), mod->precnum) && !mod->zero)
	{
		my_putchar(' ');
		mod->width--;
	}
	print_sign(nb, mod);
	while ((mod->width - IS_SIGN) > lennum(nb) && mod->zero)
	{
		my_putchar('0');
		mod->width--;
	}
	while (lennum(nb) < mod->precnum)
	{
		my_putchar('0');
		mod->precnum--;
	}
	helpd(nb, mod);
}

void	for_d(char format, va_list arg, t_mod *mod)
{
	long long	nb;

	nb = 0;
	if (mod->ll)
		nb = va_arg(arg, long long);
	else if (mod->j)
		nb = (intmax_t)va_arg(arg, intmax_t);
	else if (mod->z)
		nb = (size_t)va_arg(arg, size_t);
	else if (mod->l || format == 'D')
		nb = va_arg(arg, long);
	else if (mod->hh)
		nb = (char)va_arg(arg, int);
	else if (mod->h)
		nb = (short)va_arg(arg, int);
	else
		nb = va_arg(arg, int);
	if ((mod->width || mod->wildcart) && (mod->min || mod->width < 0))
		work_with_wm(nb, mod);
	else
		work_with_else(nb, mod);
}
