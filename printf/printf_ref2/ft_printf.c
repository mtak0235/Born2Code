/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoh <seunghoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 02:50:25 by seunghoh          #+#    #+#             */
/*   Updated: 2021/01/14 21:44:09 by seunghoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "parse.h"
#include <stdarg.h>

int			ft_printf(const char *format, ...)
{
	int		count;
	va_list	ap;

	if (format == NULL)
		return (0);
	va_start(ap, format);
	count = parse(format, ap);
	va_end(ap);
	return (count);
}
