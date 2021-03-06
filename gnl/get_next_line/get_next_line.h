/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtak <mtak@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 03:20:01 by mtak              #+#    #+#             */
/*   Updated: 2021/01/23 03:20:07 by mtak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

int			get_next_line(int fd, char **line);
void		*ft_memmove(void *dest, void *src, size_t num);
size_t		ft_strlen(const char *s1);
char		*ft_strdup(char *src);
char		*ft_strjoin_f(char *s1, char *s2);
char		*ft_substr(char *s, unsigned int start, size_t len);

#endif
