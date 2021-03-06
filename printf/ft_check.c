/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtak <mtak@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 16:05:04 by mtak              #+#    #+#             */
/*   Updated: 2021/02/20 05:13:00 by mtak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	check_flag(t_flag *flag, char c)
{
	if (c == '-')
		return (flag->minus = 1);
	if (c == '0')
		return (flag->zero = 1);
	if (c == ' ')
		return (flag->indent = 1);
	return (0);
}

int	check_precision(int c, va_list ap, t_flag *flag, int pin)
{
	if (ft_isdigit(c) && pin == 1)
	{
		flag->precision = (flag->precision) * 10 + c - '0';
		return (1);
	}
	else if (pin == 1 && c == '.')
	{
		if (flag->precision < 0)
		{
			flag->precision = 0;
			return (1);
		}
		return (0);
	}
	else if (pin == 2)
	{
		flag->precision = va_arg(ap, int);
		return (2);
	}
	return (0);
}

int	check_width(int c, va_list ap, t_flag *flag, int pin)
{
	if (ft_isdigit(c) && pin == 1)
		return (flag->width = (flag->width) * 10 + c - '0');
	else if (pin == 2)
	{
		flag->width = va_arg(ap, int);
		flag->star = 1;
		return (1);
	}
	return (0);
}

int	check_type(char c, t_flag *flag)
{
	char	*set;
	int		i;

	set = "cspdiuxX%";
	i = 0;
	while (set[i])
	{
		if (set[i] == c)
		{
			i++;
			flag->type |= i;
			return (1);
		}
		i++;
	}
	return (0);
}
