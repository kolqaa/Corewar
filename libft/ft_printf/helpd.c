/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimonov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 15:38:32 by nsimonov          #+#    #+#             */
/*   Updated: 2017/02/23 18:28:35 by nsimonov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	helpd(long long nb, t_mod *mod)
{
	if (nb != 0 || (nb == 0 && ((mod->precnum != 0 && mod->precision) ||
		!mod->precision)))
		my_formin(nb);
	else if (mod->width)
		my_putchar(' ');
}
