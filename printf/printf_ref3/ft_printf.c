/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwpark <sehwpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 15:39:48 by sehwpark          #+#    #+#             */
/*   Updated: 2021/01/23 22:39:18 by sehwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_by_type(va_list ap, t_info *info)
{
	int		ret;

	ret = 0;
	if (info->type == 'c')
		ret = print_char(va_arg(ap, int), info);
	else if (info->type == '%')
		ret = print_char('%', info);
	else if (info->type == 's')
		ret = print_str(va_arg(ap, char *), info);
	else if (info->type == 'd' || info->type == 'i')
		ret = print_int(va_arg(ap, int), info);
	else if (info->type == 'x' || info->type == 'X' || info->type == 'u')
		ret = print_16(va_arg(ap, unsigned int), info);
	else if (info->type == 'p')
		ret = print_16(va_arg(ap, unsigned long long), info);
	return (ret);
}

int		parse2(va_list ap, char *format, t_info *info, int *i)
{
	int		ret;

	init_info(info);
	while (format[++(*i)] != '\0' && !(ft_strchr("uc%spdixX", format[*i])))
		check_info(ap, format, info, *i);
	if (format[*i] == '\0')
	{
		ret = -1;
		return (ret);
	}
	info->type = format[(*i)++];
	ret = print_by_type(ap, info);
	return (ret);
}

int		parse(va_list ap, char *format)
{
	int		i;
	int		ret;
	t_info	*info;

	i = 0;
	ret = 0;
	if (!(info = (t_info *)malloc(sizeof(t_info))))
		return (-1);
	while (format[i])
	{
		while (format[i] != '%' && format[i])
		{
			write(1, &format[i++], 1);
			ret++;
		}
		if (format[i] == '%' && format[i + 1] != '\0')
			ret += parse2(ap, format, info, &i);
		if (ret == -1)
			break ;
	}
	free(info);
	return (ret);
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	int		ret;

	if (!ft_strncmp(format, "%", 2))
		return (-1);
	va_start(ap, format);
	ret = parse(ap, (char *)format);
	va_end(ap);
	return (ret);
}
