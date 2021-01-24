/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwpark <sehwpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 18:47:00 by sehwpark          #+#    #+#             */
/*   Updated: 2021/01/16 15:49:29 by sehwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			numlen(long long n)
{
	int			len;

	len = n < 0 ? 1 : 0;
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

char				*ft_itoa(int n)
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
	temp = n < 0 ? abs_power(10, size - 2) : abs_power(10, size - 1);
	i = 0;
	if (copy < 0)
	{
		s[i++] = '-';
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
