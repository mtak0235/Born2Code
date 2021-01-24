/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwpark <sehwpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 17:14:59 by sehwpark          #+#    #+#             */
/*   Updated: 2020/12/25 23:29:01 by sehwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memccpy(void *dst, const void *src, int c, size_t len)
{
	size_t			i;
	int				flag;
	unsigned char	*copy;

	copy = (unsigned char *)src;
	i = 0;
	flag = 0;
	while (i < len && copy[i] && !flag)
	{
		flag = (copy[i] == (unsigned char)c) ? 1 : 0;
		i++;
	}
	if (flag)
	{
		ft_memcpy(dst, copy, i);
		return (dst + i);
	}
	else
	{
		ft_memcpy(dst, copy, len);
		return (0);
	}
}
