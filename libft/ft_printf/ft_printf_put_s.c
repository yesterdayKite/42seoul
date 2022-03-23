/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_put_s.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae <jae@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 16:47:15 by jae               #+#    #+#             */
/*   Updated: 2021/02/01 16:47:16 by jae              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pf_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int		pf_putstr_prewid(char *s, struct s_flgs *flags)
{
	int		ssize;
	int		padsize;
	int		i;
	char	c;

	c = ' ';
	if (flags->zero == 1 && flags->minus == 0)
		c = '0';
	ssize = (pf_strlen(s) < flags->precision) ? pf_strlen(s) : flags->precision;
	padsize = (flags->width > ssize) ? flags->width - ssize : 0;
	i = 0;
	while (flags->minus == 1 && i < flags->precision && s[i] != '\0')
		buf_write(flags->buffer, s[i++], &flags->index);
	i = 0;
	while (i++ < padsize)
		buf_write(flags->buffer, c, &flags->index);
	i = 0;
	while (flags->minus == 0 && i < flags->precision && s[i] != '\0')
		buf_write(flags->buffer, s[i++], &flags->index);
	return (ssize > flags->width ? ssize : flags->width);
}

int		pf_putstr_wid(char *s, struct s_flgs *flags)
{
	int		padsize;
	int		i;
	char	c;

	c = ' ';
	if (flags->zero == 1 && flags->minus == 0)
		c = '0';
	padsize = (flags->width > pf_strlen(s)) ? flags->width - pf_strlen(s) : 0;
	i = 0;
	while (flags->minus == 1 && s[i] != '\0')
		buf_write(flags->buffer, s[i++], &flags->index);
	i = 0;
	while (i++ < padsize)
		buf_write(flags->buffer, c, &flags->index);
	i = 0;
	while (flags->minus == 0 && s[i] != '\0')
		buf_write(flags->buffer, s[i++], &flags->index);
	return (pf_strlen(s) > flags->width ? pf_strlen(s) : flags->width);
}

int		pf_putstr_pre(struct s_flgs *flags, char *s, int prec)
{
	int	ssize;
	int	i;

	ssize = (pf_strlen(s) < prec) ? pf_strlen(s) : prec;
	i = 0;
	while (i < ssize && s[i] != '\0')
		buf_write(flags->buffer, s[i++], &flags->index);
	return (ssize);
}

int		pf_putstr(struct s_flgs *flags, char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		buf_write(flags->buffer, s[i++], &flags->index);
	return (i);
}
