/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_with_mod.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimonov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 16:03:01 by nsimonov          #+#    #+#             */
/*   Updated: 2017/02/23 17:09:17 by nsimonov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	form_with_mod(char format, va_list arg, t_mod *mod)
{
	if (format == 'd' || format == 'i' || format == 'D')
		for_d(format, arg, mod);
	else if (format == 'u' || format == 'U')
		for_u(format, arg, mod);
	else if (format == 'o' || format == 'O')
		for_o(format, arg, mod);
	else if (format == 'x' || format == 'X')
		for_x(format, arg, mod);
	else if (format == 'p')
		for_p(format, arg, mod);
	else if (format == 's' || format == 'S')
		for_s(arg, mod);
	else if (format == 'c' || format == 'C')
		for_c(arg, mod);
	else if (format == 'n')
		*(va_arg(arg, unsigned int*)) = g_value;
	else if (format == '%')
		for_prec(mod);
	else
		for_nonvalid(format, mod);
	return (0);
}
