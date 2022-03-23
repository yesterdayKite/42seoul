/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae <jae@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 02:08:00 by jae               #+#    #+#             */
/*   Updated: 2020/07/24 02:11:02 by jae              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <stdbool.h>
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

void				check(t_inf *inf);

void				put_c(t_inf *inf, t_tot *tot);
void				put_s(t_inf *inf, t_tot *tot);
void				put_p(t_inf *inf, t_tot *tot);
void				put_d(t_inf *inf, t_tot *tot);
void				put_u(t_inf *inf, t_tot *tot);
void				put_x(t_inf *inf, t_tot *tot);
void				put_pct(t_inf *inf, t_tot *tot);

void				pf_putchar(t_tot *tot, char c);
void				pf_putstr(t_tot *tot, char *s, int len);
void				pf_putblank(t_tot *tot, char c, int times);

void				parse_flag(const char *fmt, t_inf *inf, t_tot *tot);
void				parse_width(const char *fmt, t_inf *inf, t_tot *tot);
void				parse_preci(const char *fmt, t_inf *inf, t_tot *tot);
void				parse_type(const char *fmt, t_inf *inf, t_tot *tot);

void				parse_typenbr(t_inf *inf);
void				parse(const char *fmt, t_inf *inf, t_tot *tot);
void				put(t_inf *inf, t_tot *tot);
void				writeto(const char *fmt, t_tot *tot);
int					ft_printf(const char *fmt, ...);

#endif
