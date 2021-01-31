/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitohex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoh <seunghoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 18:23:00 by seunghoh          #+#    #+#             */
/*   Updated: 2021/01/13 19:19:50 by seunghoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	*create_string(unsigned int n)
{
	size_t	size;
	char	*arr;

	size = 1;
	while (n > 15)
	{
		n /= 16;
		++size;
	}
	arr = (char *)malloc(sizeof(char) * (size + 1));
	if (arr == NULL)
		return (NULL);
	arr[size] = '\0';
	return (arr);
}

static char	*put_nbr(unsigned int n, char *arr, int flag)
{
	char	*temp;
	char	*hex[2];

	hex[0] = "0123456789abcdef";
	hex[1] = "0123456789ABCDEF";
	if (n < 16)
	{
		*arr = hex[flag][n];
		return (arr + 1);
	}
	else
	{
		temp = put_nbr(n / 16, arr, flag);
		*temp = hex[flag][n % 16];
		return (temp + 1);
	}
}

char		*ft_uitohex(unsigned int n, int flag)
{
	char			*arr;

	arr = create_string(n);
	if (arr == NULL)
		return (NULL);
	put_nbr(n, arr, flag);
	return (arr);
}
