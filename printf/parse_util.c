/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoh <seunghoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 22:26:07 by seunghoh          #+#    #+#             */
/*   Updated: 2021/01/15 16:44:08 by seunghoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "libft.h"
#include <stddef.h>
#include <stdarg.h>

int		check_align_zero(t_conversion *info, char ch)
{
	if (ch == '-')
	{
		info->align = 1;
		return (1);
	}
	else if (ch == '0')
	{
		info->fill_zero = 1;
		return (1);
	}
	else if (ch == ' ')
	{
		info->indent = 1;
		return (1);
	}
	return (0);
}

int		check_width(t_conversion *info, va_list ap, char ch, int flag)
{
	if (ft_isdigit(ch) && flag == 0)
	{
		info->width = info->width * 10 + ch - '0';
		return (1);
	}
	else if (flag == 1)
	{
		info->width = va_arg(ap, int);
		return (1);
	}
	return (0);
}

int		check_precision(t_conversion *info, va_list ap, char ch, int flag)
{
	if (ft_isdigit(ch) && flag == 0)
	{
		info->precision = info->precision * 10 + ch - '0';
		return (1);
	}
	else if (flag == 0 && ch == '.')
	{
		if (info->precision < 0)
		{
			info->precision = 0;
			return (1);
		}
		return (0);
	}
	else if (flag == 1)
	{
		info->precision = va_arg(ap, int);
		return (2);
	}
	return (0);
}

int		check_type(t_conversion *info, char ch)
{
	char	*set;
	char	*res;

	set = "cspdiuxX%";
	if ((res = ft_strchr(set, ch)) != NULL)
	{
		info->type = *res;
		return (1);
	}
	return (0);
}
