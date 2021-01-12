/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtak <mtak@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 13:49:02 by mtak              #+#    #+#             */
/*   Updated: 2021/01/11 15:59:52 by mtak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char		*new_dst;
	const unsigned char	*new_src;

	new_dst = dst;
	new_src = src;
	if (dst < src)
	{
		while (n--)
			*new_dst++ = *new_src++;
	}
	else
	{
		new_dst += (n - 1);
		new_src += (n - 1);
		while (n--)
			*new_dst-- = *new_src--;
	}
	return (dst);
}
