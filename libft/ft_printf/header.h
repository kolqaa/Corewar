/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimonov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 11:34:07 by nsimonov          #+#    #+#             */
/*   Updated: 2017/02/23 17:05:34 by nsimonov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# define MAX(a, b) ((a) > (b) ? (a) : (b))
# define IS_SIGN (mod->plu || mod->space || nb < 0 ? 1 : 0)

typedef	struct	s_mod
{
	int min;
	int plu;
	int space;
	int okto;
	int zero;
	int width;
	int precision;
	int precnum;
	int wildcart;
	int flag;
	int hh;
	int h;
	int l;
	int ll;
	int j;
	int z;
}				t_mod;

int				g_value;
void			printd(long long nbr);
void			for_nonvalid(char format, t_mod *mod);
void			helpd(long long nb, t_mod *mod);
t_mod			*mallc_and_fill_struct(t_mod *mod);
void			with_mod_help(const char *fo, int *i, va_list arg, t_mod *mod);
int				ft_printf(const char *format, ...);
void			form_without_mod(char format, va_list arg);
int				form_with_mod(char format, va_list arg, t_mod *mod);
int				fill_struct(const char *format, t_mod *mod, va_list arg);
int				ft_flag(const char *format, int *i, t_mod *mod, va_list arg);
int				ft_width(const char *format, int *i, t_mod *mod);
int				ft_precision(const char *format, int *i, t_mod *mod);
int				ft_lentgh(const char *format, int *i, t_mod *mod);
t_mod			*my_bzero(t_mod *mod);
int				is_modif(char format);
int				is_flag(char format);
void			my_putchar(char c);
void			my_putstr(char *str);
void			my_signednbr(long long nbr);
int				lennum(long long nbr);
void			my_formin(long long nbr);
void			for_d(char format, va_list arg, t_mod *mod);
void			for_u(char format, va_list arg, t_mod *mod);
void			for_o(char format, va_list arg, t_mod *mod);
void			my_itoa_base(long long value, int base, char format);
int				lennum8(long long nbr);
int				lennum16(long long nbr);
int				ft_isdigit(int c);
int				ft_atoi(const char *str);
void			my_putnbr(int n);
void			for_x(char format, va_list arg, t_mod *mod);
void			for_p(char format, va_list arg, t_mod *mod);
void			for_s(va_list arg, t_mod *mod);
int				my_strlen(char *str);
void			for_c(va_list arg, t_mod *mod);
void			for_prec(t_mod *mod);
void			my_forun(long long nbr);

#endif
