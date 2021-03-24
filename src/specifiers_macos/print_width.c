/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapmarti <bapmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 17:50:34 by bapmarti          #+#    #+#             */
/*   Updated: 2021/02/27 14:22:11 by bapmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_width(int width, int arg, int zero)
{
	char	printed_char;
	int		count;

	count = 0;
	if (zero == 1)
		printed_char = '0';
	else
		printed_char = ' ';
	while (width - arg > count)
	{
		ft_putchar(printed_char);
		count++;
	}
	return (count);
}
