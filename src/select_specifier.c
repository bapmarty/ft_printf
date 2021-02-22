/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_specifier.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapmarti <bapmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 13:49:36 by bapmarti          #+#    #+#             */
/*   Updated: 2021/02/22 18:00:45 by bapmarti         ###   ########.fr       */
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
}
