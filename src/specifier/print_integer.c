/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_integer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapmarti <bapmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 18:12:38 by bapmarti          #+#    #+#             */
/*   Updated: 2021/02/22 20:46:18 by bapmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_minus(char *number)
{
	if (*number == '-')
		return (1);
	return (0);
}

static void	print_number(char *number, t_printf *f, int len_number, int minus)
{
	int len_copy;
	(void)minus;
	// START DEBUG
	//printf("\n\n\n[DEBUG]\n");
	//printf("[number] [%s]\n", number);
	//printf("[len] %i\n", len);
	//printf("[f->m] %d\n", f->m);
	//printf("[f->w] %d\n", f->w);
	//printf("[f->p] %d\n", f->p);
	//printf("[f->l] %d\n", f->l);
	//printf("[f->s] %c\n\n\n", f->s);
	// END DEBUG
	if (f->l >= 0)
	{
		len_copy = f->l;
		f->len += print_width(f->l, len_number, 1);
		while (*number)
		{
			ft_putchar(*number);
			number++;
			f->len++;
		}
	}
	else
	{
		while (*number)
		{
			ft_putchar(*number);
			number++;
			f->len++;
		}
	}
}

void	print_integer(t_printf *f, char *number)
{
	int	len;
	int	minus;

	minus = check_minus(number);
	len = ft_strlen(number);
	if (f->w == 0 && (minus && f->l >= 0))
	{
		ft_putchar('-');
		len--;
		number++;
		minus = 0;
	}
	//if (f->l >= 0 && f->l > len)
	//{
	//	f->l = len;
	//}
	if (f->m == 1)
	{
		print_number(number, f, len, minus);
	}
	if ((f->l >= 0 && f->zero == 1) )
	{
		f->len += print_width(f->w, len, 1);
	}
	else if (f->l >= 0)
		f->len += print_width(f->w, -(f->l - len), 0);
	else
		f->len += print_width(f->w, len, 0);
	if (minus && f->l >= 0)
	{
		ft_putchar('-');
		len--;
		number++;
	}
	if (f->m == 0)
	{
		if (minus && f->m == 1)
		{
			ft_putchar('-');
			number++;
		}
		print_number(number, f, len, minus);
	}
}