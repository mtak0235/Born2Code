/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoh <seunghoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 01:41:38 by seunghoh          #+#    #+#             */
/*   Updated: 2020/12/29 22:09:13 by seunghoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	idx;

	idx = 0;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dstsize == 0)
		return (src_len);
	if (dst_len + 1 > dstsize)
		return (dstsize + src_len);
	while (*src && (dst_len + idx + 1) < dstsize)
		dst[dst_len + idx++] = *src++;
	dst[dst_len + idx] = '\0';
	return (dst_len + src_len);
}
