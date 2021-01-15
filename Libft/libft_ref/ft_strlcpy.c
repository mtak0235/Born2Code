/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjlee <stareta1202@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 21:24:59 by yongjlee          #+#    #+#             */
/*   Updated: 2020/12/02 02:21:56 by yongjlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t n)
{
	size_t	i;

	if (!dst || !src)
		return (0);
	i = 0;
	if (!n)
		return (ft_strlen(src));
	if (n)
		while (src[i] && (i < n - 1))
		{
			dst[i] = src[i];
			i++;
		}
	dst[i] = 0;
	return (ft_strlen(src));
}
