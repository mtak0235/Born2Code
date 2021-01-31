/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwoo <jwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 18:05:29 by jwoo              #+#    #+#             */
/*   Updated: 2021/01/31 18:06:00 by jwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	utoa_len(unsigned int n)
{
	size_t		len;

	len = 0;
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char			*ft_utoa(unsigned int n)
{
	char	*unsign;
	size_t	len;

	if (n == 0)
		return ("0");
	len = utoa_len(n);
	unsign = (char *)malloc(sizeof(char) * (len + 1));
	if (unsign == NULL)
		return (NULL);
	unsign[len] = 0;
	while (len-- > 0)
	{
		unsign[len] = (n % 10) + '0';
		n /= 10;
	}
	return (unsign);
}
