/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwpark <sehwpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 15:41:17 by sehwpark          #+#    #+#             */
/*   Updated: 2021/01/23 22:19:17 by sehwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"

typedef struct	s_info
{
	int			minus;
	int			zero;
	int			width;
	int			dot;
	char		type;
	int			nbr_sign;
}				t_info;

int				ft_printf(const char *format, ...);
char			*ft_itoa_remake(int n, t_info *info);
char			*ft_uitoa_remake(unsigned int n);
void			init_info(t_info *info);
void			check_info(va_list ap, char *format, t_info *info, int i);
char			*ft_strndup(char *str, int len);
int				print_char(char c, t_info *info);
int				print_str_p(char *str, t_info *info);
int				print_str(char *str, t_info *info);
int				print_int(int nbr, t_info *info);
int				print_16(unsigned long long nbr, t_info *info);

#endif
