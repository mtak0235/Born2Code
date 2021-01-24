/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwpark <sehwpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 17:51:13 by sehwpark          #+#    #+#             */
/*   Updated: 2020/12/24 10:24:16 by sehwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*copy;
	unsigned char	*copy2;

	if (dst == 0 && src == 0)
		return (dst);
	copy = (unsigned char *)dst;
	copy2 = (unsigned char *)src;
	if (dst < src)
	{
		while (len--)
			*copy++ = *copy2++;
	}
	else
	{
		copy += len;
		copy2 += len;
		while (len--)
			*--copy = *--copy2;
	}
	return (dst);
}
