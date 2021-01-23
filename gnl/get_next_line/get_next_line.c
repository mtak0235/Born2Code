/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtak <mtak@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 15:18:19 by mtak              #+#    #+#             */
/*   Updated: 2021/01/23 06:57:10 by mtak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	find_nl_idx(char *save)
{
	int	nl_idx;

	nl_idx = 0;
	while (save[nl_idx] != '\0')
	{
		if (save[nl_idx] == '\n')
			return (nl_idx);
		nl_idx++;
	}
	return (-1);
}

int	put_line(char **line, char *save, int nl_idx)
{
	int len_after_nl;

	len_after_nl = (int)ft_strlen(save + nl_idx + 1);
	*line = ft_substr(save, 0, nl_idx);
	ft_memmove(save, save + nl_idx + 1, len_after_nl + 1);
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char	*save;
	char		buff[BUFFER_SIZE + 1];
	int			nl_idx;
	int			read_bytes;

	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	if (save && (nl_idx = find_nl_idx(save)) >= 0)
		return (put_line(line, save, nl_idx));
	while ((read_bytes = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[read_bytes] = '\0';
		save = ft_strjoin_f(save, buff);
		if ((nl_idx = find_nl_idx(save)) >= 0)
			return (put_line(line, save, nl_idx));
	}
	if (save != NULL)
	{
		*line = ft_strdup(save);
		free(save);
		save = NULL;
		return (0);
	}
	*line = ft_strdup("");
	return (0);
}
