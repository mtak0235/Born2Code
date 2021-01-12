/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtak <mtak@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 10:49:43 by mtak              #+#    #+#             */
/*   Updated: 2021/01/12 07:35:04 by mtak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	if (!*little)
		return (char *)big;
	i = 0;
	while (big[i] && i < len)
	{
		if (ft_memcmp(big + i, little, ft_strlen(little)) == 0)
			return (char *)big + i;
		i++;
	}
	return (0);
}
