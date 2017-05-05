/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_u.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimonov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 18:20:34 by nsimonov          #+#    #+#             */
/*   Updated: 2017/02/23 18:47:30 by nsimonov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	work_with_wmu(unsigned long long nb, t_mod *mod)
{
	unsigned long long tmp;

	if (mod->precnum > lennum(nb))
		tmp = mod->precnum;
	else
		tmp = lennum(nb);
	while (mod->precnum-- > lennum(nb))
		my_putchar('0');
	my_forun(nb);
	while ((unsigned long)mod->width-- > tmp)
		my_putchar(' ');
}

void	work_with_elseu(unsigned long long nb, t_mod *mod)
{
	unsigned long long	tmp;
	int					flag;

	flag = 0;
	if (mod->precnum == 0 && nb == 0 && mod->precision)
	{
		flag = 1;
		tmp = 0;
	}
	if (mod->precnum > lennum(nb))
		tmp = mod->precnum;
	else
		tmp = lennum(nb);
	while ((unsigned long)mod->width-- > tmp)
		mod->zero ? my_putchar('0') : my_putchar(' ');
	while ((mod->precnum - lennum(nb)) > 0)
	{
		my_putchar('0');
		mod->precnum--;
	}
	if (!flag)
		my_forun(nb);
}

void	for_u(char format, va_list arg, t_mod *mod)
{
	unsigned long long nb;

	nb = 0;
	if (mod->j)
		nb = (uintmax_t)va_arg(arg, uintmax_t);
	else if (mod->ll)
		nb = va_arg(arg, unsigned long long int);
	else if (mod->l || format == 'U')
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
		work_with_wmu(nb, mod);
	else
		work_with_elseu(nb, mod);
}
