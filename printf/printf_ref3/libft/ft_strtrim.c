/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwpark <sehwpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 15:37:18 by sehwpark          #+#    #+#             */
/*   Updated: 2020/12/25 13:08:44 by sehwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		check_set(const char c, char *set)
{
	while (*set)
	{
		if (c == *set)
		{
			return (1);
		}
		set++;
	}
	return (0);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	size_t		front;
	size_t		back;
	size_t		len;
	char		*ret;

	if (!set || !s1)
		return ((char *)s1);
	front = 0;
	back = ft_strlen(s1) - 1;
	while (check_set(s1[front], (char *)set) && front <= ft_strlen(s1))
		front++;
	while (check_set(s1[back], (char *)set) && back != 0)
		back--;
	len = (back > front) ? back - front + 1 : 0;
	if (len <= 1)
		return (ft_strdup(""));
	if (!(ret = ft_calloc(1, len + 1)))
		return (0);
	ft_strlcpy(ret, s1 + front, len + 1);
	return (ret);
}
