/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjlee <stareta1202@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 19:59:03 by yongjlee          #+#    #+#             */
/*   Updated: 2020/12/05 22:22:35 by yongjlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	unsigned char	*temp_dst;
	unsigned char	*temp_src;
	unsigned char	word;
	size_t			i;

	temp_dst = (unsigned char *)s1;
	temp_src = (unsigned char *)s2;
	word = c;
	i = 0;
	while (i < n)
	{
		temp_dst[i] = temp_src[i];
		if (temp_src[i] == word)
			return (&s1[i + 1]);
		i++;
	}
	return (0);
}
