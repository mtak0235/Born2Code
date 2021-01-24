/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwpark <sehwpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 18:26:56 by sehwpark          #+#    #+#             */
/*   Updated: 2020/12/25 23:26:39 by sehwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memset(void *dst, int c, size_t len)
{
	size_t			i;
	unsigned char	*copy;

	i = 0;
	copy = (unsigned char *)dst;
	while (i < len)
	{
		copy[i] = (unsigned char)c;
		i++;
	}
	return (dst);
}
