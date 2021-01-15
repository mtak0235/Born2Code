/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinchoi <jinchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 11:45:32 by jinchoi           #+#    #+#             */
/*   Updated: 2021/01/16 05:12:17 by jinchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		find_index_nl(char *backup)
{
	int		index;

	index = 0;
	while (backup[index] != '\0')
	{
		if (backup[index] == '\n')
			return (index);
		index++;
	}
	return (-1);
}

int		allocate_line(char **line, char *backup, int index_nl)
{
	int		len_after_nl;

	len_after_nl = (int)ft_strlen(backup + index_nl + 1);
	*line = ft_substr(backup, 0, index_nl);
	ft_memmove(backup, backup + index_nl + 1, len_after_nl + 1);
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static char		*backup[1023];
	char			buff[BUFFER_SIZE + 1];
	int				index_nl;
	int				bytes_read;

	if (fd < 0 || line == NULL || BUFFER_SIZE < 1 || read(fd, buff, 0) < 0)
		return (-1);
	if ((backup[fd] != NULL) && (index_nl = find_index_nl(backup[fd])) >= 0)
		return (allocate_line(line, backup[fd], index_nl));
	while ((bytes_read = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[bytes_read] = '\0';
		backup[fd] = ft_strjoin_free(backup[fd], buff);
		if ((index_nl = find_index_nl(backup[fd])) >= 0)
			return (allocate_line(line, backup[fd], index_nl));
	}
	if (backup[fd] != NULL)
	{
		*line = ft_strdup(backup[fd]);
		free(backup[fd]);
		backup[fd] = NULL;
		return (0);
	}
	*line = ft_strdup("");
	return (0);
}
