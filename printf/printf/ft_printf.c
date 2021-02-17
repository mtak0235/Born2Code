# include "ft_printf.h"
# include "ft_utils.h"

int ft_printf(const char *format, ...)
{
	va_list ap;
	int count;

	va_start(ap, format);
	if (format == NULL)
		return (-1);
	count = parse(format, ap);
	va_end(ap);
	return (count);
}

int parse(const char *format, va_list ap)
{
	int count;
	char *str;
	int base_i;
	int parsed_i;
	t_flag *flag;

	str = ft_strdup(format);
	if (!(flag = (t_flag *)malloc(sizeof(t_flag))))
		return (0);
	base_i = 0;
	count = 0;
	while(str[base_i])
	{
		if ((parsed_i = is_valid_format(flag, str + base_i, ap)) != -1)
		{
			fit_flag(flag);
			count += param_print(flag, ap);
			base_i += parsed_i;
    	}
		else
   		{
   			write(1,&str[base_i++],1);
   			count++;
		}
  }
	free(str);
	free(flag);
	return (count);
}

int is_valid_format(t_flag *flag, char *str, va_list ap )
{
	int i;

	i = 0;
	if (!(str[i] == '%' && str[i + 1]))
		return (-1);
	i = i + 1;
	init_flag(flag);
	while (check_flag(flag, str[i]))
		i++;
	if (str[i] != '0' && ft_isdigit(str[i]))
		while (check_width(str[i], ap, flag, 1) && i <8)
			i++;
	else if (str[i] == '*')
		i += check_width(str[i], ap, flag, 2);
	if (str[i] == '.' && str[i + 1] == '*')
	{
		i = i + 1;
		i += check_precision(str[i], ap, flag, 2);
	}
  	else if (str[i] == '.')
	{
		i ++;
		flag->precision = 0;
		while(check_precision(str[i], ap, flag, 1))
			i++;
	}
	if (!check_type(str[i], flag))
		return (i);
	if (str[i])
		return (i + 1);
	return (i);
}

int param_print(t_flag *flag, va_list ap)
{
	int count2print;

	count2print = 0;
	if (flag->type == 1)
		count2print = print_char(flag, ap);
	else if (flag->type == 2)
		count2print = print_string(flag, ap);
	else if (flag->type == 3)
		count2print = print_ptr(flag, ap);
	else if (flag->type == 4)
		count2print = print_int(flag, ap);
	else if (flag->type == 5)
		count2print = print_int(flag, ap);
	else if (flag->type == 6)
		count2print = print_uint(flag, ap);
	else if (flag->type == 7)
		count2print = print_hex(flag, ap, 0);
	else if (flag->type == 8)
		count2print = print_hex(flag, ap, 1);
	else if (flag->type == 9)
		count2print = print_percent(flag);
	return (count2print);
}
