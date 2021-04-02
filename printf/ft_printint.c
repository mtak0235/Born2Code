/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtak <mtak@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 17:17:13 by mtak              #+#    #+#             */
/*   Updated: 2021/02/20 04:25:52 by mtak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static void		print_flag(t_flag *flag, char *num, int size)
{
	int	minus;

	size = num[0] == '-' ? size + 1 : size;
	flag->width = size > flag->width ? size : flag->width;
	if (flag->indent)
		ft_putchar_fd(' ', 1);
	if (flag->minus == 0)
		while (size < flag->width)
		{
			ft_putchar_fd(' ', 1);
			size++;
		}
	if (num[0] == '-')
		ft_putchar_fd('-', 1);
	minus = num[0] == '-' ? 1 : 0;
	while (flag->precision > 0 && flag->precision--)
		ft_putchar_fd('0', 1);
	ft_putstr_fd(num + minus, 1);
	if (flag->minus == 1)
		while (size < flag->width)
		{
			size++;
			ft_putchar_fd(' ', 1);
		}
	free(num);
}

int				print_int(t_flag *flag, va_list ap)
{
	char	*num;
	int		pure_size;
	int		num_size;

	num = ft_itoa(va_arg(ap, int));
	if (num == NULL)
		return (0);
	if (num[0] == '0' && flag->precision == 0)
		num[0] = '\0';
	num_size = ft_strlen(num);
	pure_size = num[0] == '-' ? num_size - 1 : num_size;
	if (flag->precision >= 0 && flag->precision > pure_size)
	{
		flag->precision = flag->precision - pure_size;
		pure_size = pure_size + flag->precision;
	}
	else if (flag->zero == 1 && flag->width > num_size)
	{
		flag->precision = (flag->width - num_size);
		pure_size = pure_size + flag->precision;
	}
	else
		flag->precision = 0;
	print_flag(flag, num, pure_size);
	return (flag->width + flag->indent);
}

int				print_uint(t_flag *flag, va_list ap)
{
	char	*num;
	int		num_size;

	num = ft_uitoa(va_arg(ap, unsigned int));
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
		flag->precision = (flag->width - num_size);
		num_size = num_size + flag->precision;
	}
	else
		flag->precision = 0;
	print_flag(flag, num, num_size);
	return (flag->width + flag->indent);
}
