/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoh <seunghoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 17:53:23 by seunghoh          #+#    #+#             */
/*   Updated: 2020/12/27 03:30:25 by seunghoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t idx;

	idx = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	while (idx < n)
	{
		((char *)dst)[idx] = ((char *)src)[idx];
		idx++;
	}
	return (dst);
}
