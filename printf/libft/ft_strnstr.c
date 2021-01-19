/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoh <seunghoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 03:21:29 by seunghoh          #+#    #+#             */
/*   Updated: 2020/12/27 00:28:34 by seunghoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	idx;
	size_t	jdx;

	idx = 0;
	if (needle[idx] == 0)
		return ((char *)haystack);
	while (haystack[idx] && idx < len)
	{
		if (haystack[idx] == needle[0])
		{
			jdx = 0;
			while (needle[jdx] && jdx + idx < len)
			{
				if (haystack[idx + jdx] != needle[jdx])
					break ;
				jdx++;
			}
			if (needle[jdx] == 0)
				return ((char *)(haystack + idx));
		}
		idx++;
	}
	return (NULL);
}
