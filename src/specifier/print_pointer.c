/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapmarti <bapmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 15:27:43 by bapmarti          #+#    #+#             */
/*   Updated: 2021/02/28 19:53:54 by bapmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_part_pointer_string(char *s_pointer, t_printf *f)
{
	int	i;

	ft_putstr("0x");
	f->len += 2;
	if (f->l >= 0)
	{
		f->len += print_width(f->l, ft_strlen(s_pointer), 1);
		i = 0;
		while (s_pointer[i] && i < f->l)
		{
			ft_putchar(s_pointer[i]);
			f->len++;
			i++;
		}
	}
	else
	{
		ft_putstr(s_pointer);
		f->len += ft_strlen(s_pointer);
	}
}

void	print_pointer(t_printf *f, unsigned long long pointer)
{
	char	*s_pointer;
	int		i;
	
	if (f->l == 0 && pointer == 0)
	{
		if (f->m == 1)
			ft_putstr("0x");
		f->len += print_width(f->w, 2, f->zero) + 2;
		if (f->m == 0)
			ft_putstr("0x");
		return ;
	}
	s_pointer = ft_ulltoa_base(pointer, 16);
	i = 0;
	while (s_pointer[i])
	{
		s_pointer[i] = ft_tolower(s_pointer[i]);
		i++;
	}
	if ((size_t)f->l < ft_strlen(s_pointer))
		f->l = ft_strlen(s_pointer);
	if (f->m == 1)
		print_part_pointer_string(s_pointer, f);
	if (f->w < 0)
		f->w = -f->w;
	f->len += print_width(f->w, ft_strlen(s_pointer) + 2, 0);
	if (f->m == 0)
		print_part_pointer_string(s_pointer, f);
	free(s_pointer);
}