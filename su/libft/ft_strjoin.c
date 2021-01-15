/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoh <seunghoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 23:40:54 by seunghoh          #+#    #+#             */
/*   Updated: 2020/12/27 18:11:28 by seunghoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size;
	size_t	idx;
	char	*str;

	size = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (NULL);
	idx = 0;
	while (s1[idx])
	{
		str[idx] = s1[idx];
		idx++;
	}
	size = idx;
	idx = 0;
	while (s2[idx])
	{
		str[size + idx] = s2[idx];
		idx++;
	}
	str[size + idx] = '\0';
	return (str);
}
