/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoh <seunghoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 14:10:29 by seunghoh          #+#    #+#             */
/*   Updated: 2021/01/15 05:46:52 by seunghoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H
# include <stdarg.h>
# include <stddef.h>

typedef	struct		s_conversion{
	char			type;
	char			align;
	char			fill_zero;
	int				indent;
	int				width;
	size_t			u_width;
	int				precision;
}					t_conversion;

int					parse(const char *format, va_list ap);
int					find_conversion(t_conversion *info, va_list ap,
									const char *format);
int					parse_conversion(t_conversion *info, va_list ap);
void				init_conversion(t_conversion *info);
int					validate_conversion(t_conversion *info);
int					check_align_zero(t_conversion *info, char ch);
int					check_width(t_conversion *info, va_list ap, char ch,
								int flag);
int					check_precision(t_conversion *info, va_list ap, char ch,
									int flag);
int					check_type(t_conversion *info, char ch);
int					parse_int(t_conversion *info, va_list ap);
int					parse_uint(t_conversion *info, va_list ap);
int					parse_char(t_conversion *info, va_list ap);
int					parse_string(t_conversion *info, va_list ap);
int					parse_hex(t_conversion *info, va_list ap, int flag);
int					parse_ptr(t_conversion *info, va_list ap);
int					parse_percent(t_conversion *info);
#endif
