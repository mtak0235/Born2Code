/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoh <seunghoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 00:36:21 by seunghoh          #+#    #+#             */
/*   Updated: 2020/12/22 02:00:40 by seunghoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				idx;
	const unsigned char	*temp;

	temp = s;
	idx = 0;
	while (idx < n)
	{
		if (temp[idx] == (unsigned char)c)
			return ((void *)(temp + idx));
		idx++;
	}
	return (NULL);
}
