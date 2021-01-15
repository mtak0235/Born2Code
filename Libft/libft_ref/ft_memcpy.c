/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjlee <stareta1202@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 20:47:11 by yongjlee          #+#    #+#             */
/*   Updated: 2020/12/02 01:30:58 by yongjlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	unsigned char	*dest;
	unsigned char	*src;
	size_t			count;

	if ((!s1 && !s2) || n == 0)
		return (s1);
	dest = (unsigned char *)s1;
	src = (unsigned char *)s2;
	count = 0;
	while (count < n)
	{
		dest[count] = src[count];
		count++;
	}
	*dest = *src;
	return (dest);
}
