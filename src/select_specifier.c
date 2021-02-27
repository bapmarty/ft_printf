/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_specifier.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapmarti <bapmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 13:49:36 by bapmarti          #+#    #+#             */
/*   Updated: 2021/02/27 15:44:16 by bapmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	select_specifier(t_printf *f)
{
	if (f->s == 'c')
		print_char(f, va_arg(f->ap, int));
	else if (f->s == 's')
		print_string(f, va_arg(f->ap, char *));
	else if (f->s == '%')
		print_char(f, '%');
	else if (f->s == 'i' || f->s == 'd')
		print_int(f, va_arg(f->ap, int));
	else if (f->s == 'u')
		print_uint(f, va_arg(f->ap, int));
	else if (f->s == 'x')
		print_hexa(f, (unsigned int)va_arg(f->ap, int));
	else if (f->s == 'X')
		print_hexa(f, (unsigned int)va_arg(f->ap, int));
	else if (f->s == 'p')
		print_pointer(f, va_arg(f->ap, unsigned long long));
}
