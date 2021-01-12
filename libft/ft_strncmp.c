/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtak <mtak@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 10:06:51 by mtak              #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2021/01/12 16:08:53 by mtak             ###   ########.fr       */
=======
/*   Updated: 2021/01/12 10:06:00 by mtak             ###   ########.fr       */
>>>>>>> c83ac39f426120e89dac560f12b3caf6b85e57ba
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && i < n)
		i++;
	if (i == n)
		return (0);
<<<<<<< HEAD
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
=======
	return ((unsigned char)s1[i] -  (unsigned char)s2[i]);
>>>>>>> c83ac39f426120e89dac560f12b3caf6b85e57ba
}
