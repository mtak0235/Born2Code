/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjlee <stareta1202@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 18:43:34 by yongjlee          #+#    #+#             */
/*   Updated: 2020/12/03 03:36:52 by yongjlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int		ft_get_digit_count(long int n)
{
	int		i;

	if (n < 0)
		n *= -1;
	i = 1;
	while (n > 9)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char			*str;
	int				digit_count;
	long int		long_n;

	long_n = n;
	digit_count = ft_get_digit_count(long_n);
	if (long_n < 0)
		digit_count++;
	if (!(str = malloc((digit_count + 1) * sizeof(char))))
		return (NULL);
	str[0] = '0';
	if (long_n < 0)
	{
		str[0] = '-';
		long_n *= -1;
	}
	str[digit_count] = '\0';
	while (((digit_count >= 0 && str[0] != '-')
				|| (digit_count > 0 && str[0] == '-')) && long_n != 0)
	{
		str[digit_count - 1] = (long_n % 10) + '0';
		long_n /= 10;
		digit_count--;
	}
	return (str);
}
