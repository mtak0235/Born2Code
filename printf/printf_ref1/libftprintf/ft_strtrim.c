/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwoo <jwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 17:35:24 by jwoo              #+#    #+#             */
/*   Updated: 2021/01/04 14:52:48 by jwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	find_end(char const *s1, char const *set)
{
	size_t	end;
	size_t	index;

	end = ft_strlen(s1);
	while (end > 0)
	{
		index = 0;
		while (index < ft_strlen(set))
		{
			if (s1[end - 1] == set[index])
				break ;
			index++;
		}
		if (index == ft_strlen(set))
			break ;
		end--;
	}
	return (end);
}

static size_t	find_start(char const *s1, char const *set)
{
	size_t	start;
	size_t	index;

	start = 0;
	while (start < ft_strlen(s1))
	{
		index = 0;
		while (index < ft_strlen(set))
		{
			if (s1[start] == set[index])
				break ;
			index++;
		}
		if (index == ft_strlen(set))
			break ;
		start++;
	}
	return (start);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	index;
	size_t	end;
	size_t	start;
	size_t	len;

	if (s1 == NULL || set == NULL)
		return (NULL);
	end = find_end(s1, set);
	start = find_start(s1, set);
	if (start < end)
		len = end - start;
	else
		len = 0;
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	index = 0;
	while (index < len)
	{
		str[index] = s1[start + index];
		index++;
	}
	str[index] = '\0';
	return (str);
}
