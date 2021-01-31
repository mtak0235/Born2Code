/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwoo <jwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 10:31:29 by jwoo              #+#    #+#             */
/*   Updated: 2021/01/31 18:20:25 by jwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_type(char c, char *type)
{
	const int	len = ft_strlen(type);
	int			i;

	i = -1;
	while (++i < len)
		if (c == type[i])
			return (1);
	return (0);
}

char	**free_args(char **split, int x)
{
	int	i;

	i = -1;
	while (++i <= x)
	{
		free(split[i]);
		split[i] = 0;
	}
	free(split);
	split = 0;
	return (0);
}

char	*free_temp(char **temp)
{
	free(*temp);
	*temp = 0;
	return (0);
}

char	*find_type(const char *str)
{
	const int	len = ft_strlen(str);
	char		*type;
	char		*temp;
	int			i;
	int			args;

	type = ft_strdup("");
	args = 0;
	i = 0;
	while (i < len)
	{
		if (str[i++] != '%')
			continue ;
		while (is_type(str[i], "-0.*123456789") == 1)
			i++;
		temp = type;
		if ((type = str_char(temp, str[i])) == 0)
			return (free_temp(&temp));
		free_temp(&temp);
		i++;
	}
	return (type);
}

char	**find_flag(const char *str, int args)
{
	char		**split;
	char		*temp;
	int			num;

	if ((split = (char **)malloc(sizeof(char *) * args)) == 0)
		return (0);
	num = 0;
	while (num < args)
	{
		if (*(str++) != '%')
			continue ;
		if ((split[num] = ft_strdup("")) == 0)
			return (free_args(split, num - 1));
		while (is_type(*str, "-0.*123456789") == 1)
		{
			temp = split[num];
			if ((split[num] = str_char(temp, *str)) == 0)
				return (free_args(split, num));
			free_temp(&temp);
			str++;
		}
		num++;
		str++;
	}
	return (split);
}
