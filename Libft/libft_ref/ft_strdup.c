/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjlee <stareta1202@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 21:10:20 by yongjlee          #+#    #+#             */
/*   Updated: 2020/12/05 22:29:20 by yongjlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *src)
{
	char	*word;
	int		i;
	int		size;

	i = 0;
	size = 0;
	while (src[size])
		size++;
	if (!(word = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (src[i])
	{
		word[i] = src[i];
		i++;
	}
	word[i] = 0;
	return (word);
}
