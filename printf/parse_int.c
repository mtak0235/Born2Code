/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoh <seunghoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 00:39:16 by seunghoh          #+#    #+#             */
/*   Updated: 2021/01/15 05:52:13 by seunghoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "libft.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

static void		parse_info(t_conversion *info, char *num, size_t size)
{
	int	minus;

	size = num[0] == '-' ? size + 1 : size;
	info->u_width = size > info->u_width ? size : info->u_width;
	if (info->indent)
		ft_putchar_fd(' ', 1);
	if (info->align == 0)
		while (size < info->u_width)
		{
			ft_putchar_fd(' ', 1);
			size++;
		}
	if (num[0] == '-')
		ft_putchar_fd('-', 1);
	minus = num[0] == '-' ? 1 : 0;
	while (info->precision > 0 && info->precision--)
		ft_putchar_fd('0', 1);
	ft_putstr_fd(num + minus, 1);
	if (info->align == 1)
		while (size < info->u_width)
		{
			size++;
			ft_putchar_fd(' ', 1);
		}
	free(num);
}

int				parse_int(t_conversion *info, va_list ap)
{
	char	*num;
	size_t	pure_size;
	size_t	num_size;

	num = ft_itoa(va_arg(ap, int));
	if (num == NULL)
		return (0);
	if (num[0] == '0' && info->precision == 0)
		num[0] = '\0';
	num_size = ft_strlen(num);
	pure_size = num[0] == '-' ? num_size - 1 : num_size;
	if (info->precision >= 0 && (size_t)info->precision > pure_size)
	{
		info->precision = info->precision - (int)pure_size;
		pure_size = pure_size + info->precision;
	}
	else if (info->fill_zero == 1 && info->u_width > num_size)
	{
		info->precision = (int)(info->u_width - num_size);
		pure_size = pure_size + info->precision;
	}
	else
		info->precision = 0;
	parse_info(info, num, pure_size);
	return ((int)info->u_width + info->indent);
}

int				parse_uint(t_conversion *info, va_list ap)
{
	char	*num;
	size_t	num_size;

	num = ft_uitoa(va_arg(ap, int));
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
	parse_info(info, num, num_size);
	return ((int)info->u_width + info->indent);
}
