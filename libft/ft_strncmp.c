/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtak <mtak@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 10:06:51 by mtak              #+#    #+#             */
/*   Updated: 2021/01/11 14:25:09 by mtak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char *c1;
	unsigned char *c2;

	c1 = (unsigned char *)s1;
	c2 = (unsigned char *)s2;
	if ((!c1 && !c2) || !n)
		return (0);
	else if (!c1 || !c2)
		return (!c1 ? -1 : 1);
	while (n-- && *c1 && *c2)
	{
		if (*c1 != *c2)
			return ((int)(*c1 - *c2));
		c1++;
		c2++;
	}
	if (n != 0 && (!*c1 || !*c2))
		return ((int)(*c1 - *c2));
	return (0);
}
