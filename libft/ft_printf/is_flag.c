/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimonov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 12:33:49 by nsimonov          #+#    #+#             */
/*   Updated: 2017/02/23 18:44:25 by nsimonov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	is_flag(char format)
{
	if (format == '-')
		return (1);
	if (format == '+')
		return (1);
	if (format == '#')
		return (1);
	if (format == '0')
		return (1);
	if (format == ' ')
		return (1);
	return (0);
}
