/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtak <mtak@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 06:33:10 by mtak              #+#    #+#             */
/*   Updated: 2021/01/19 09:54:08 by mtak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
	char 	*line;
	int		fd;
	int		ret;

	fd = open("test.txt",O_RDONLY);
	while ((ret = get_next_line(fd,&line)) >= 0)
	{
		printf("%s\n",line);
		free(line);
	}
	printf("%s\n",line);
	close(fd);
	return (0);
}

