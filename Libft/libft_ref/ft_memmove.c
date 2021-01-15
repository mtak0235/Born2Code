/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjlee <stareta1202@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 20:49:43 by yongjlee          #+#    #+#             */
/*   Updated: 2020/12/02 01:51:31 by yongjlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	unsigned char	*dest;
	unsigned char	*src;
	size_t			i;

	i = 0;
	if (s1 == s2 || n == 0)
		return (s1);
	dest = (unsigned char *)s1;
	src = (unsigned char *)s2;
	if (s1 < s2)
		while (i < n)
		{
			dest[i] = src[i];
			i++;
		}
	else
		while (i < n)
		{
			dest[n - i - 1] = src[n - i - 1];
			i++;
		}
	return (dest);
}
