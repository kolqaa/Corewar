/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_signednbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimonov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 16:21:24 by nsimonov          #+#    #+#             */
/*   Updated: 2017/02/23 18:22:42 by nsimonov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	my_signednbr(long long nbr)
{
	if (nbr < 0)
	{
		my_putchar('-');
		nbr = -nbr;
	}
	if (nbr / 10)
		my_signednbr(nbr / 10);
	my_putchar(nbr % 10 + '0');
}
