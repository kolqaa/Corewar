/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimonov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 10:56:25 by nsimonov          #+#    #+#             */
/*   Updated: 2017/02/24 12:54:42 by nsimonov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_printf(const char *format, ...)
{
	va_list		arg;
	int			i;
	t_mod		*mod;

	va_start(arg, format);
	i = 0;
	g_value = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			mod = mallc_and_fill_struct(mod);
			fill_struct(&format[i], mod, arg) == 1 ?
			(with_mod_help(format, &i, arg, mod)) :
			(form_without_mod(format[i], arg));
			free(mod);
		}
		else
			my_putchar(format[i]);
		if (format[i] != '\0')
			i++;
	}
	va_end(arg);
	return (g_value);
}
