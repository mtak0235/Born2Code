/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwpark <sehwpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 11:10:30 by sehwpark          #+#    #+#             */
/*   Updated: 2021/01/23 22:20:00 by sehwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_strndup(char *str, int len)
{
	int		i;
	char	*buf;

	if (!(buf = (char *)malloc(sizeof(char) * len + 1)))
		return (0);
	i = 0;
	while (i < len)
	{
		buf[i] = str[i];
		i++;
	}
	buf[i] = '\0';
	return (buf);
}

void		init_info(t_info *info)
{
	info->minus = 0;
	info->zero = 0;
	info->width = 0;
	info->dot = -1;
	info->type = 0;
	info->nbr_sign = 0;
}

void		check_width_and_dot(char *format, t_info *info, int i)
{
	if (ft_isdigit(format[i]))
	{
		if (info->dot == -1)
			info->width = info->width * 10 + format[i] - 48;
		else
			info->dot = info->dot * 10 + format[i] - 48;
	}
}

void		check_star(va_list ap, char *format, t_info *info, int i)
{
	if (format[i] == '*')
	{
		if (info->dot == -1)
		{
			info->width = va_arg(ap, int);
			if (info->width < 0)
			{
				info->width *= -1;
				info->minus = 1;
			}
		}
		else
		{
			info->dot = va_arg(ap, int);
			if (info->dot < 0)
				info->dot = -1;
		}
	}
}

void		check_info(va_list ap, char *format, t_info *info, int i)
{
	if (format[i] == '0' && info->width == 0 && info->dot == -1)
		info->zero = 1;
	else if (format[i] == ' ')
		write(1, " ", 1);
	else if (format[i] == '-')
		info->minus = 1;
	else if (format[i] == '.')
		info->dot = 0;
	else if (ft_isdigit(format[i]))
		check_width_and_dot(format, info, i);
	else if (format[i] == '*')
		check_star(ap, format, info, i);
}
