/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_remake.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwpark <sehwpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 18:47:00 by sehwpark          #+#    #+#             */
/*   Updated: 2021/01/23 22:11:13 by sehwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			numlen(long long n)
{
	int			len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		n *= -1;
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static long long	abs_power(long long n, long long p)
{
	long long	ret;

	if (p == 0)
		return (1);
	ret = 1;
	while (p)
	{
		ret *= n;
		p--;
	}
	return (ret);
}

char				*ft_itoa_remake(int n, t_info *info)
{
	int			size;
	long long	temp;
	int			i;
	long long	copy;
	char		*s;

	copy = (long long)n;
	size = numlen(copy);
	if (!(s = (char *)malloc(size + 1)))
		return (0);
	temp = abs_power(10, size - 1);
	i = 0;
	if (copy < 0)
	{
		info->nbr_sign = 1;
		copy *= -1;
	}
	s[size] = '\0';
	while (temp)
	{
		s[i++] = copy / temp + '0';
		copy %= temp;
		temp /= 10;
	}
	return (s);
}

char				*ft_uitoa_remake(unsigned int n)
{
	int					size;
	unsigned long long	temp;
	int					i;
	unsigned long long	copy;
	char				*s;

	copy = (unsigned long long)n;
	size = numlen(copy);
	if (!(s = (char *)malloc(size + 1)))
		return (0);
	temp = abs_power(10, size - 1);
	i = 0;
	s[size] = '\0';
	while (temp)
	{
		s[i++] = copy / temp + '0';
		copy %= temp;
		temp /= 10;
	}
	return (s);
}
