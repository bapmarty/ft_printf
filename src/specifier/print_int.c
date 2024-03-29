/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapmarti <bapmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 18:12:38 by bapmarti          #+#    #+#             */
/*   Updated: 2021/03/24 16:48:48 by baptistem        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_part_int_string(char *s_number, int number, t_printf *f)
{
	if (number < 0 && f->l >= 0)
		ft_putchar('-');
	if (f->l >= 0)
		f->len += print_width(f->l - 1, ft_strlen(s_number) - 1, 1);
	ft_putstr(s_number);
	f->len += ft_strlen(s_number);
}

static void	print_int_string(char *s_number, int number, t_printf *f)
{
	if (f->m == 1)
		print_part_int_string(s_number, number, f);
	if (f->l >= 0 && (size_t)f->l < ft_strlen(s_number))
		f->l = ft_strlen(s_number);
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
		f->len += print_width(f->w, ft_strlen(s_number), f->zero);
	}
	if (f->m == 0)
		print_part_int_string(s_number, number, f);
}

void		print_int(t_printf *f, int number)
{
	char	*str_number;
	int		saved_number;

	saved_number = number;
	if ((f->l == 0 && number == 0))
	{
		f->len += print_width(f->w, 0, 0);
		return ;
	}
	if (number < 0 && (f->l >= 0 || f->zero == 1))
	{
		if (f->zero && f->l == -1)
			ft_putchar('-');
		if (f->w < 0)
			f->w++;
		else
			f->w--;
		number *= -1;
		f->len++;
	}
	str_number = ft_itoa(number);
	print_int_string(str_number, saved_number, f);
	free(str_number);
}
