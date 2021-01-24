/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwpark <sehwpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 13:50:48 by sehwpark          #+#    #+#             */
/*   Updated: 2020/12/24 10:29:52 by sehwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	src_size(char *src)
{
	int		i;

	i = 0;
	while (src[i])
	{
		i++;
	}
	return (i);
}

char		*ft_strdup(char *src)
{
	char	*dest;
	char	*copy;

	if (!(dest = (char*)malloc(src_size(src) + 1)))
		return (0);
	copy = dest;
	while (*src)
	{
		*copy = *src;
		copy++;
		src++;
	}
	*copy = '\0';
	return (dest);
}
