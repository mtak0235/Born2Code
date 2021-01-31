/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoh <seunghoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 00:39:16 by seunghoh          #+#    #+#             */
/*   Updated: 2021/01/15 06:44:57 by seunghoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

static void		parse_info(t_conversion *info, char *num, size_t precision_size)
{
	if (info->indent)
		ft_putchar_fd(' ', 1);
	if (info->align == 0)
		while (precision_size < info->u_width)
		{
			if (info->fill_zero == 1)
				ft_putchar_fd('0', 1);
			else
				ft_putchar_fd(' ', 1);
			precision_size++;
		}
	while (info->precision--)
		ft_putchar_fd(*num++, 1);
	if (info->align == 1)
		while (precision_size < info->u_width)
		{
			ft_putchar_fd(' ', 1);
			precision_size++;
		}
}

int				parse_string(t_conversion *info, va_list ap)
{
	char	*str;
	size_t	str_size;
	int		flag;

	flag = 0;
	str = va_arg(ap, char *);
	if (str == NULL)
	{
		flag = 1;
		str = ft_strdup("(null)");
		if (str == NULL)
			return (0);
	}
	str_size = ft_strlen(str);
	if (info->precision >= 0 && (size_t)info->precision > str_size)
		info->precision = (int)str_size;
	else if (info->precision < 0)
		info->precision = (int)str_size;
	str_size = info->precision;
	info->u_width = str_size > info->u_width ? str_size : info->u_width;
	parse_info(info, str, str_size);
	if (flag)
		free(str);
	return ((int)info->u_width);
}

int				parse_char(t_conversion *info, va_list ap)
{
	char	*str;

	if (info->u_width < 1)
		info->u_width = 1;
	str = (char *)malloc(sizeof(char) * 2);
	if (str == NULL)
		return (0);
	str[0] = (char)va_arg(ap, int);
	str[1] = '\0';
	info->precision = 1;
	parse_info(info, str, 1);
	free(str);
	return ((int)info->u_width + info->indent);
}

int				parse_percent(t_conversion *info)
{
	char	*str;

	if (info->u_width < 1)
		info->u_width = 1;
	str = (char *)malloc(sizeof(char) * 2);
	if (str == NULL)
		return (0);
	str[0] = '%';
	str[1] = '\0';
	info->precision = 1;
	parse_info(info, str, 1);
	free(str);
	return ((int)info->u_width + info->indent);
}
