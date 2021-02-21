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
static void	parse(t_printf *f)
{
	int	i;

	f->len = 0;
	i = 0;
	while (f->fmt[i])
	{
		init_params(f);
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
