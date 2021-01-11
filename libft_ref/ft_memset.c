/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjlee <stareta1202@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 20:54:40 by yongjlee          #+#    #+#             */
/*   Updated: 2020/11/27 20:56:12 by yongjlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*temp;
	size_t			count;

	if (len == 0)
	{
		return (b);
	}
	count = 0;
	temp = (unsigned char *)b;
	while (count < len)
	{
		*temp = (unsigned char)c;
		temp++;
		count++;
	}
	return (b);
}
