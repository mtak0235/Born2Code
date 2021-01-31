/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwoo <jwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 17:35:34 by jwoo              #+#    #+#             */
/*   Updated: 2021/01/31 19:16:40 by jwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libftprintf/libft.h"
# include <stdarg.h>

typedef	struct	s_format_flag
{
	int	sort_0;
	int	wild_width;
	int	width;
	int	wild_pre;
	int	pre;
}				t_flag_list;

char			*print_nega(t_flag_list fl, char *str, char o);
char			*print_pre(t_flag_list fl, char *str, char type);
char			*print_width(t_flag_list fl, char *str, char type);
int				is_type(char c, char *type);
char			**free_args(char **split, int x);
char			*free_temp(char **temp);
char			*find_type(const char *str);
char			**find_flag(const char *str, int args);
char			*ch_to_str(char c);
char			*str_char(char *s1, char s2);
char			*ft_hextoa(unsigned long long hex, char type);
char			*split_n(char *s, int point, int x);
char			*ft_utoa(unsigned int n);
t_flag_list		ft_sort_0(t_flag_list flag, char **format, char type);
t_flag_list		ft_width(t_flag_list flag, char **format);
t_flag_list		ft_pre(t_flag_list flag, char **format, char type);
t_flag_list		ft_flag(char *format, char type);
int				print_char(va_list ap, t_flag_list fl);
char			*str_null(char *str);
char			*print_type(va_list ap, t_flag_list fl, char type);
int				ret_printf(va_list ap, const char *format, char **flag,
				char *type);
int				ft_printf(const char *format, ...);

#endif
