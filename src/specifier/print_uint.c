/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapmarti <bapmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 14:54:16 by bapmarti          #+#    #+#             */
/*   Updated: 2021/02/28 17:54:55 by bapmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_part_uint_string(char *s_uint, unsigned int uint, t_printf *f)
{
	if (uint < 0 && f->l >= 0)
	{
		ft_putchar('-');
	}
	if (f->l >= 0)
	{
		f->len += print_width(f->l - 1, ft_strlen(s_uint) - 1, 1);
	}
	ft_putstr(s_uint);
	f->len += ft_strlen(s_uint);
}

static void	print_uint_string(char *s_uint, unsigned int uint, t_printf *f)
{
	if (f->m == 1)
	{
		print_part_uint_string(s_uint, uint, f);
	}
	if (f->l >= 0 && (size_t)f->l < ft_strlen(s_uint))
	{
		f->l = ft_strlen(s_uint);
	}
	if (f->l >= 0)
	{
		if (f->w < 0)
			f->w = -f->w;
		f->w -= f->l;
		f->len += print_width(f->w, 0, 0);
	}
	else
	{
		if (f->w < 0)
			f->w = -f->w;
		f->len += print_width(f->w, ft_strlen(s_uint), f->zero);
	}
	if (f->m == 0)
	{
		print_part_uint_string(s_uint, uint, f);
	}
}

void	print_uint(t_printf *f, unsigned int uint)
{
	char	*str_uint;

	if (f->l == 0 && uint == 0)
	{
		f->len += print_width(f->w, 0, f->zero);
		return ;
	}
	if (uint != 0)
		str_uint = ft_utoa(uint);
	else
		str_uint = ft_itoa(uint);
	print_uint_string(str_uint, uint, f);
	free(str_uint);
}