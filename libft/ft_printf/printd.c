/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimonov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 18:47:35 by nsimonov          #+#    #+#             */
/*   Updated: 2017/02/23 18:27:19 by nsimonov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	printd(long long nbr)
{
	unsigned long long nbrr;

	if (nbr < 0)
	{
		my_putchar('-');
		nbrr = -nbr;
	}
	else
		nbrr = nbr;
	if (nbrr / 10)
		printd(nbrr / 10);
	my_putchar(nbrr % 10 + '0');
}
