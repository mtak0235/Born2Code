/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hextoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwoo <jwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 18:11:42 by jwoo              #+#    #+#             */
/*   Updated: 2021/01/31 19:03:37 by jwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*free_two(char **temp, char **temp2)
{
	free(*temp);
	*temp = 0;
	free(*temp2);
	*temp2 = 0;
	return (0);
}

char		*ft_hextoa(unsigned long long hex, char type)
{
	char	*save;
	char	*temp;
	char	*mod;

	save = hex ? ft_strdup("") : ch_to_str(hex + '0');
	while (hex > 0)
	{
		if (hex % 16 < 10)
			mod = ch_to_str((hex % 16) + '0');
		else if (type == 'X')
			mod = ch_to_str(((hex % 16) - 10) + 'A');
		else
			mod = ch_to_str(((hex % 16) - 10) + 'a');
		temp = save;
		save = ft_strjoin(mod, temp);
		free_two(&mod, &temp);
		hex /= 16;
	}
	if (type == 'p')
	{
		temp = save;
		save = ft_strjoin("0x", temp);
		free_temp(&temp);
	}
	return (save);
}
