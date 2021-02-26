/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapmarti <bapmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 20:39:48 by bapmarti          #+#    #+#             */
/*   Updated: 2021/02/26 14:55:19 by bapmarti         ###   ########.fr       */
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

void				init_flags(t_printf *f);
void				select_specifier(t_printf *f);
void				print_unsigned_integer(t_printf *f, unsigned int number);
void				print_char(t_printf *f, unsigned char c);
void				print_integer(t_printf *f, int number);
void				print_string(t_printf *f, char *str);

#endif