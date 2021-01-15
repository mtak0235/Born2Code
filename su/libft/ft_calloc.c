/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoh <seunghoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 14:55:38 by seunghoh          #+#    #+#             */
/*   Updated: 2020/12/27 04:14:35 by seunghoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	char	*array;
	size_t	idx;

	array = (char *)malloc(count * size);
	if (array == NULL)
		return (NULL);
	idx = 0;
	while (idx < count * size)
		array[idx++] = 0;
	return ((void *)array);
}
