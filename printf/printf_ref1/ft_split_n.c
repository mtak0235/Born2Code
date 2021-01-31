/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_n.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwoo <jwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 18:08:07 by jwoo              #+#    #+#             */
/*   Updated: 2021/01/31 18:08:27 by jwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*split_n(char *s, int point, int x)
{
	char	*str;
	int		s_len;
	int		len;
	int		i;

	s_len = s ? ft_strlen(s) : 0;
	len = x == 0 ? point : s_len - point - 1;
	if ((str = (char *)malloc(sizeof(char) * (len + 1))) == 0)
		return (0);
	str[len] = '\0';
	i = -1;
	if (x == 0)
		while (++i < len)
			str[i] = s[i];
	else
		while (++i < len)
			str[i] = s[point + 1 + i];
	return (str);
}
