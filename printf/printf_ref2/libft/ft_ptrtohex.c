/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptrtohex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoh <seunghoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 18:23:00 by seunghoh          #+#    #+#             */
/*   Updated: 2021/01/15 04:27:12 by seunghoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	*create_string(unsigned long long n)
{
	size_t	size;
	char	*arr;

	size = 1;
	while (n > 15)
	{
		n /= 16;
		++size;
	}
	arr = (char *)malloc(sizeof(char) * (size + 3));
	if (arr == NULL)
		return (NULL);
	arr[size + 2] = '\0';
	return (arr);
}

static char	*put_nbr(unsigned long long n, char *arr)
{
	char	*temp;
	char	*hex;

	hex = "0123456789abcdef";
	if (n < 16)
	{
		*arr = hex[n];
		return (arr + 1);
	}
	else
	{
		temp = put_nbr(n / 16, arr);
		*temp = hex[n % 16];
		return (temp + 1);
	}
}

char		*ft_ptrtohex(unsigned long long n)
{
	char			*arr;

	arr = create_string(n);
	if (arr == NULL)
		return (NULL);
	arr[0] = '0';
	arr[1] = 'x';
	put_nbr(n, arr + 2);
	return (arr);
}
