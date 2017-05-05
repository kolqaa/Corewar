/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lentgh.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimonov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 19:14:06 by nsimonov          #+#    #+#             */
/*   Updated: 2017/02/23 18:17:30 by nsimonov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_lentgh(const char *format, int *i, t_mod *mod)
{
	if (format[*i] == 'h' && format[*i + 1] != 'h' && format[*i - 1] != 'h')
		mod->h = 1;
	if (format[*i] == 'h' && format[*i + 1] == 'h')
		mod->hh = 1;
	if (format[*i] == 'j')
		mod->j = 1;
	if (format[*i] == 'z')
		mod->z = 1;
	if (format[*i] == 'l')
		mod->l = 1;
	if (format[*i] == 'l' && format[*i + 1] == 'l')
		mod->ll = 1;
	if (mod->h || mod->hh || mod->l || mod->ll || mod->j || mod->z)
		return (1);
	return (0);
}
