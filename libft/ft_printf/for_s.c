/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_s.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimonov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 14:58:33 by nsimonov          #+#    #+#             */
/*   Updated: 2017/02/23 18:11:13 by nsimonov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	work_with_wms(char *nb, t_mod *mod)
{
	int tmp;
	int i;

	i = 0;
	if (mod->precnum < 0)
		mod->precnum *= -1;
	if (mod->width < 0)
		mod->width *= -1;
	if (mod->precnum < my_strlen(nb) && mod->precision)
		tmp = mod->precnum;
	else
		tmp = my_strlen(nb);
	if (!mod->precision)
		my_putstr(nb);
	while (mod->precnum-- && nb[i])
		my_putchar(nb[i++]);
	while (mod->width-- > tmp)
		mod->zero ? my_putchar('0') : my_putchar(' ');
}

void	work_with_elses(char *nb, t_mod *mod)
{
	int	tmp;
	int	i;

	i = 0;
	if (mod->precnum < 0)
		mod->precnum *= -1;
	if (mod->width < 0)
		mod->width *= -1;
	if (mod->precnum < my_strlen(nb) && mod->precision)
		tmp = mod->precnum;
	else
		tmp = my_strlen(nb);
	while (mod->width-- > tmp)
		mod->zero ? my_putchar('0') : my_putchar(' ');
	while (mod->precnum-- && nb[i])
		my_putchar(nb[i++]);
	if (!mod->precision)
		my_putstr(nb);
}

void	for_s(va_list arg, t_mod *mod)
{
	char *nb;

	nb = va_arg(arg, char*);
	if (nb == NULL)
		nb = "(null)";
	if ((mod->width || mod->wildcart) && (mod->min || mod->width < 0))
		work_with_wms(nb, mod);
	else
		work_with_elses(nb, mod);
}
