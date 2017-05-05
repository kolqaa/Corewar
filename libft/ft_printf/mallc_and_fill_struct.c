/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mallc_and_fill_struct.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimonov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 18:12:32 by nsimonov          #+#    #+#             */
/*   Updated: 2017/02/23 18:12:47 by nsimonov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_mod	*mallc_and_fill_struct(t_mod *mod)
{
	mod = (t_mod*)malloc(sizeof(*mod));
	mod = my_bzero(mod);
	return (mod);
}
