/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapmarti <bapmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 21:50:29 by bapmarti          #+#    #+#             */
/*   Updated: 2021/02/21 03:13:21 by bapmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_c(t_printf *f)
{
	unsigned char	c;

	c = (unsigned char)va_arg(f->ap, int);
	if (f->m == 0)
		print_space(f, f->w - 1);
	write(1, &c, 1);
	f->len++;
	if (f->m == 1)
		print_space(f, f->w - 1);
}

static void	print_s(t_printf *f)
{
	char	*s;
	int		len_s;
	int		len_l;

	s = va_arg(f->ap, char *);
	len_s = ft_strlen(s);
	if (f->m == 0)
		print_space(f, f->w - len_s);
	if (f->l >= 0 || f->l >= len_s)
	{
		if (f->l > len_s)
		{
			ft_putstr(s);
			f->len+=len_s;
		}
		else
		{
			len_l = 0;
			while (f->l > len_l)
				ft_putchar(s[len_l++]);
			f->len+=f->l;
		}
	}
	else if ((f->p && f->l > 0)) {
		ft_putstr(s);
		f->len+=len_s;
	}
	else {
		ft_putstr(s);
		f->len+=len_s;
	}
	if (f->m == 1)
		print_space(f, f->w - len_s);
}

void	print_cs(t_printf *f)
{
	if (f->s == 'c')
		print_c(f);
	else
		print_s(f);
}