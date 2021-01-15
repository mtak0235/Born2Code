/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoh <seunghoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 22:44:43 by seunghoh          #+#    #+#             */
/*   Updated: 2020/12/27 02:34:25 by seunghoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src,
					int c, size_t n)
{
	size_t	idx;

	idx = 0;
	while (idx < n)
	{
		((unsigned char *)dst)[idx] = ((unsigned char *)src)[idx];
		if ((unsigned char)c == ((unsigned char *)src)[idx])
			return (dst + idx + 1);
		idx++;
	}
	return (NULL);
}
