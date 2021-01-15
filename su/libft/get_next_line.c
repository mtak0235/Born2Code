/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoh <seunghoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 18:35:58 by seunghoh          #+#    #+#             */
/*   Updated: 2021/01/13 22:03:11 by seunghoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>

static char	*ft_strdup(char *origin, t_uint size)
{
	char	*new;
	t_uint	idx;

	idx = 0;
	new = (char *)malloc(sizeof(char) * (size + 1));
	if (new == NULL)
		return (NULL);
	while (idx < size)
	{
		new[idx] = origin[idx];
		idx++;
	}
	new[idx] = '\0';
	return (new);
}

int			get_next_line(int fd, char **line)
{
	static t_buffer	*buffer_head = NULL;
	t_buffer		*ptr;
	int				flag;

	if (BUFFER_SIZE < 1)
		return (-1);
	ptr = find_fd_buffer(fd, &buffer_head);
	if (ptr == NULL)
	{
		clear_fd_buffer(&buffer_head);
		return (-1);
	}
	*line = NULL;
	flag = read_next_line(ptr, line);
	if (flag == 0)
	{
		del_fd_buffer(fd, &buffer_head);
	}
	else if (flag == -1)
	{
		clear_fd_buffer(&buffer_head);
		free(*line);
	}
	return (flag);
}

int			read_next_line(t_buffer *ptr, char **line)
{
	int	read_char;
	int	flag;

	read_char = 0;
	flag = get_backup_line(ptr, line);
	if (flag == -1 || flag == 1)
		return (flag);
	while ((read_char = read(ptr->fd, ptr->buffer, BUFFER_SIZE)) > 0)
	{
		if (backup_join(ptr, ptr->buffer, read_char))
			return (-1);
		flag = get_backup_line(ptr, line);
		if (flag == -1 || flag == 1)
			return (flag);
	}
	if (read_char == -1)
		return (-1);
	*line = ft_strdup(ptr->backup, ptr->backup_size);
	if (*line == NULL)
		return (-1);
	return (0);
}

int			get_backup_line(t_buffer *ptr, char **line)
{
	t_uint	idx;

	if (ptr->backup_size == 0)
		return (0);
	idx = 0;
	while (idx < ptr->backup_size)
	{
		if (ptr->backup[idx] == '\n')
			break ;
		idx++;
	}
	if (idx == ptr->backup_size)
		return (0);
	*line = ft_strdup(ptr->backup, idx);
	if (*line == NULL)
		return (-1);
	if (backup_realloc(ptr, idx))
		return (-1);
	return (1);
}
