/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoh <seunghoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 23:40:37 by seunghoh          #+#    #+#             */
/*   Updated: 2021/01/02 01:30:01 by seunghoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

t_buffer	*find_fd_buffer(int fd, t_buffer **header)
{
	t_buffer	*ptr;

	ptr = *header;
	while (ptr != NULL)
	{
		if (ptr->fd == fd)
			break ;
		ptr = ptr->next;
	}
	if (ptr != NULL)
		return (ptr);
	ptr = (t_buffer *)malloc(sizeof(t_buffer));
	if (ptr == NULL)
		return (NULL);
	ptr->fd = fd;
	ptr->backup = NULL;
	ptr->backup_size = 0;
	ptr->next = *header;
	*header = ptr;
	return (ptr);
}

void		clear_fd_buffer(t_buffer **header)
{
	t_buffer	*ptr;
	t_buffer	*temp;

	ptr = *header;
	while (ptr != NULL)
	{
		temp = ptr->next;
		free(ptr->backup);
		free(ptr);
		ptr = temp;
	}
	*header = NULL;
}

void		del_fd_buffer(int fd, t_buffer **header)
{
	t_buffer	*ptr;
	t_buffer	*before;

	ptr = *header;
	before = *header;
	if (ptr->fd == fd)
	{
		*header = ptr->next;
		free(ptr->backup);
		free(ptr);
		return ;
	}
	while (ptr != NULL)
	{
		if (ptr->fd == fd)
		{
			before->next = ptr->next;
			free(ptr->backup);
			free(ptr);
			break ;
		}
		before = ptr;
		ptr = ptr->next;
	}
}

int			backup_realloc(t_buffer *ptr, t_uint start)
{
	char	*backup;
	t_uint	size;
	t_uint	idx;

	size = ptr->backup_size - start - 1;
	backup = NULL;
	if (size != 0)
	{
		backup = (char *)malloc(sizeof(char) * size);
		if (backup == NULL)
			return (1);
	}
	idx = 0;
	while (++start < ptr->backup_size)
	{
		backup[idx] = ptr->backup[start];
		idx++;
	}
	free(ptr->backup);
	ptr->backup = backup;
	ptr->backup_size = size;
	return (0);
}

int			backup_join(t_buffer *ptr, char *new_backup, t_uint new_size)
{
	char	*backup;
	t_uint	size;
	t_uint	idx;
	t_uint	jdx;

	size = ptr->backup_size + new_size;
	backup = (char *)malloc(sizeof(char) * size);
	if (backup == NULL)
		return (1);
	idx = 0;
	while (idx < ptr->backup_size)
	{
		backup[idx] = ptr->backup[idx];
		idx++;
	}
	jdx = 0;
	while (jdx < new_size)
		backup[idx++] = new_backup[jdx++];
	free(ptr->backup);
	ptr->backup = backup;
	ptr->backup_size = size;
	return (0);
}
