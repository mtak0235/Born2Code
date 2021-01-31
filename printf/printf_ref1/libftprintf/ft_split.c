/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwoo <jwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 22:41:08 by jwoo              #+#    #+#             */
/*   Updated: 2021/01/04 14:53:41 by jwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_num(char const *s, char c)
{
	size_t	num;
	size_t	index;

	num = 0;
	if (s[0] != c)
		num++;
	index = 1;
	while (index < ft_strlen(s))
	{
		if (s[index - 1] == c && s[index] != c)
			num++;
		index++;
	}
	return (num);
}

static char		**free_split(char **words, size_t num)
{
	size_t	n;

	n = 0;
	while (n <= num)
	{
		free(words[n]);
		words[n] = NULL;
	}
	free(words);
	words = NULL;
	return (words);
}

static char		**word_len(char **words, char const *s, char c)
{
	size_t	index;
	size_t	len;
	size_t	num;

	index = 0;
	num = 0;
	while (index < ft_strlen(s) && words != NULL)
	{
		while (s[index] == c && index < ft_strlen(s))
			index++;
		len = 0;
		while (s[index] != c && index < ft_strlen(s))
		{
			len++;
			index++;
		}
		if (len != 0)
		{
			words[num] = (char *)malloc(sizeof(char) * (len + 1));
			if (words[num] == NULL)
				free_split(words, num);
			num++;
		}
	}
	return (words);
}

static void		word_split(char **words, char const *s, char c)
{
	size_t	index;
	size_t	len;
	size_t	num;

	index = 0;
	num = 0;
	len = 0;
	while (index < ft_strlen(s))
	{
		if (s[index] == c)
		{
			index++;
			continue ;
		}
		len = 0;
		while (s[index] != c && index < ft_strlen(s))
		{
			words[num][len] = s[index];
			len++;
			index++;
		}
		words[num][len] = '\0';
		num++;
	}
	words[num] = NULL;
}

char			**ft_split(char const *s, char c)
{
	char	**words;
	size_t	num;

	if (s == NULL)
		return (NULL);
	num = word_num(s, c);
	words = (char **)malloc(sizeof(char *) * (num + 1));
	if (words == NULL)
		return (NULL);
	if (word_len(words, s, c) == NULL)
		return (NULL);
	word_split(words, s, c);
	return (words);
}
