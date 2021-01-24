/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwpark <sehwpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 22:45:47 by sehwpark          #+#    #+#             */
/*   Updated: 2021/01/23 23:18:17 by sehwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			print_char(char c, t_info *info)
{
	int		ret;

	ret = 0;
	ret += info->width ? info->width : 1;
	if (info->minus == 1)
		write(1, &c, 1);
	if (info->width == 0)
		info->width = 1;
	if (info->zero && !(info->minus))
	{
		while (--info->width)
			write(1, "0", 1);
	}
	else
	{
		while (--info->width)
			write(1, " ", 1);
	}
	if (info->minus == 0)
		write(1, &c, 1);
	return (ret);
}
