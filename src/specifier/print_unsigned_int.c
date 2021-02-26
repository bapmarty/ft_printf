/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsinged_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapmarti <bapmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 14:54:16 by bapmarti          #+#    #+#             */
/*   Updated: 2021/02/26 14:57:00 by bapmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_part_number(char *s_number, unsigned int number, t_printf *f)
{
	if (number < 0 && f->l >= 0)
	{
		ft_putchar('-');
	}
	if (f->l >= 0)
	{
		f->len += print_width(f->l - 1, ft_strlen(s_number) - 1, 1);
	}
	ft_putstr(s_number);
	f->len += ft_strlen(s_number);
}

static void	print_number(char *s_number, unsigned int number, t_printf *f)
{
	if (f->m == 1)
	{
		print_part_number(s_number, number, f);
	}
	if (f->l >= 0 && (size_t)f->l < ft_strlen(s_number))
	{
		f->l = ft_strlen(s_number);
	}
	if (f->l >= 0)
	{
		f->w -= f->l;
		f->len += print_width(f->w, 0, 0);
	}
	else
	{
		f->len += print_width(f->w, ft_strlen(s_number), f->zero);
	}
	if (f->m == 0)
	{
		print_part_number(s_number, number, f);
	}
}

void	print_unsigned_integer(t_printf *f, unsigned int number)
{
	char			*str_number;
	unsigned int	saved_number;
	
	saved_number = number;
	if (f->l == 0 && number == 0)
	{
		f->len += print_width(f->w, 0, 0);
		return ;
	}
	if (number < 0 && (f->l >=0 || f->zero == 1))
	{
		if (f->zero && f->l == -1)
		{
			ft_putchar('-');
		}
		number *= -1;
		f->w--;
		f->len++;
	}
	str_number = ft_utoa(number);
	print_number(str_number, saved_number, f);
	free(str_number);
}