/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjlee <stareta1202@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 21:03:22 by yongjlee          #+#    #+#             */
/*   Updated: 2021/01/12 05:42:04 by mtak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char			**ft_free(char **temp)
{
	unsigned int	i;

	i = 0;
	while (temp[i] != 0)
		free(temp[i++]);
	free(temp);
	return (0);
}

unsigned int	check_num(char const *s, char c)
{
	unsigned int	i;
	unsigned int	num;

	if (s[0] == 0)
		return (0);
	i = 0;
	num = 0;
	while (s[i] != '\0' && s[i] == c)
		i++;
	while (s[i] != '\0')
	{
		if (s[i] != c)
			num++;
		if (i != 0 && s[i] != c && s[i - 1] != c)
			num--;
		i++;
	}
	return (num);
}

void			find_str(char **str_idx, unsigned int *str_idx_len, char c)
{
	unsigned int	i;

	*str_idx += *str_idx_len;
	*str_idx_len = 0;
	i = 0;
	while (**str_idx != '\0' && **str_idx == c)
		(*str_idx)++;
	while ((*str_idx)[i] != '\0' && (*str_idx)[i] != c)
	{
		(*str_idx_len)++;
		i++;
	}
	return ;
}

char			**ft_split(char const *s, char c)
{
	char			**temp;
	char			*str_idx;
	unsigned int	str_idx_len;
	unsigned int	num_str;
	unsigned int	i;

	if (!s)
		return (0);
	num_str = check_num(s, c);
	if (!(temp = (char **)malloc(sizeof(char *) * (num_str + 1))))
		return (0);
	str_idx = (char *)s;
	str_idx_len = 0;
	i = 0;
	while (i < num_str)
	{
		find_str(&str_idx, &str_idx_len, c);
		if (!(temp[i] = (char *)malloc(sizeof(char) * (str_idx_len + 1))))
			return (ft_free(temp));
		ft_strlcpy(temp[i], str_idx, str_idx_len + 1);
		i++;
	}
	temp[i] = 0;
	return (temp);
}
