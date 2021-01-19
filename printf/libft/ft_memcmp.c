/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoh <seunghoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 02:06:51 by seunghoh          #+#    #+#             */
/*   Updated: 2020/12/22 02:16:34 by seunghoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				idx;
	const unsigned char	*t1;
	const unsigned char	*t2;

	t1 = s1;
	t2 = s2;
	idx = 0;
	while (idx < n)
	{
		if (t1[idx] != t2[idx])
			return (t1[idx] - t2[idx]);
		idx++;
	}
	return (0);
}
