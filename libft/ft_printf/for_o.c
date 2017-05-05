/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_o.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimonov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 14:27:27 by nsimonov          #+#    #+#             */
/*   Updated: 2017/02/23 18:07:52 by nsimonov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	printifneed(int flag, t_mod *mod, unsigned long long nb, char format)
{
	if ((!flag) || (mod->okto && mod->precision))
	{
		if (mod->okto && nb != 0 && mod->precnum == 0)
			my_putchar('0');
		my_itoa_base(nb, 8, format);
	}
}

void	work_with_wmo(unsigned long nb, t_mod *mod, char format)
{
	unsigned long tmp;

	if (mod->precnum > lennum8(nb))
		tmp = mod->precnum;
	else
		tmp = lennum8(nb);
	while (mod->precnum-- > lennum8(nb))
		my_putchar('0');
	if (mod->okto && mod->min)
	{
		my_putchar('0');
		tmp = tmp + 1;
	}
	my_itoa_base(nb, 8, format);
	while ((unsigned long)mod->width-- > tmp)
		my_putchar(' ');
}

void	work_with_elseo(unsigned long nb, t_mod *mod, char format)
{
	unsigned int	tmp;
	int				flag;

	flag = 0;
	if (mod->precnum == 0 && nb == 0 && mod->precision)
	{
		flag = 1;
		tmp = 0;
	}
	else if (mod->precnum > lennum8(nb))
		tmp = mod->precnum;
	else
		tmp = lennum8(nb);
	if (mod->okto && nb != 0 && mod->precision != 1)
		tmp++;
	while ((unsigned long)mod->width-- > tmp)
		mod->zero ? my_putchar('0') : my_putchar(' ');
	while ((mod->precnum - lennum8(nb)) > 0)
	{
		my_putchar('0');
		mod->precnum--;
	}
	printifneed(flag, mod, nb, format);
}

void	for_o(char format, va_list arg, t_mod *mod)
{
	unsigned long long nb;

	nb = 0;
	if (mod->j)
		nb = (uintmax_t)va_arg(arg, int);
	else if (mod->ll)
		nb = va_arg(arg, unsigned long long int);
	else if (mod->l || format == 'O')
		nb = va_arg(arg, unsigned long int);
	else if (mod->z)
		nb = (size_t)va_arg(arg, int);
	else if (mod->hh)
		nb = (unsigned char)va_arg(arg, int);
	else if (mod->h)
		nb = (unsigned short int)va_arg(arg, int);
	else
		nb = va_arg(arg, unsigned int);
	if ((mod->width || mod->wildcart) && (mod->min))
		work_with_wmo(nb, mod, format);
	else
		work_with_elseo(nb, mod, format);
}
