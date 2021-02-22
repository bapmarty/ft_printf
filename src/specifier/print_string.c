/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapmarti <bapmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 13:45:14 by bapmarti          #+#    #+#             */
/*   Updated: 2021/02/22 18:06:24 by bapmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_str(char *str, t_printf *f)
{
	int	len;

	len = f->l;
	if (f->l >= 0)
	{
		while (*str && len-- > 0)
		{
			ft_putchar(*str);
			str++;
			f->len++;
		}
	}
	else
	{
		while (*str)
		{
			ft_putchar(*str);
			str++;
			f->len++;
		}
	}
}

void	print_string(t_printf *f, char *str)
{
	int		len_s;

	if (!str)
		str = "(null)";
	len_s = ft_strlen(str);
	if ((f->l >= 0 && f->l > len_s))
		f->l = len_s;
	if (f->m == 1)
		print_str(str, f);
	if (f->l >= 0)
		f->len += print_width(f->w, f->l, 0);
	else
		f->len += print_width(f->w, len_s, 0);
	if (f->m == 0)
		print_str(str, f);
}
