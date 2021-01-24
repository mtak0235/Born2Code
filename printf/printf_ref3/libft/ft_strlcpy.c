/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwpark <sehwpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 13:07:20 by sehwpark          #+#    #+#             */
/*   Updated: 2020/12/25 10:26:35 by sehwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t		i;
	char		*p;
	size_t		src_size;

	if (dest == 0 && src == 0)
		return (0);
	p = (char *)src;
	src_size = 0;
	while (*p++)
		src_size++;
	i = 0;
	while (i + 1 < size && src[i])
	{
		*(dest + i) = *(src + i);
		i++;
	}
	if (size > 0)
		*(dest + i) = '\0';
	return (src_size);
}
