/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoh <seunghoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 15:08:09 by seunghoh          #+#    #+#             */
/*   Updated: 2020/12/27 04:14:20 by seunghoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	size_t	idx;
	char	*str;

	idx = 0;
	while (s1[idx])
		idx++;
	str = (char *)malloc(sizeof(char) * (idx + 1));
	if (str == NULL)
		return (NULL);
	idx = 0;
	while (s1[idx])
	{
		str[idx] = s1[idx];
		idx++;
	}
	str[idx] = '\0';
	return (str);
}
