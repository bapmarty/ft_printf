/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapmarti <bapmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 13:44:08 by bapmarti          #+#    #+#             */
/*   Updated: 2021/02/22 18:04:32 by bapmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_char(t_printf *f, unsigned char c)
{
	if ((f->l >= 0 && f->l > 1))
		f->l = 1;
	if (f->m == 1)
		ft_putchar(c);
	if (f->l >= 0)
		f->len += print_width(f->w, 1, f->zero);
	else
		f->len += print_width(f->w, 1, f->zero);
	if (f->m == 0)
		ft_putchar(c);
	f->len++;
}
