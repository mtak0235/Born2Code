/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoh <seunghoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 18:23:00 by seunghoh          #+#    #+#             */
/*   Updated: 2021/01/13 02:56:08 by seunghoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	*create_string(unsigned int n, size_t minus)
{
	size_t	size;
	char	*arr;

	size = 1;
	while (n > 9)
	{
		n /= 10;
		++size;
	}
	arr = (char *)malloc(sizeof(char) * (size + 1 + minus));
	if (arr == NULL)
		return (NULL);
	if (minus)
		arr[0] = '-';
	arr[size + minus] = '\0';
	return (arr);
}

static char	*put_nbr(unsigned int n, char *arr)
{
	char	*temp;

	if (n < 10)
	{
		*arr = n + '0';
		return (arr + 1);
	}
	else
	{
		temp = put_nbr(n / 10, arr);
		*temp = n % 10 + '0';
		return (temp + 1);
	}
}

char		*ft_itoa(int n)
{
	char			*arr;
	unsigned int	u_int;
	size_t			minus;

	u_int = n;
	minus = 0;
	if (n < 0)
	{
		minus = 1;
		u_int = n * -1;
	}
	arr = create_string(u_int, minus);
	if (arr == NULL)
		return (NULL);
	put_nbr(u_int, arr + minus);
	return (arr);
}

char		*ft_uitoa(unsigned int n)
{
	char			*arr;

	arr = create_string(n, 0);
	if (arr == NULL)
		return (NULL);
	put_nbr(n, arr);
	return (arr);
}
