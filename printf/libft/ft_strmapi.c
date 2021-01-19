/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoh <seunghoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 22:07:02 by seunghoh          #+#    #+#             */
/*   Updated: 2020/12/27 18:06:07 by seunghoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	idx;
	char	*arr;

	idx = 0;
	if (s == NULL)
		return (NULL);
	arr = ft_strdup(s);
	if (arr == NULL)
		return (NULL);
	while (arr[idx])
	{
		arr[idx] = f(idx, arr[idx]);
		idx++;
	}
	return (arr);
}
