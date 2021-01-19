/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinchoi <jinchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 02:54:20 by jinchoi           #+#    #+#             */
/*   Updated: 2021/01/16 04:55:00 by jinchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*ft_strjoin_free(char *s1, char *s2)
{
	int		len_s1;
	int		len_total;
	char	*ret;
	int		index;

	if (!s1)
		return (ft_substr(s2, 0, ft_strlen(s2)));
	if (!s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_total = len_s1 + ft_strlen(s2) + 1;
	if (!(ret = (char *)malloc(sizeof(char) * len_total)))
		return (NULL);
	index = -1;
	while (s1[++index])
		ret[index] = s1[index];
	free(s1);
	s1 = NULL;
	index = -1;
	while (s2[++index])
		ret[index + len_s1] = s2[index];
	ret[index + len_s1] = '\0';
	return (ret);
}

void		*ft_memmove(void *dest, void *src, size_t num)
{
	size_t		index;

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

size_t		ft_strlen(const char *str)
{
	size_t		index;

	index = 0;
	while (str[index] != '\0')
		index++;
	return (index);
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
	char		*ret;
	size_t		index;

	if (s == NULL)
		return (NULL);
	if (!(ret = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	index = 0;
	while (index < len)
	{
		if (ft_strlen(s) <= (size_t)start)
			ret[index] = '\0';
		else
			ret[index] = s[index + start];
		index++;
	}
	ret[index] = '\0';
	return (ret);
}
