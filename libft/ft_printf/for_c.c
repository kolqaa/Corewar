/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_c.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimonov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 19:01:17 by nsimonov          #+#    #+#             */
/*   Updated: 2017/02/23 17:31:14 by nsimonov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	work_with_wmc(char nb, t_mod *mod)
{
	if (mod->precnum < 0)
		mod->precnum *= -1;
	if (mod->width < 0)
		mod->width *= -1;
	my_putchar(nb);
	while ((mod->width - 1) > 0)
	{
		mod->zero ? my_putchar('0') : my_putchar(' ');
		mod->width--;
	}
}

void	work_with_elsec(char nb, t_mod *mod)
{
	if (mod->precnum < 0)
		mod->precnum *= -1;
	if (mod->width < 0)
		mod->width *= -1;
	while ((mod->width - 1) > 0)
	{
		mod->zero ? my_putchar('0') : my_putchar(' ');
		mod->width--;
	}
	my_putchar(nb);
}

void	for_c(va_list arg, t_mod *mod)
{
	char nb;

	nb = (char)va_arg(arg, int);
	if ((mod->width || mod->wildcart) && (mod->min || mod->width < 0 ||
			mod->precnum < 0))
		work_with_wmc(nb, mod);
	else
		work_with_elsec(nb, mod);
}
