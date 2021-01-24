/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwpark <sehwpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 18:27:22 by sehwpark          #+#    #+#             */
/*   Updated: 2020/12/25 10:17:10 by sehwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*copy;
	unsigned char	*copy2;

	if (dst == 0 && src == 0)
		return (dst);
	copy = (unsigned char *)dst;
	copy2 = (unsigned char *)src;
	i = 0;
	while (i < len)
	{
		copy[i] = copy2[i];
		i++;
	}
	return (dst);
}
