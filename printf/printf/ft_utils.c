#include "ft_utils.h"
#include "ft_printf.h"
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
	if (flag->precision >= 0 && flag->type != 9)
		flag->zero = 0;
	if (flag->minus)
		flag->zero = 0;
}

char *int2hex(unsigned long long num, int pin)
{
	char *str;
	char *hex;
	int len;

	hex = pin ? "0123456789ABCDEF" : "0123456789abcdef";
	len = int2hex_len(num);
	if (!(str = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	str[len] = 0;
	while (--len >= 0)
	{
		str[len] = hex[num % 16];
		num /= 16;
	}
	return (str);
}

char *ptr2hex(unsigned long long num)
{
	char *str;
	char *hex;
	int len;

	hex = "0123456789abcdef";
	len = int2hex_len(num) + 2;
	if (!(str = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	str[len] = 0;
	while (--len >= 2)
	{
		str[len] = hex[num % 16];
		num /= 16;
	}
	str[0] = '0';
	str[1] = 'x';
	return (str);

}
int int2hex_len(unsigned long long n)
{
	int len;

	len = 1;
	while (n > 15)
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
