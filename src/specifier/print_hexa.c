/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapmarti <bapmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 14:59:12 by bapmarti          #+#    #+#             */
/*   Updated: 2021/02/27 14:17:31 by bapmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	convert_small_hexa(char *str)
{
	while (*str)
	{
		if (*str >= 'A' && *str <= 'E')
			*str += 32;
		str++;
	}
}

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

void	print_hexa(t_printf *f, unsigned int number, int small)
{
	// if small == 1 "abcdef"
	// if small == 0 "ABCDEF"
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
	str_number = ft_utoa_base(number, 16);
	if (small)
	{
		//printf("\n\n%s\n\n", str_number);
		convert_small_hexa(str_number);
	}
	print_number(str_number, saved_number, f);
	free(str_number);

}