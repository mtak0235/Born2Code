/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwoo <jwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 18:26:22 by jwoo              #+#    #+#             */
/*   Updated: 2021/01/31 19:17:28 by jwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*print_nega(t_flag_list fl, char *str, char o)
{
	int		diff;
	char	*posi;
	char	*temp;

	posi = split_n(str, 0, 1);
	diff = (o == 'p') ? fl.pre - ft_strlen(posi) : fl.width - ft_strlen(str);
	while (diff-- > 0)
	{
		temp = posi;
		posi = ft_strjoin("0", temp);
		free_temp(&temp);
	}
	str = ft_strjoin("-", posi);
	free_temp(&posi);
	return (str);
}

char	*print_pre(t_flag_list fl, char *str, char type)
{
	int		diff;

	if (is_type(type, "di") == 1 && *str == '-')
		return (print_nega(fl, str, 'p'));
	if (is_type(type, "diuxX") == 1 && *str == '0' && fl.pre == 0)
		str = ft_strdup("");
	if (type == 'p' && fl.pre == 0 && str[2] == '0' && str[3] == 0)
		str = ft_strdup("0x");
	if (type == 's' && ft_strlen(str) - fl.pre > 0)
		str = split_n(str, fl.pre, 0);
	if (is_type(type, "diuxX") == 1)
		if ((diff = fl.pre - ft_strlen(str)) > 0)
			while (diff-- > 0)
				str = ft_strjoin("0", str);
	return (str);
}

char	*print_width(t_flag_list fl, char *str, char type)
{
	int		diff;
	char	*blank;

	fl.sort_0 = (fl.width < 0) ? -1 : fl.sort_0;
	fl.width = (fl.width < 0) ? -fl.width : fl.width;
	if (fl.pre >= 0 && type != '%')
		fl.sort_0 = (fl.sort_0 == 1) ? 0 : fl.sort_0;
	if (is_type(type, "di") == 1 && *str == '-' && fl.sort_0 == 1)
		return (print_nega(fl, str, 'w'));
	if ((diff = fl.width - ft_strlen(str)) > 0)
	{
		blank = (fl.sort_0 == 1) ? "0" : " ";
		if (fl.sort_0 == -1)
			while (diff-- > 0)
				str = ft_strjoin(str, " ");
		else
			while (diff-- > 0)
				str = ft_strjoin(blank, str);
	}
	return (str);
}
