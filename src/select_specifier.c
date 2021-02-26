/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_specifier.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapmarti <bapmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 13:49:36 by bapmarti          #+#    #+#             */
/*   Updated: 2021/02/26 14:55:10 by bapmarti         ###   ########.fr       */
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
		print_integer(f, va_arg(f->ap, int));
	else if (f->s == 'u')
		print_unsigned_integer(f, va_arg(f->ap, int));
}
