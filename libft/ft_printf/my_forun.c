/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_forun.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimonov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 16:19:52 by nsimonov          #+#    #+#             */
/*   Updated: 2017/02/23 18:01:18 by nsimonov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	my_forun(long long nbr)
{
	unsigned long long newnbr;

	if (nbr < 0)
	{
		newnbr = nbr;
		if (newnbr / 10)
			my_formin(newnbr / 10);
		my_putchar(newnbr % 10 + '0');
	}
	else
	{
		if (nbr / 10)
			my_formin(nbr / 10);
		my_putchar(nbr % 10 + '0');
	}
}
