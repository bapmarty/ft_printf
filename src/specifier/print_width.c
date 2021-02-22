/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapmarti <bapmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 17:50:34 by bapmarti          #+#    #+#             */
/*   Updated: 2021/02/22 17:50:37 by bapmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_width(int width, int arg, int zero)
{
	char	printed_char;
	int		count;

	printed_char = zero ? '0' : ' ';
	count = 0;
	
	while (width - arg > count)
	{
		ft_putchar(printed_char);
		count++;
	}
	return (count);
}
