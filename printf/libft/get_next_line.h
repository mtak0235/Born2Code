/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoh <seunghoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 18:36:07 by seunghoh          #+#    #+#             */
/*   Updated: 2021/01/13 22:06:03 by seunghoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 1024

typedef	unsigned int	t_uint;

typedef struct			s_buffer
{
	int					fd;
	char				buffer[BUFFER_SIZE];
	char				*backup;
	t_uint				backup_size;
	struct s_buffer		*next;
}						t_buffer;

int						get_next_line(int fd, char **line);
int						read_next_line(t_buffer *ptr, char **line);
int						get_backup_line(t_buffer *ptr, char **line);
t_buffer				*find_fd_buffer(int fd, t_buffer **header);
void					clear_fd_buffer(t_buffer **header);
void					del_fd_buffer(int fd, t_buffer **header);
int						backup_join(t_buffer *ptr, char *new_backup,
									t_uint new_size);
int						backup_realloc(t_buffer *ptr, t_uint start);
#endif
