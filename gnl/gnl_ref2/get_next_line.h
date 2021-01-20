/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtak <mtak@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 12:47:51 by mtak              #+#    #+#             */
/*   Updated: 2021/01/19 12:48:07 by mtak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

int		get_next_line(int fd, char **line);

size_t	ft_strlen(char *str);
size_t	ft_strlcpy(char *dest, char *src, size_t destsize);
size_t	ft_strlcat(char *dest, char *src, size_t size);
char	*ft_strdup(char *s1);
char	*ft_strjoin(char *str1, char *str2);

#endif
