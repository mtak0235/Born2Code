/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwpark <sehwpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 16:55:11 by sehwpark          #+#    #+#             */
/*   Updated: 2021/01/23 21:35:46 by sehwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		size_sum(char const *s1, char const *s2)
{
	int		count;

	count = 0;
	while (*s1++)
		count++;
	while (*s2++)
		count++;
	return (count);
}

static void		join(char const *s1, char const *s2, char *ret)
{
	int		k;

	k = 0;
	while (*s1)
	{
		ret[k] = *s1;
		k++;
		s1++;
	}
	while (*s2)
	{
		ret[k] = *s2;
		k++;
		s2++;
	}
	ret[k] = '\0';
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	int		size;

	size = size_sum(s1, s2) + 1;
	if (!(ret = (char *)malloc(sizeof(char) * size)))
		return (0);
	join(s1, s2, ret);
	return (ret);
}
