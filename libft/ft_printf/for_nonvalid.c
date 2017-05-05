/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_nonvalid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimonov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 15:47:35 by nsimonov          #+#    #+#             */
/*   Updated: 2017/02/23 18:39:10 by nsimonov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	work_with_wmn(char nb, t_mod *mod)
{
	my_putchar(nb);
	while ((mod->width - 1) > 0)
	{
		mod->zero ? my_putchar('0') : my_putchar(' ');
		mod->width--;
	}
}

void	work_with_elsen(char nb, t_mod *mod)
{
	while ((mod->width - 1) > 0)
	{
		mod->zero ? my_putchar('0') : my_putchar(' ');
		mod->width--;
	}
	my_putchar(nb);
}

void	for_nonvalid(char format, t_mod *mod)
{
	char nb;

	nb = format;
	if ((mod->width || mod->wildcart) && (mod->min))
		work_with_wmn(nb, mod);
	else
		work_with_elsen(nb, mod);
}
