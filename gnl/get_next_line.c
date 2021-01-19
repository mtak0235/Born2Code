/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinchoi <jinchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 11:45:32 by jinchoi           #+#    #+#             */
/*   Updated: 2021/01/16 04:55:44 by jinchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		find_index_of_newline(char *backup)
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
	static char		*backup;
	char			buff[BUFFER_SIZE + 1];
	int				index_nl;
	int				bytes_read;

	if (fd < 0 || line == NULL || BUFFER_SIZE < 1 || read(fd, buff, 0) < 0)
		return (-1);
	if ((backup != NULL) && (index_nl = find_index_of_newline(backup)) >= 0)
		return (allocate_line(line, backup, index_nl));
	while ((bytes_read = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[bytes_read] = '\0';
		backup = ft_strjoin_free(backup, buff);
		if ((index_nl = find_index_of_newline(backup)) >= 0)
			return (allocate_line(line, backup, index_nl));
	}
	if (backup != NULL)
	{
		*line = ft_strdup(backup);
		free(backup);
		backup = NULL;
		return (0);
	}
	*line = ft_substr("", 0, 1);
	return (0);
}
