/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoh <seunghoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 23:09:24 by seunghoh          #+#    #+#             */
/*   Updated: 2020/12/27 03:34:03 by seunghoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				idx;
	unsigned char		*temp_dst;
	const unsigned char	*temp_src;

	temp_dst = dst;
	temp_src = src;
	idx = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	while (idx < len)
	{
		if (dst < src)
			temp_dst[idx] = temp_src[idx];
		else
			temp_dst[len - idx - 1] = temp_src[len - idx - 1];
		idx++;
	}
	return (dst);
}
