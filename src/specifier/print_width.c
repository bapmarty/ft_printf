/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapmarti <bapmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 21:52:36 by bapmarti          #+#    #+#             */
/*   Updated: 2021/02/22 15:04:23 by bapmarti         ###   ########.fr       */
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
