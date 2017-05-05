/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lennum.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimonov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 19:44:11 by nsimonov          #+#    #+#             */
/*   Updated: 2017/02/10 13:56:43 by nsimonov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		lennum(long long nbr)
{
	int count;

	count = 0;
	if (nbr == 0)
		return (1);
	while (nbr)
	{
		nbr = nbr / 10;
		count++;
	}
	return (count);
}
