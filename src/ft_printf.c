/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapmarti <bapmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 20:33:19 by bapmarti          #+#    #+#             */
/*   Updated: 2021/02/21 02:56:09 by bapmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	parse_width_length(t_printf *f, int i)
{
	int	wl;

	wl = 0;
	while (f->fmt[i] >= '0' && f->fmt[i] <= '9')
	{
		wl = wl * 10 + f->fmt[i] - '0';
		i++;
	}
	if (f->p == 1)
		f->l = wl;
	else
		f->w = wl;
	return (i);
}

static int	parse_wildcard(t_printf *f, int i)
{
	if (f->p == 1)
		f->l = va_arg(f->ap, int);
	else
		f->w = va_arg(f->ap, int);
	i++;
	return (i);
}

static int	parse_parameters(t_printf *f, int i)
{
	if (f->fmt[i] == '-')
	{
		f->m = 1;
		i++;
	}
	if (f->fmt[i] >= '0' && f->fmt[i] <= '9')
		i = parse_width_length(f, i);
	else if (f->fmt[i] == '*')
		i = parse_wildcard(f, i);
	if (f->fmt[i] == '.')
	{
		f->p = 1;
		i++;
		if (f->fmt[i] >= '0' && f->fmt[i] <= '9')
			i = parse_width_length(f, i);
		else if (f->fmt[i] == '*')
			i = parse_wildcard(f, i);
	}
	f->s = f->fmt[i];
	return (i);
}


static void	parse(t_printf *f)
{
	int	i;

	f->len = 0;
	i = 0;
	while (f->fmt[i])
	{
		init_params(f);
		if (f->fmt[i] == '%')
		{
			i = parse_parameters(f, i + 1);
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

	f.fmt = (char *)fmt;
	va_start(f.ap, fmt);
	va_copy(f.copy, f.ap);
	parse(&f);
	va_end(f.ap);
	return (f.len);
}
