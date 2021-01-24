/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwpark <sehwpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 13:54:20 by sehwpark          #+#    #+#             */
/*   Updated: 2020/12/21 20:25:01 by sehwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	to_size(char *src)
{
	size_t	i;

	i = 0;
	while (src[i] != 0)
	{
		i++;
	}
	return (i);
}

size_t			ft_strlcat(char *dest, char *src, size_t size)
{
	size_t	i;
	size_t	dest_size;
	size_t	src_size;

	i = 0;
	dest_size = to_size(dest);
	src_size = to_size(src);
	if (size > 0)
	{
		if (size > dest_size + 1)
		{
			while (src[i] != '\0' && i + dest_size < (size - 1))
			{
				dest[dest_size + i] = src[i];
				i++;
			}
			dest[dest_size + i] = '\0';
		}
	}
	if (dest_size + 1 > size)
		return (src_size + size);
	else
		return (src_size + dest_size);
}
