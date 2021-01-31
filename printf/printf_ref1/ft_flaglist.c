/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flaglist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwoo <jwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 18:03:45 by jwoo              #+#    #+#             */
/*   Updated: 2021/01/31 19:17:49 by jwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flag_list	ft_sort_0(t_flag_list flag, char **format, char type)
{
	while (**format == '-' || **format == '0')
	{
		if (**format == '-')
			flag.sort_0 = -1;
		if (**format == '0' && is_type(type, "csp") == 0)
			flag.sort_0 = (flag.sort_0 == -1) ? -1 : 1;
		(*format)++;
	}
	return (flag);
}

t_flag_list	ft_width(t_flag_list flag, char **format)
{
	if (**format == '*')
	{
		flag.wild_width = 1;
		(*format)++;
		return (flag);
	}
	while (is_type(**format, "1234567890") == 1)
	{
		flag.width = flag.width * 10 + (**format - '0');
		(*format)++;
	}
	return (flag);
}

t_flag_list	ft_pre(t_flag_list flag, char **format, char type)
{
	if (**format == '*')
	{
		flag.wild_pre = 1;
		(*format)++;
		return (flag);
	}
	while (is_type(**format, "1234567890") == 1 && type != '%')
	{
		flag.pre = flag.pre * 10 + (**format - '0');
		(*format)++;
	}
	if (flag.pre >= 0 && type != '%')
		flag.sort_0 = (flag.sort_0 == 1) ? 0 : flag.sort_0;
	return (flag);
}

t_flag_list	ft_flag(char *format, char type)
{
	t_flag_list	flag;

	flag.sort_0 = 0;
	flag.wild_width = 0;
	flag.width = 0;
	flag.wild_pre = 0;
	flag.pre = -1;
	if (*format == '-' || *format == '0')
		flag = ft_sort_0(flag, &format, type);
	if (is_type(*format, "*1234567890") == 1)
		flag = ft_width(flag, &format);
	if (*format == '.')
	{
		if (type != '%')
			flag.pre = 0;
		format++;
		flag = ft_pre(flag, &format, type);
	}
	return (flag);
}
