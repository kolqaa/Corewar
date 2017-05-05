/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lennum8.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimonov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 17:38:52 by nsimonov          #+#    #+#             */
/*   Updated: 2017/02/23 18:24:19 by nsimonov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	lennum8(long long nbr)
{
	int count;

	count = 0;
	if (nbr == 0)
		return (1);
	while (nbr)
	{
		nbr = nbr / 8;
		count++;
	}
	return (count);
}
