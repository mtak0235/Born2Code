/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwpark <sehwpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 21:35:31 by sehwpark          #+#    #+#             */
/*   Updated: 2021/01/23 22:26:49 by sehwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*cut_by_dot_p(char *buf, t_info *info)
{
	char	*add;
	int		i;

	i = 0;
	if (ft_strchr("duipxX", info->type) && buf[i] == '0' && info->dot == 0)
		buf[i] = '\0';
	else if ((int)ft_strlen(buf) < info->dot && \
			(ft_strchr("udixXp", info->type)))
	{
		if (!(add = (char *)malloc(info->dot - ft_strlen(buf) + 1)))
			return (0);
		while ((size_t)i < info->dot - ft_strlen(buf))
			add[i++] = '0';
		add[i] = '\0';
		buf = ft_strjoin(add, buf);
		free(add);
	}
	return (buf);
}

char		*put_width_p(char *buf, t_info *info)
{
	char	*add;
	int		i;

	if (info->dot != -1)
		buf = cut_by_dot_p(buf, info);
	buf = ft_strjoin("0x", buf);
	if (info->width < (int)ft_strlen(buf))
		info->width = (int)ft_strlen(buf);
	if (!(add = (char *)malloc(info->width - ft_strlen(buf) + 1)))
		return (0);
	i = 0;
	while ((size_t)i < info->width - info->nbr_sign - ft_strlen(buf))
		add[i++] = (info->zero == 1 && \
				info->dot == -1 && info->minus == 0) ? '0' : ' ';
	add[i] = '\0';
	if (info->minus)
		buf = ft_strjoin(buf, add);
	else
		buf = ft_strjoin(add, buf);
	free(add);
	return (buf);
}

int			print_str_p(char *str, t_info *info)
{
	int		ret;
	char	*buf;

	ret = 0;
	buf = ft_strndup(str, ft_strlen(str));
	buf = put_width_p(buf, info);
	ret = ft_strlen(buf);
	ft_putstr_fd(buf, 1);
	free(buf);
	return (ret);
}
