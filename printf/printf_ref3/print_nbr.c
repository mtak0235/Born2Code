/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwpark <sehwpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 15:28:53 by sehwpark          #+#    #+#             */
/*   Updated: 2021/01/23 22:23:30 by sehwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			print_int(int nbr, t_info *info)
{
	char	*nbr_str;
	int		ret;

	nbr_str = ft_itoa_remake(nbr, info);
	ret = print_str(nbr_str, info);
	free(nbr_str);
	return (ret);
}

char		*convert_16(unsigned long long num, t_info *info)
{
	char					*ret;
	int						i;

	if (!(ret = (char *)malloc(14)))
		return (0);
	i = 0;
	if (num == 0)
		ret[i++] = '0';
	while (num > 0)
	{
		if (num % 16 >= 10)
		{
			ret[i++] = num % 16 + ((info->type == 'X') ? 55 : 87);
		}
		else
			ret[i++] = num % 16 + '0';
		num /= 16;
	}
	ret[i] = '\0';
	return (ret);
}

char		*reverse(char *str)
{
	int		i;
	char	temp;
	int		len;

	i = 0;
	len = (int)ft_strlen(str);
	while (i < (len / 2))
	{
		temp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = temp;
		i++;
	}
	return (str);
}

int			print_16(unsigned long long nbr, t_info *info)
{
	char		*str;
	int			ret;

	if (info->type == 'u')
		str = ft_uitoa_remake((unsigned int)nbr);
	else
	{
		str = convert_16((unsigned long long)nbr, info);
		str = reverse(str);
	}
	if (info->type == 'p')
		ret = print_str_p(str, info);
	else
		ret = print_str(str, info);
	free(str);
	return (ret);
}
