/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapmarti <bapmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 23:21:06 by bapmarti          #+#    #+#             */
/*   Updated: 2021/02/20 23:22:30 by bapmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_p(t_printf *f)
{
	print_space(f, f->w > 0 ? f->w - 1 : 0);
	write(1, "%", 1);
	f->len++;
	print_space(f, f->w < 0 ? -f->w - 1 : 0);
}

void	print_percent(t_printf *f)
{
	print_p(f);
}