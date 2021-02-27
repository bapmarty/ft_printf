/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapmarti <bapmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 14:59:12 by bapmarti          #+#    #+#             */
/*   Updated: 2021/02/27 20:00:58 by bapmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_part_hexa_string(char *s_hexa, unsigned int hexa, t_printf *f)
{
	if (hexa < 0 && f->l >= 0)
	{
		ft_putchar('-');
	}
	if (f->l >= 0)
	{
		f->len += print_width(f->l - 1, ft_strlen(s_hexa) - 1, 1);
	}
	while (*s_hexa)
	{
		if (f->s == 'x' && (*s_hexa >= 'A' && *s_hexa <= 'F'))
			ft_putchar(*s_hexa + 32);
		else
			ft_putchar(*s_hexa);
		s_hexa++;
		f->len++;
	}
}

static void	print_hexa_string(char *s_hexa, unsigned int hexa, t_printf *f)
{
	if (f->m == 1)
	{
		print_part_hexa_string(s_hexa, hexa, f);
	}
	if (f->l >= 0 && (size_t)f->l < ft_strlen(s_hexa))
	{
		f->l = ft_strlen(s_hexa);
	}
	if (f->l >= 0)
	{
		f->w -= f->l;
		f->len += print_width(f->w, 0, 0);
	}
	else
	{
		f->len += print_width(f->w, ft_strlen(s_hexa), f->zero);
	}
	if (f->m == 0)
	{
		print_part_hexa_string(s_hexa, hexa, f);
	}
}

void	print_hexa(t_printf *f, unsigned int hexa)
{
	char	*str_hexa;
	
	if (f->l == 0 && hexa == 0)
	{
		f->len += print_width(f->w, 0, 0);
		return ;
	}
	if (hexa < 0 && (f->l >=0 || f->zero == 1))
	{
		if (f->zero && f->l == -1)
		{
			ft_putchar('-');
		}
		hexa *= -1;
		f->w--;
		f->len++;
	}
	str_hexa = ft_utoa_base(hexa, 16);
	print_hexa_string(str_hexa, hexa, f);
	free(str_hexa);
}