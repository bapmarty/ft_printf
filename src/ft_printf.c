/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapmarti <bapmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 20:33:19 by bapmarti          #+#    #+#             */
/*   Updated: 2021/02/27 18:51:57 by bapmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	parse_wl(t_printf *f, int i)
{
	int wl;
	int wl_minus;

	wl = 0;
	wl_minus = 0;
	i = parse_zero(f, i);
	if (f->fmt[i] == '-')
	{
		wl_minus = 1;
		i++;
	}
	while (f->fmt[i] >= '0' && f->fmt[i] <= '9')
	{
		wl = wl * 10 + f->fmt[i] - '0';
		i++;
	}
	if (wl_minus)
		wl = -wl;
	if (f->p == 1)
		f->l = wl;
	else
		f->w = wl;
	return (i);
}

static int	parse_wildcard(t_printf *f, int i)
{
	if (f->p == 1)
	{
		f->l = va_arg(f->ap, int);
		if (f->l < 0)
		{
			f->m = 1;
		}
	}
	else
	{
		f->w = va_arg(f->ap, int);
		if (f->w < 0)
		{
			f->m = 1;
		}
	}
	return (i + 1);
}

static int	parse_parameters(t_printf *f, int i)
{
	if (f->fmt[i] == '-')
	{
		f->m = 1;
		f->fmt++;
	}
	if ((f->fmt[i] >= '0'  && f->fmt[i] <= '9') || f->fmt[i] == '-')
	{
		i = parse_wl(f, i);
	}
	else if (f->fmt[i] == '*')
	{
		i = parse_wildcard(f, i);
	}
	if (f->fmt[i] == '.')
	{
		f->p = 1;
		i++;
		if ((f->fmt[i] >= '0'  && f->fmt[i] <= '9') || f->fmt[i] == '-')
		{
			i = parse_wl(f, i);
		}
		else if (f->fmt[i] == '*')
			i = parse_wildcard(f, i);
		else
			f->l = 0;
	}
	f->s = f->fmt[i];
	return (i);
}

static void	parse(t_printf *f, int i)
{
	f->len = 0;
	while (f->fmt[i])
	{
		init_flags(f);
		if (f->fmt[i] == '%')
		{
			i = parse_parameters(f, i + 1);
			select_specifier(f);
		}
		else
		{
			ft_putchar(f->fmt[i]);
			f->len++;
		}
		i++;
	}
}

int	ft_printf(const char *fmt, ...)
{
	t_printf	f;
	int			i;

	i = 0;
	f.fmt = (char *)fmt;
	va_start(f.ap, fmt);
	va_copy(f.copy, f.ap);
	parse(&f, i);
	va_end(f.ap);
	return (f.len);
}
