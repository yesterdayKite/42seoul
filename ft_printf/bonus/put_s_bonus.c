/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_s_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae <jae@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 02:27:11 by jae               #+#    #+#             */
/*   Updated: 2020/07/24 02:27:12 by jae              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int		pf_wstrlen(wchar_t *s)
{
	int			i;
	int			byte;

	i = 0;
	byte = 0;
	while (s[i] != '\0')
	{
		if (s[i] < 0x007F)
			byte += 1;
		else if (s[i] < 0x07FF)
			byte += 2;
		else if (s[i] < 0xFFFF)
			byte += 3;
		else if (s[i] < 0x10FFFF)
			byte += 4;
		i++;
	}
	return (byte);
}

static void		real_ws(t_inf *inf, wchar_t **ps)
{
	int			len;

	if (!*ps)
		*ps = L"(null)";
	len = pf_wstrlen(*ps);
	if (inf->preci == NONE)
		inf->real = len;
	else
		inf->real = ft_min(inf->preci, len);
}

void			put_ws(t_inf *inf, t_tot *tot)
{
	wchar_t		*s;
	int			i;

	s = va_arg(tot->ap, wchar_t *);
	real_ws(inf, &s);
	if (!inf->paste)
		pf_putblank(tot, ' ', inf->width - inf->real);
	else if (inf->paste == '0')
		pf_putblank(tot, '0', inf->width - inf->real);
	i = 0;
	while (s[i] != '\0')
	{
		pf_putwchar(tot, (wint_t)s[i]);
		i++;
	}
	if (inf->paste == '-')
		pf_putblank(tot, ' ', inf->width - inf->real);
}

static void		real_s(t_inf *inf, char **ps)
{
	int			len;

	if (!*ps)
		*ps = "(null)";
	len = (int)ft_strlen(*ps);
	if (inf->preci == NONE)
		inf->real = len;
	else
		inf->real = ft_min(inf->preci, len);
}

void			put_s(t_inf *inf, t_tot *tot)
{
	char		*s;

	if (inf->add == 'l')
	{
		put_ws(inf, tot);
		return ;
	}
	s = va_arg(tot->ap, char *);
	real_s(inf, &s);
	if (!inf->paste)
		pf_putblank(tot, ' ', inf->width - inf->real);
	else if (inf->paste == '0')
		pf_putblank(tot, '0', inf->width - inf->real);
	pf_putstr(tot, s, inf->real);
	if (inf->paste == '-')
		pf_putblank(tot, ' ', inf->width - inf->real);
}
