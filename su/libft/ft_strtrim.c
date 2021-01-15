/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoh <seunghoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 00:42:52 by seunghoh          #+#    #+#             */
/*   Updated: 2020/12/27 18:13:07 by seunghoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	int		idx;
	int		start;
	int		end;
	char	*str;

	idx = 0;
	if (s1 == NULL)
		return (NULL);
	while (s1[idx] && ft_strchr(set, s1[idx]))
		idx++;
	start = idx;
	idx = (int)ft_strlen(s1) - 1;
	while (idx >= 0 && ft_strchr(set, s1[idx]))
		idx--;
	end = idx;
	if (end < start)
		return (ft_strdup(""));
	str = (char *)malloc(sizeof(char) * (end - start + 2));
	if (str == NULL)
		return (NULL);
	idx = 0;
	ft_strlcpy(str, s1 + start, end - start + 2);
	return (str);
}
