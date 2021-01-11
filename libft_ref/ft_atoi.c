/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjlee <stareta1202@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 18:27:15 by yongjlee          #+#    #+#             */
/*   Updated: 2020/12/05 16:35:09 by yongjlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isspace(char c)
{
	if (c == ' ' || c == '\n' || c == '\t' ||
			c == '\v' || c == '\f' || c == '\r')
		return (1);
	else
		return (0);
}

int			ft_atoi(const char *str)
{
	size_t	ans;
	size_t	i;
	int		sign;

	ans = 0;
	i = 0;
	sign = 1;
	while (str[i] != 0 && isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		ans = (ans * 10) + str[i] - '0';
		i++;
	}
	if (ans > LLONG_MAX - 1 && sign == 1)
		return (-1);
	if (ans > LLONG_MAX && sign == -1)
		return (0);
	return (sign * ans);
}
