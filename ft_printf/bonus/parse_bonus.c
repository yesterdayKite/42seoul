/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae <jae@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 02:26:02 by jae               #+#    #+#             */
/*   Updated: 2020/07/24 02:26:03 by jae              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

void				parse_flag(const char *fmt, t_inf *inf, t_tot *tot)
{
	char			c;

	while (fmt[tot->i] != '\0')
	{
		c = (char)fmt[tot->i];
		if (c == '+' || c == ' ')
		{
			if (!inf->sign)
				inf->sign = c;
			else if (inf->sign == ' ' && c == '+')
				inf->sign = c;
		}
		else if (c == '#')
			inf->sharp = TRUE;
		else if (c == '-' || c == '0')
		{
			if (!inf->paste)
				inf->paste = c;
			else if (inf->paste == '0' && c == '-')
				inf->paste = c;
		}
		else
			return ;
		tot->i++;
	}
}

void				parse_width(const char *fmt, t_inf *inf, t_tot *tot)
{
	char			c;

	while (fmt[tot->i] != '\0')
	{
		c = (char)fmt[tot->i];
		if (c == '*')
		{
			inf->width = va_arg(tot->ap, int);
			if (inf->width < 0)
			{
				inf->paste = '-';
				inf->width *= -1;
			}
		}
		else if (ft_isdigit(c))
		{
			inf->width *= 10;
			inf->width += c - '0';
		}
		else
			return ;
		tot->i++;
	}
}

void				parse_preci(const char *fmt, t_inf *inf, t_tot *tot)
{
	char			c;

	if (fmt[tot->i] != '.')
	{
		inf->preci = NONE;
		return ;
	}
	tot->i++;
	while (fmt[tot->i] != '\0')
	{
		c = (char)fmt[tot->i];
		if (c == '*')
		{
			inf->preci = va_arg(tot->ap, int);
			if (inf->preci < 0)
				inf->preci = NONE;
		}
		else if (ft_isdigit(c))
			inf->preci = (inf->preci * 10) + c - '0';
		else
			return ;
		tot->i++;
	}
}

void				parse_add(const char *fmt, t_inf *inf, t_tot *tot)
{
	if (fmt[tot->i] == 'h')
	{
		inf->add = 'h';
		tot->i++;
		if (fmt[tot->i] == 'h')
		{
			inf->add = 'H';
			tot->i++;
		}
	}
	else if (fmt[tot->i] == 'l')
	{
		inf->add = 'l';
		tot->i++;
		if (fmt[tot->i] == 'l')
		{
			inf->add = 'L';
			tot->i++;
		}
	}
}

void				parse_type(const char *fmt, t_inf *inf, t_tot *tot)
{
	if (ft_strchr("cspdiuxX%nfge", fmt[tot->i]))
	{
		inf->type = fmt[tot->i];
		tot->i++;
	}
}
