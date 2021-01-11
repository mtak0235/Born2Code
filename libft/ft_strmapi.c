/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtak <mtak@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 05:32:39 by mtak              #+#    #+#             */
/*   Updated: 2020/12/31 06:15:24 by mtak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char *new_str;
	unsigned int len;
	int i;

	if(!s || !f)
		return 0;
	len = ft_strlen(s);
	if(!(new_str = (char *)malloc(sizeof(char) * len + 1)))
		return 0;
	i = -1;
	while(s[++i])
		new_str[i] = f(i, s[i]);
	new_str[i] = 0;
	return new_str;
}

