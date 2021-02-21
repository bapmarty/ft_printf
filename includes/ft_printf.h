/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapmarti <bapmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 20:39:48 by bapmarti          #+#    #+#             */
/*   Updated: 2021/02/20 23:24:47 by bapmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>

typedef struct		s_printf {
	char		*fmt;
	va_list		ap;
	va_list		copy;
	int			len;
	int			m;
	int			w;
	int			p;
	int			l;
	char		s;
}					t_printf;

int					ft_printf(const char *fmt, ...);


#endif