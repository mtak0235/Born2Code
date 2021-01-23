/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtak <mtak@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 03:18:52 by mtak              #+#    #+#             */
/*   Updated: 2021/01/23 03:19:00 by mtak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char		*ft_strjoin_f(char *s1, char *s2)
{
	size_t		len_s1;
	size_t		len_s2;
	char		*comb_str;
	int			index;

	if (!s1)
		return (ft_substr(s2, 0, ft_strlen(s2)));
	if (!s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if (!(comb_str = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1))))
		return (NULL);
	index = -1;
	while (s1[++index])
		comb_str[index] = s1[index];
	free(s1);
	s1 = NULL;
	index = -1;
	while (s2[++index])
		comb_str[index + len_s1] = s2[index];
	comb_str[index + len_s1] = '\0';
	return (comb_str);
}

void		*ft_memmove(void *dest, void *src, size_t num)
{
	size_t	index;

	if (dest == NULL && src == NULL)
		return (NULL);
	if ((unsigned char *)dest > (unsigned char *)src)
	{
		index = num;
		while (index > 0)
		{
			index--;
			((unsigned char *)dest)[index] = ((unsigned char *)src)[index];
		}
	}
	else
	{
		index = 0;
		while (index < num)
		{
			((unsigned char *)dest)[index] = ((unsigned char *)src)[index];
			index++;
		}
	}
	return (dest);
}

size_t		ft_strlen(const char *s)
{
	int cnt;

	cnt = 0;
	while (*s++)
		cnt++;
	return (cnt);
}

char		*ft_strdup(char *src)
{
	size_t		len_src;
	size_t		index;
	char		*ret;

	len_src = ft_strlen(src);
	if (!(ret = (char *)malloc(sizeof(char) * (len_src + 1))))
		return (NULL);
	index = 0;
	while (src[index] != '\0')
	{
		ret[index] = src[index];
		index++;
	}
	ret[index] = '\0';
	return (ret);
}

char		*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*extract;
	size_t	idx;

	if (!s)
		return (0);
	if (!(extract = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	idx = 0;
	while (idx < len)
	{
		if (ft_strlen(s) <= (size_t)start)
			extract[idx] = 0;
		else
			extract[idx] = s[idx + start];
		idx++;
	}
	extract[idx] = 0;
	return (extract);
}
