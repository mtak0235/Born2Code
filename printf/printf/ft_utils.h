#ifndef FT_UTILS_H
# define FT_UTILS_H

#include <string.h>
#include <stdlib.h>

char	*ft_strdup(const char *str);
size_t	ft_strlen(const char *s);
int	ft_isdigit(int c);
int	ft_toupper(int c);
void	ft_putchar_fd(char c, int fd);
char		*ft_itoa(int a);
void	ft_putstr_fd(char *s, int fd);

#endif
