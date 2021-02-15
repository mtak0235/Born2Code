#include "ft_utils.h"
#include "ft_printf.h"
char	*ft_strdup(const char *str)
{
	char	*new_str;
	size_t	str_len;
	size_t	i;

	str_len = ft_strlen(str);
	new_str = (char *)malloc((str_len + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	i = 0;
	while (i < str_len)
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = 0;
	return (new_str);
}

size_t	ft_strlen(const char *s)
{
	size_t cnt;

	cnt = 0;
	while (*s++)
		cnt++;
	return (cnt);
}

int	ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}

int	ft_toupper(int c)
{
	if ('a' <= c && c <= 'z')
		return (c - 32);
	return (c);
}

void init_flag(t_flag *flag)
{
	flag->type = 0;
	flag->width = 0;
	flag->minus = 0;
	flag->zero = 0;
	flag->precision = -1;
	flag->star = 0;
	flag->indent = 0;
}

void	fit_flag(t_flag *flag)
{
	if (flag->width < 0)
	{
		flag->width *= -1;
		flag->minus = 1;
	}
	if (flag->precision >= 0)
		flag->zero = 0;
	if (flag->minus)
		flag->zero = 0;
}

char *int2hex(unsigned long long num, int *cnt)
{
	char *str;
	char *hex;
	int len;

	hex = "0123456789abcdef";
	len = int2hex_len(num);
	*cnt = len;
	if (!(str = (char *)malloc(sizeof(char) * len + 1)))
		return (0);
	str[len] = 0;
	while (--len >= 0)
	{
		str[len] = hex[num % 16];
		num /= 16;
	}
	return (str);
}

int int2hex_len(unsigned long long n)
{
	int len;

	len = 0;
	while (n)
	{
		n /= 16;
		len++;
	}
	return (len);
}


char *int2str(long long n, int *len)
{
	char *str;
	long long num;
	int len_backup;
	int sign;

	*len = 0;
	sign = 1;
	if (n < 0)
	{
		n *= -1;
		sign = -1;
		(*len)++;
	}
	num = n;
	while (n)
	{
		n /= 10;
		(*len)++;
	}
	if (!(str = (char *)malloc(sizeof(char) * *len + 1)))
		return (0);
	len_backup = *len;
	str[len_backup] = 0;
	while (--len_backup >= 0 && num)
	{
		str[len_backup] = '0' + num % 10;
		num /= 10;
	}
	str[0] = (sign == -1) ? '-' : str[0];
	return (str);
}
