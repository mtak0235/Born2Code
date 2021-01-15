/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoh <seunghoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 13:43:10 by seunghoh          #+#    #+#             */
/*   Updated: 2020/12/27 00:25:43 by seunghoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_space(char ch)
{
	int		idx;

	idx = 0;
	while (idx < 6)
		if (ch == "\t\n\v\f\r "[idx++])
			return (1);
	return (0);
}

int			ft_atoi(const char *str)
{
	int		result;
	int		sign;

	result = 0;
	sign = 1;
	while (is_space(*str))
		str++;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			sign = -1;
	while (ft_isdigit(*str))
	{
		result = result * 10 + *str - '0';
		str++;
	}
	return (result * sign);
}
