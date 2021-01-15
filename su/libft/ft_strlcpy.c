/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoh <seunghoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 03:11:37 by seunghoh          #+#    #+#             */
/*   Updated: 2020/12/27 16:20:17 by seunghoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	idx;
	size_t	src_len;

	src_len = 0;
	idx = 0;
	if (src == NULL)
		return (src_len);
	while (src[src_len])
		src_len++;
	while (idx + 1 < dstsize && src[idx])
	{
		dst[idx] = src[idx];
		idx++;
	}
	if (dst != NULL && dstsize)
		dst[idx] = '\0';
	return (src_len);
}
