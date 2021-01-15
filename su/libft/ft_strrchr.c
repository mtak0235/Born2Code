/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoh <seunghoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 03:08:39 by seunghoh          #+#    #+#             */
/*   Updated: 2020/12/27 16:20:45 by seunghoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	idx;

	idx = (int)ft_strlen(s);
	while (idx >= 0)
	{
		if (s[idx] == (char)c)
			return ((char *)s + idx);
		idx--;
	}
	return (NULL);
}
