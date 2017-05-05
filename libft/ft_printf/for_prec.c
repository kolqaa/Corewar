/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_prec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimonov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 09:35:04 by nsimonov          #+#    #+#             */
/*   Updated: 2017/02/23 18:41:48 by nsimonov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	work_with_wmpr(t_mod *mod)
{
	my_putchar('%');
	while ((mod->width - 1) > 0)
	{
		mod->zero ? my_putchar('0') : my_putchar(' ');
		mod->width--;
	}
}

void	work_with_elsepr(t_mod *mod)
{
	while ((mod->width - 1) > 0)
	{
		mod->zero ? my_putchar('0') : my_putchar(' ');
		mod->width--;
	}
	my_putchar('%');
}

void	for_prec(t_mod *mod)
{
	if ((mod->width || mod->wildcart) && (mod->min))
		work_with_wmpr(mod);
	else
		work_with_elsepr(mod);
}
