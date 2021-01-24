/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwpark <sehwpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 17:45:52 by sehwpark          #+#    #+#             */
/*   Updated: 2021/01/23 23:19:47 by sehwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*cut_by_dot(char *buf, t_info *info)
{
	char	*add;
	int		i;

	i = 0;
	if (ft_strchr("duipxX", info->type) && buf[i] == '0')
		buf[i] = '\0';
	if ((int)ft_strlen(buf) > info->dot && info->type == 's')
		buf = ft_strndup(buf, info->dot);
	else if ((int)ft_strlen(buf) < info->dot \
			&& (ft_strchr("udixXp", info->type)))
	{
		if (!(add = (char *)malloc(info->dot - ft_strlen(buf) + 1)))
			return (0);
		while ((size_t)i < info->dot - ft_strlen(buf))
			add[i++] = '0';
		add[i] = '\0';
		buf = ft_strjoin(add, buf);
		if (info->nbr_sign == 1)
		{
			info->nbr_sign = 0;
			buf = ft_strjoin("-", buf);
		}
		free(add);
	}
	return (buf);
}

char		*put_width3(char *buf, t_info *info, char *add)
{
	if (info->nbr_sign == 1 \
			&& ((info->minus == 0 && info->zero == 0) || info->dot > -1))
		buf = ft_strjoin("-", buf);
	if (info->minus == 0)
		buf = ft_strjoin(add, buf);
	if (info->nbr_sign == 1\
			&& (info->minus == 1 || info->zero == 1) && info->dot == -1)
		buf = ft_strjoin("-", buf);
	if (info->minus == 1)
		buf = ft_strjoin(buf, add);
	return (buf);
}

char		*put_width2(char *buf, t_info *info)
{
	if (info->dot != -1)
		buf = cut_by_dot(buf, info);
	if (info->width < (int)ft_strlen(buf))
		info->width = (int)ft_strlen(buf);
	return (buf);
}

char		*put_width(char *buf, t_info *info)
{
	char	*add;
	int		i;

	if (info->width <= (int)ft_strlen(buf))
	{
		if (info->nbr_sign == 1)
			buf = ft_strjoin("-", buf);
		return (buf);
	}
	if (!(add = (char *)malloc(info->width - \
					info->nbr_sign - ft_strlen(buf) + 1)))
		return (0);
	i = 0;
	while ((size_t)i < info->width - info->nbr_sign - ft_strlen(buf))
		add[i++] = (info->zero == 1 \
				&& info->dot == -1 && info->minus == 0) ? '0' : ' ';
	add[i] = '\0';
	buf = put_width3(buf, info, add);
	free(add);
	return (buf);
}

int			print_str(char *buf, t_info *info)
{
	int		ret;

	ret = 0;
	if (buf == NULL)
		buf = ft_strdup("(null)");
	buf = put_width2(buf, info);
	buf = put_width(buf, info);
	if (info->type == 'p')
		buf = ft_strjoin("0x", buf);
	ret = ft_strlen(buf);
	ft_putstr_fd(buf, 1);
	return (ret);
}
