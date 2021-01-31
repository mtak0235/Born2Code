/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoh <seunghoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 15:38:30 by seunghoh          #+#    #+#             */
/*   Updated: 2020/12/27 18:06:44 by seunghoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	idx;
	size_t	size;
	char	*str;

	idx = 0;
	size = 0;
	if (s == NULL)
		return (NULL);
	while (s[idx])
		idx++;
	if (idx <= start)
		return (ft_strdup(""));
	size = idx < start + len ? idx - start : len;
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (NULL);
	idx = 0;
	while (idx < size)
	{
		str[idx] = s[idx + start];
		idx++;
	}
	str[idx] = '\0';
	return (str);
}
