/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtak <mtak@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 16:09:04 by mtak              #+#    #+#             */
/*   Updated: 2021/02/20 04:25:29 by mtak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static void	print_flag(t_flag *flag, char *num, int size, int ost)
{
	if (flag->indent)
		ft_putchar_fd(' ', 1);
	flag->width = size > flag->width ? size : flag->width;
	if (flag->minus == 0)
		while (size++ < flag->width)
			ft_putchar_fd(' ', 1);
	if (num[0] == '0' && num[1] == 'x')
	{
		ft_putstr_fd("0x", 1);
		ost = 2;
	}
	while (flag->precision > 0 && flag->precision--)
		ft_putchar_fd('0', 1);
	ft_putstr_fd(num + ost, 1);
	if (flag->minus == 1)
		while (size++ < flag->width)
			ft_putchar_fd(' ', 1);
}

int			print_hex(t_flag *flag, va_list ap, int pin)
{
	char	*num;
	int		num_size;

	num = int2hex(va_arg(ap, unsigned int), pin);
	if (num == NULL)
		return (0);
	if (num[0] == '0' && flag->precision == 0)
		num[0] = '\0';
	num_size = ft_strlen(num);
	if (flag->precision >= 0 && flag->precision > num_size)
	{
		flag->precision = flag->precision - num_size;
		num_size = num_size + flag->precision;
	}
	else if (flag->zero == 1 && flag->width > num_size)
	{
		flag->precision = flag->width - num_size;
		num_size = num_size + flag->precision;
	}
	else
		flag->precision = 0;
	print_flag(flag, num, num_size, 0);
	free(num);
	return (flag->width + flag->indent);
}

int			print_ptr(t_flag *flag, va_list ap)
{
	char	*num;
	int		num_size;

	num = ptr2hex(va_arg(ap, unsigned long long));
	if (num == NULL)
		return (0);
	if (num[2] == '0' && flag->precision == 0 && num[3] == '\0')
		num[2] = '\0';
	num_size = ft_strlen(num);
	if (flag->precision >= 0 && flag->precision + 2 > num_size)
	{
		flag->precision = flag->precision - num_size + 2;
		num_size = num_size + flag->precision;
	}
	else if (flag->zero == 1 && flag->width > num_size)
	{
		flag->precision = (flag->width - num_size);
		num_size = num_size + flag->precision;
	}
	else
		flag->precision = 0;
	print_flag(flag, num, num_size, 0);
	free(num);
	return (flag->width + flag->indent);
}
