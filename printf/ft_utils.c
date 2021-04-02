/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtak <mtak@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 04:03:17 by mtak              #+#    #+#             */
/*   Updated: 2021/02/20 05:21:06 by mtak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void	init_flag(t_flag *flag)
{
	flag->type = 0;
	flag->width = 0;
	flag->minus = 0;
	flag->zero = 0;
	flag->precision = -1;
	flag->star = 0;
	flag->indent = 0;
}

char	*int2hex(unsigned long long num, int pin)
{
	char	*str;
	char	*hex;
	int		len;

	hex = pin ? "0123456789ABCDEF" : "0123456789abcdef";
	len = int2hex_len(num);
	if (!(str = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	str[len] = 0;
	while (--len >= 0)
	{
		str[len] = hex[num % 16];
		num /= 16;
	}
	return (str);
}

char	*ptr2hex(unsigned long long num)
{
	char	*str;
	char	*hex;
	int		len;

	hex = "0123456789abcdef";
	len = int2hex_len(num) + 2;
	if (!(str = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	str[len] = 0;
	while (--len >= 2)
	{
		str[len] = hex[num % 16];
		num /= 16;
	}
	str[0] = '0';
	str[1] = 'x';
	return (str);
}

int		int2hex_len(unsigned long long n)
{
	int len;

	len = 1;
	while (n > 15)
	{
		n /= 16;
		len++;
	}
	return (len);
}
