/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoh <seunghoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 00:39:16 by seunghoh          #+#    #+#             */
/*   Updated: 2021/01/15 06:44:35 by seunghoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "libft.h"
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>

static void		parse_info(t_conversion *info, char *num, size_t size, int ost)
{
	if (info->indent)
		ft_putchar_fd(' ', 1);
	info->u_width = size > info->u_width ? size : info->u_width;
	if (info->align == 0)
		while (size < info->u_width)
		{
			ft_putchar_fd(' ', 1);
			size++;
		}
	if (num[0] == '0' && num[1] == 'x')
	{
		ft_putstr_fd("0x", 1);
		ost = 2;
	}
	while (info->precision > 0 && info->precision--)
		ft_putchar_fd('0', 1);
	ft_putstr_fd(num + ost, 1);
	if (info->align == 1)
		while (size < info->u_width)
		{
			size++;
			ft_putchar_fd(' ', 1);
		}
}

int				parse_hex(t_conversion *info, va_list ap, int flag)
{
	char	*num;
	size_t	num_size;

	num = ft_uitohex(va_arg(ap, unsigned int), flag);
	if (num == NULL)
		return (0);
	if (num[0] == '0' && info->precision == 0)
		num[0] = '\0';
	num_size = ft_strlen(num);
	if (info->precision >= 0 && (size_t)info->precision > num_size)
	{
		info->precision = info->precision - (int)num_size;
		num_size = num_size + info->precision;
	}
	else if (info->fill_zero == 1 && info->u_width > num_size)
	{
		info->precision = (int)(info->u_width - num_size);
		num_size = num_size + info->precision;
	}
	else
		info->precision = 0;
	parse_info(info, num, num_size, 0);
	free(num);
	return ((int)info->u_width + info->indent);
}

int				parse_ptr(t_conversion *info, va_list ap)
{
	char	*num;
	size_t	num_size;

	num = ft_ptrtohex(va_arg(ap, unsigned long long));
	if (num == NULL)
		return (0);
	if (num[2] == '0' && info->precision == 0 && num[3] == '\0')
		num[2] = '\0';
	num_size = ft_strlen(num);
	if (info->precision >= 0 && (size_t)info->precision + 2 > num_size)
	{
		info->precision = info->precision - (int)num_size + 2;
		num_size = num_size + info->precision;
	}
	else if (info->fill_zero == 1 && info->u_width > num_size)
	{
		info->precision = (int)(info->u_width - num_size);
		num_size = num_size + info->precision;
	}
	else
		info->precision = 0;
	parse_info(info, num, num_size, 0);
	free(num);
	return ((int)info->u_width + info->indent);
}
