/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae <jae@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 02:27:50 by jae               #+#    #+#             */
/*   Updated: 2020/07/24 02:27:51 by jae              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include <stdlib.h>
# include <stdbool.h>
# include <wchar.h>
# include "../libft/libft.h"

# define TRUE		1
# define FALSE		0
# define ERROR		-1
# define NONE		-2
# define DECI		"0123456789"
# define HEXA_S		"0123456789abcdef"
# define HEXA_B		"0123456789ABCDEF"

typedef struct		s_inf
{
	char			sign;
	bool			sharp;
	char			paste;
	int				width;
	int				preci;
	char			add;
	char			type;
	int				typenbr;
	int				signbyte;
	int				real;
	bool			is_plus;
}					t_inf;

typedef struct		s_tot
{
	va_list			ap;
	int				i;
	int				total;
	bool			error;
}					t_tot;

typedef struct		s_flo
{
	bool			is_minus;
	double			f;
	double			tmp;
	char			*str;
	int				len;
	int				cnt;
	bool			is_up;
	int				e;
	int				elen;
}					t_flo;

wint_t				get_c(t_inf *inf, t_tot *tot);
long long			get_n(t_inf *inf, t_tot *tot);
unsigned long long	get_u(t_inf *inf, t_tot *tot);
void				check(t_inf *inf);

void				put_c(t_inf *inf, t_tot *tot);
void				put_s(t_inf *inf, t_tot *tot);
void				put_p(t_inf *inf, t_tot *tot);
void				put_d(t_inf *inf, t_tot *tot);
void				put_u(t_inf *inf, t_tot *tot);
void				put_x(t_inf *inf, t_tot *tot);
void				put_pct(t_inf *inf, t_tot *tot);
void				put_n(t_inf *inf, t_tot *tot);
void				put_f(t_inf *inf, t_tot *tot);
void				put_g(t_inf *inf, t_tot *tot);
void				put_e(t_inf *inf, t_tot *tot);

void				make_f_len(t_flo *flo, t_inf *inf, t_tot *tot);
void				make_f_str(t_flo *flo, t_inf *inf);
void				make_f_rnd(t_flo *flo, t_tot *tot);
void				make_e_len(t_flo *flo, t_inf *inf, t_tot *tot);
void				make_e_str(t_flo *flo, t_inf *inf);
void				make_e_rnd(t_flo *flo);
void				put_e_e(t_tot *tot, int e);
void				get_g_e(t_flo *flo, t_inf *inf);

void				pf_putchar(t_tot *tot, char c);
void				pf_putstr(t_tot *tot, char *s, int len);
void				pf_putblank(t_tot *tot, char c, int times);
void				pf_putwchar(t_tot *tot, wint_t c);
int					pf_round_is_up(double f, int preci);

void				parse_flag(const char *fmt, t_inf *inf, t_tot *tot);
void				parse_width(const char *fmt, t_inf *inf, t_tot *tot);
void				parse_preci(const char *fmt, t_inf *inf, t_tot *tot);
void				parse_add(const char *fmt, t_inf *inf, t_tot *tot);
void				parse_type(const char *fmt, t_inf *inf, t_tot *tot);

void				parse_typenbr(t_inf *inf);
void				parse(const char *fmt, t_inf *inf, t_tot *tot);
void				put(t_inf *inf, t_tot *tot);
void				writeto(const char *fmt, t_tot *tot);
int					ft_printf(const char *fmt, ...);

#endif
