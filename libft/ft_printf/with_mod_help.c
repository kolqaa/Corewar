/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   with_mod_help.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimonov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 18:05:57 by nsimonov          #+#    #+#             */
/*   Updated: 2017/02/23 17:06:03 by nsimonov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	with_mod_help(const char *fo, int *i, va_list arg, t_mod *mod)
{
	while (ft_isdigit(fo[*i]) || is_modif(fo[*i]) || is_flag(fo[*i]))
		(*i)++;
	form_with_mod(fo[*i], arg, mod);
}
