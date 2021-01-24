/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwpark <sehwpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 19:05:07 by sehwpark          #+#    #+#             */
/*   Updated: 2020/12/24 10:33:21 by sehwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *ptr1, const void *ptr2, size_t len)
{
	size_t			i;
	unsigned char	*copy1;
	unsigned char	*copy2;

	i = 0;
	copy1 = (unsigned char *)ptr1;
	copy2 = (unsigned char *)ptr2;
	while (i < len)
	{
		if (copy2[i] != copy1[i])
			return ((unsigned char)copy1[i] - (unsigned char)copy2[i]);
		i++;
	}
	return (0);
}
