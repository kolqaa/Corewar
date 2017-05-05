/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_without_mod.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimonov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 16:02:17 by nsimonov          #+#    #+#             */
/*   Updated: 2017/02/23 17:57:27 by nsimonov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	countin_check(char format, va_list arg)
{
	if (format == 'p')
	{
		my_putstr("0x");
		my_itoa_base((va_arg(arg, unsigned long int)), 16, format);
	}
	else if (format == 'c' || format == 'C')
		my_putchar((char)va_arg(arg, int));
	else if (format == 'n')
		*(va_arg(arg, unsigned int*)) = g_value;
	else if (format == '%')
		my_putchar(format);
	else if (format == 'u')
		my_formin(va_arg(arg, unsigned int));
	else if (format == 'U')
		my_itoa_base((va_arg(arg, unsigned long)), 10, format);
	else if (format != '\0')
		my_putchar(format);
}

void	form_without_mod(char format, va_list arg)
{
	char	*check;

	if (format == 's' || format == 'S')
	{
		check = va_arg(arg, char*);
		if (check == NULL)
			my_putstr("(null)");
		else
			my_putstr(check);
	}
	else if (format == 'd' || format == 'i')
		my_signednbr(va_arg(arg, int));
	else if (format == 'D')
		printd(va_arg(arg, long long));
	else if (format == 'o')
		my_itoa_base((va_arg(arg, unsigned int)), 8, format);
	else if (format == 'O')
		my_itoa_base((va_arg(arg, long)), 8, format);
	else if (format == 'x')
		my_itoa_base((va_arg(arg, unsigned int)), 16, format);
	else if (format == 'X')
		my_itoa_base((va_arg(arg, unsigned int)), 16, format);
	else
		countin_check(format, arg);
}
