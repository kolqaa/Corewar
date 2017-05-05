/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_modif.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimonov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 12:29:39 by nsimonov          #+#    #+#             */
/*   Updated: 2017/02/23 18:26:18 by nsimonov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	is_modif(char format)
{
	if (format == '*')
		return (1);
	if (format == '.')
		return (1);
	if (format == 'h')
		return (1);
	if (format == 'l')
		return (1);
	if (format == 'j')
		return (1);
	if (format == 'z')
		return (1);
	return (0);
}
