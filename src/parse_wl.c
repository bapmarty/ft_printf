/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_wl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapmarti <bapmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 20:32:33 by bapmarti          #+#    #+#             */
/*   Updated: 2021/02/28 20:36:59 by bapmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	parse_wl(t_printf *f, int i)
{
	int	wl;
	int	wl_minus;

	wl = 0;
	wl_minus = 0;
	while (f->fmt[i] >= '0' && f->fmt[i] <= '9')
	{
		wl = wl * 10 + f->fmt[i] - '0';
		i++;
	}
	if (wl_minus)
		wl = -wl;
	if (f->p == 1)
		f->l = wl;
	else
		f->w = wl;
	return (i);
}
