/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwpark <sehwpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 19:36:23 by sehwpark          #+#    #+#             */
/*   Updated: 2020/12/21 20:22:23 by sehwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *ptr, int value, size_t len)
{
	unsigned char *copy;

	copy = (unsigned char *)ptr;
	while (len--)
	{
		if (*copy == (unsigned char)value)
			return (copy);
		copy++;
	}
	return (0);
}
