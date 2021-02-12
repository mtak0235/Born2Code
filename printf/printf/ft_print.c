#include "ft_printf.h"
#include "ft_utils.h"

int print_char(t_flag *flag, va_list ap)
{
	int cnt;
	char c;

	cnt = 1;
	c = (char)va_arg(ap, int);
	if (flag->width < 1)
		flag->width = 1;
	if (flag->minus == 1)
		write(1, &c, 1);
	while (--(flag->width))
	{
		write(1, " ",1);
		cnt++;
	}
	if (flag->minus == 0)
		write(1, &c, 1);
	return (cnt);
}

int print_string(t_flag *flag, va_list ap)
{
	int		cnt;
	char	*str;
	int len;
	int i;
	
	if(!(str = va_arg(ap, char *)))
	{
		write(1, "(null)", 6);
		return (0);
	}
	if (flag->precision == 0)
		return (0);
	len = ft_strlen(str);
	i = len < flag->precision || flag->precision == -1? len : flag->precision;
	cnt = flag->width < i ? i : flag->width;
	if (flag->minus)
	{
		while (i--)
			write(1, str++, 1);
		i = len < flag->precision || flag->precision == -1? len : flag->precision;
	}
	while (flag->width-- - i > 0)
		write(1," ",1);
	if (!flag->minus)
		while (i--)
			write(1, str++, 1);
	return (cnt);
}

int print_ptr(t_flag *flag, va_list ap)
{
	int cnt;
	int i;
	char *str;

	cnt = 2;
	str = int2hex(va_arg(ap, unsigned long long), &cnt);
	if (flag->minus)
	{
		write(1, "0x", 2);
		while (*str)
			write(1, str++, 1);
	}
	i = 0;
	while (i++ <= flag->width - cnt)
	{
		write(1, " ", 1);
		cnt++;
	}
	i = 0;
	if (!flag->minus)
	{
		write(1, "0x", 2);
		while (str[i])
			write(1, &str[i++], 1);
	}
	free(str);
	return (cnt);
}

int print_int(t_flag *flag, va_list ap)
{
	int cnt;
	int i;
	int len;
	char *str;
	int sign;

	i = 0;
	str = int2str(va_arg(ap, int), &len);
	sign = (str[i] == '-') ? 1 : 0;
	cnt = 0;
	if (flag->width > len && flag->width > flag->precision && !flag->zero)
		while (i++ < (cnt = flag->width - ((len <= flag->precision) ? flag->precision : len)))
			write(1, " ",1);
	i = 0;
	write(1, &str[i], sign);
	cnt += sign;
	if (len <= (flag->zero ? flag->width : flag->precision))
		while (i++ < (cnt = (flag->zero ? flag->width : flag->precision) - len) + sign)
			write(1, "0", 1);
	i = 0;
	while (str[i + sign])
	{
		write(1, &str[sign + i++], 1);
		cnt++;
	}
	free(str);
	return (cnt);
}

int print_uint(t_flag *flag, va_list ap)
{
	int cnt;
	int i;
	int len;
	char *str;

	i = 0;
	str = int2str(va_arg(ap, unsigned int), &len);
	cnt = 0;
	if (flag->width > len && flag->width > flag->precision && !flag->zero)
		while (i++ < (cnt = flag->width - ((len <= flag->precision) ? flag->precision : len)))
			write(1, " ",1);
	i = 0;
	if (len <= (flag->zero ? flag->width : flag->precision))
		while (i++ < (cnt = (flag->zero ? flag->width : flag->precision) - len))
			write(1, "0", 1);
	i = 0;
	while (str[i])
	{
		write(1, &str[i++], 1);
		cnt++;
	}
	free(str);
	return (cnt);
}

int print_hex(t_flag *flag, va_list ap, int pin)
{
	int cnt;
	char *str;
	int i;
	int len;

	str = int2hex(va_arg(ap, unsigned int), &len);
	i = 0;
	cnt = 0;
	if (flag->width > len && flag->width > flag->precision && !flag->zero)
		while (i++ < (cnt = flag->width - ((len <= flag->precision) ? flag->precision : len)))
			write(1, " ",1);
	i = 0;
	if (len <= (flag->zero ? flag->width : flag->precision))
		while (i++ < (cnt = (flag->zero ? flag->width : flag->precision) - len))
			write(1, "0", 1);
	i = 0;
	while (str[i])
	{	
		str[i] = (pin == 1 && 'a' <= str[i] && str[i] <= 'z') ? str[i] - 32 : str[i];
		write(1, &str[i++], 1);
		cnt++;
	}
	free(str);
	return (cnt);
}

int print_percent(t_flag *flag)
{
	init_flag(flag);
	write(1, "%", 1);
	return (1);
}
