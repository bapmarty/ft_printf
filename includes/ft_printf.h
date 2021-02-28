/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapmarti <bapmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 20:39:48 by bapmarti          #+#    #+#             */
/*   Updated: 2021/02/28 20:35:02 by bapmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <stdio.h>

typedef struct s_printf {
	char		*fmt;
	va_list		ap;
	va_list		copy;
	int			zero;
	int			len;
	int			m;
	int			w;
	int			p;
	int			l;
	char		s;
}	t_printf;

int					ft_printf(const char *fmt, ...);
int					print_width(int width, int arg, int zero);
int					parse_zero(t_printf *f, int i);
int					parse_wl(t_printf *f, int i);

void				init_flags(t_printf *f);
void				select_specifier(t_printf *f);
void				print_pointer(t_printf *f, unsigned long long pointer);
void				print_hexa(t_printf *f, unsigned int integer);
void				print_uint(t_printf *f, unsigned int uint);
void				print_char(t_printf *f, unsigned char c);
void				print_int(t_printf *f, int integer);
void				print_string(t_printf *f, char *str);

#endif