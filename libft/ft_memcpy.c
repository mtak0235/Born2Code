/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtak <mtak@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 07:15:14 by mtak              #+#    #+#             */
/*   Updated: 2021/01/11 14:13:40 by mtak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*new_dst;
	const unsigned char	*new_src;

	new_dst = dst;
	new_src = src;
	while (n--)
		*new_dst++ = *new_src++;
	return (dst);
}
