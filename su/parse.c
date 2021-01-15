/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoh <seunghoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 13:53:37 by seunghoh          #+#    #+#             */
/*   Updated: 2021/01/15 17:35:21 by seunghoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parse.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int			parse(const char *format, va_list ap)
{
	int				base_idx;
	int				parsed_idx;
	int				count;
	t_conversion	info;

	count = 0;
	base_idx = 0;
	while (format[base_idx])
		if ((parsed_idx = find_conversion(&info, ap, format + base_idx)) != -1)
		{
			validate_conversion(&info);
			count += parse_conversion(&info, ap);
			base_idx += parsed_idx;
		}
		else
		{
			write(1, format + base_idx, 1);
			count++;
			base_idx++;
		}
	return (count);
}

int			parse_conversion(t_conversion *info, va_list ap)
{
	int		res;

	res = 0;
	if (info->type == 'c')
		res = parse_char(info, ap);
	else if (info->type == 's')
		res = parse_string(info, ap);
	else if (info->type == 'p')
		res = parse_ptr(info, ap);
	else if (info->type == 'd')
		res = parse_int(info, ap);
	else if (info->type == 'i')
		res = parse_int(info, ap);
	else if (info->type == 'u')
		res = parse_uint(info, ap);
	else if (info->type == 'x')
		res = parse_hex(info, ap, 0);
	else if (info->type == 'X')
		res = parse_hex(info, ap, 1);
	else if (info->type == '%')
		res = parse_percent(info);
	return (res);
}

int			find_conversion(t_conversion *info, va_list ap, const char *format)
{
	int	idx;

	idx = 0;
	init_conversion(info);
	if (format[idx++] != '%')
		return (-1);
	while (check_align_zero(info, format[idx]))
		idx++;
	if (format[idx] != '0' && ft_isdigit(format[idx]))
		while (check_width(info, ap, format[idx], 0))
			idx++;
	else if (format[idx] == '*')
		idx += check_width(info, ap, 0, 1);
	if (format[idx] == '.' && format[idx + 1] == '*')
		idx += check_precision(info, ap, 0, 1);
	else if (format[idx] == '.')
		while (check_precision(info, ap, format[idx], 0))
			idx++;
	if (check_type(info, format[idx]) == 0)
		return (idx);
	if (format[idx] != '\0')
		return (idx + 1);
	return (idx);
}

void		init_conversion(t_conversion *info)
{
	info->type = '\0';
	info->align = 0;
	info->fill_zero = '\0';
	info->width = 0;
	info->u_width = 0;
	info->precision = -1;
	info->indent = 0;
}

int			validate_conversion(t_conversion *info)
{
	info->u_width = info->width;
	if (info->width < 0)
	{
		info->u_width = info->width * -1;
		info->align = 1;
	}
	if (info->precision >= 0 && info->type != '%')
		info->fill_zero = 0;
	if (info->align == 1)
		info->fill_zero = 0;
	return (1);
}
