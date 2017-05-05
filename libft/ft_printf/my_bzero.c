/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimonov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 11:53:35 by nsimonov          #+#    #+#             */
/*   Updated: 2017/02/23 18:15:49 by nsimonov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_mod	*my_bzero(t_mod *mod)
{
	mod->min = 0;
	mod->plu = 0;
	mod->space = 0;
	mod->okto = 0;
	mod->zero = 0;
	mod->width = 0;
	mod->precision = 0;
	mod->precnum = 0;
	mod->wildcart = 0;
	mod->flag = 0;
	mod->hh = 0;
	mod->h = 0;
	mod->l = 0;
	mod->ll = 0;
	mod->j = 0;
	mod->z = 0;
	return (mod);
}
