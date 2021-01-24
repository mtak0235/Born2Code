/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwpark <sehwpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 20:05:15 by sehwpark          #+#    #+#             */
/*   Updated: 2021/01/07 20:42:35 by sehwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_count(char *s, char c)
{
	size_t		i;
	size_t		ret;

	i = 0;
	ret = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			while (s[i] != c && s[i])
				i++;
			ret++;
		}
		else
			i++;
	}
	return (ret);
}

static size_t	wordlen(char *s, int idx, char c)
{
	size_t		i;

	i = 0;
	while (s[i + idx] && s[i + idx] != c)
		i++;
	return (i);
}

static void		get_str(char *s, char c, size_t count, char **ret)
{
	size_t		i;
	size_t		len;
	size_t		curr;

	i = 0;
	curr = 0;
	while (s[curr] == c)
		curr++;
	while (s[curr] && i < count)
	{
		len = wordlen(s, curr, c);
		if (!(ret[i] = (char *)malloc(len + 1)))
			return ;
		ft_strlcpy(ret[i], &s[curr], len + 1);
		curr = curr + len;
		while (s[curr] && s[curr] == c)
			curr++;
		i++;
	}
}

char			**ft_split(char const *s, char c)
{
	char		**ret;
	size_t		count;

	if (!s)
		return (0);
	count = word_count((char *)s, c);
	if (!(ret = (char **)malloc(sizeof(char *) * (count + 1))))
		return (0);
	ret[count] = 0;
	get_str((char *)s, c, count, ret);
	return (ret);
}
