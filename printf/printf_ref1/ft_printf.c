/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwoo <jwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 10:28:43 by jwoo              #+#    #+#             */
/*   Updated: 2021/01/31 19:17:10 by jwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_char(va_list ap, t_flag_list fl)
{
	char	ch;
	int		ret;

	fl.width = (fl.wild_width == 1) ? va_arg(ap, int) : fl.width;
	fl.pre = (fl.wild_pre == 1) ? va_arg(ap, int) : fl.pre;
	ch = va_arg(ap, int);
	fl.sort_0 = (fl.width < 0) ? -1 : fl.sort_0;
	fl.width = (fl.width < 0) ? -fl.width : fl.width;
	ret = 0;
	if (fl.width > 0 && fl.sort_0 == -1)
	{
		ret += write(1, &ch, 1);
		while (--fl.width > 0)
			ret += write(1, " ", 1);
	}
	else if (fl.width > 0)
	{
		while (--fl.width > 0)
			ret += write(1, " ", 1);
		ret += write(1, &ch, 1);
	}
	else
		ret += write(1, &ch, 1);
	return (ret);
}

char	*str_null(char *str)
{
	if (str == 0)
		return ("(null)");
	return (str);
}

char	*print_type(va_list ap, t_flag_list fl, char type)
{
	char		*temp;

	temp = 0;
	fl.width = (fl.wild_width == 1) ? va_arg(ap, int) : fl.width;
	fl.pre = (fl.wild_pre == 1) ? va_arg(ap, int) : fl.pre;
	if (type == '%')
		temp = ch_to_str('%');
	else if (type == 's')
		temp = str_null(va_arg(ap, char *));
	else if (type == 'd' || type == 'i')
		temp = ft_itoa(va_arg(ap, int));
	else if (type == 'x' || type == 'X')
		temp = ft_hextoa(va_arg(ap, unsigned int), type);
	else if (type == 'u')
		temp = ft_utoa(va_arg(ap, unsigned int));
	else if (type == 'p')
		temp = ft_hextoa(va_arg(ap, long long), type);
	temp = (fl.pre >= 0) ? print_pre(fl, temp, type) : temp;
	temp = (fl.width == 0) ? temp : print_width(fl, temp, type);
	return (temp);
}

int		ret_printf(va_list ap, const char *format, char **flag, char *type)
{
	char		*temp;
	int			i;
	int			ret;
	t_flag_list	fl;

	ret = 0;
	i = 0;
	while (*format)
	{
		if (*format != '%')
			ret += write(1, format++, 1);
		else
		{
			fl = ft_flag(flag[i], type[i]);
			if (type[i] == 'c')
				ret += print_char(ap, fl);
			else
			{
				temp = print_type(ap, fl, type[i]);
				ret += write(1, temp, ft_strlen(temp));
			}
			format += ft_strlen(flag[i++]) + 2;
		}
	}
	return (ret);
}

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	char		**flag;
	char		*type;
	int			args;
	int			ret;

	if (format == 0)
		return (-1);
	type = find_type(format);
	args = ft_strlen(type);
	flag = find_flag(format, args);
	va_start(ap, format);
	ret = ret_printf(ap, format, flag, type);
	va_end(ap);
	return (ret);
}
