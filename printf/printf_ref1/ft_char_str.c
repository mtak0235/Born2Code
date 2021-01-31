/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwoo <jwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 18:18:51 by jwoo              #+#    #+#             */
/*   Updated: 2021/01/31 18:19:40 by jwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ch_to_str(char c)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * 2);
	str[0] = c;
	str[1] = 0;
	return (str);
}

char	*str_char(char *s1, char s2)
{
	char	*str;
	size_t	len;
	size_t	index;
	size_t	i;

	if (s1 == NULL)
		return (NULL);
	len = ft_strlen(s1);
	if ((str = (char *)malloc(sizeof(char) * (len + 2))) == 0)
		return (NULL);
	index = 0;
	i = 0;
	while (i < len)
		str[index++] = s1[i++];
	str[len] = s2;
	str[len + 1] = '\0';
	return (str);
}
