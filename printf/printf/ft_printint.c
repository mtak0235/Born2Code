#include "ft_printf.h"
#include "ft_utils.h"

static void             print_flag(t_flag *flag, char *num, size_t size)
{
        int     minus;

        size = num[0] == '-' ? size + 1 : size;
        flag->width = size > flag->width ? size : flag->width;
        if (flag->indent)
                ft_putchar_fd(' ', 1);
        if (flag->minus == 0)
                while (size < flag->width)
                {
                        ft_putchar_fd(' ', 1);
                        size++;
                }
        if (num[0] == '-')
                ft_putchar_fd('-', 1);
        minus = num[0] == '-' ? 1 : 0;
        while (flag->precision > 0 && flag->precision--)
                ft_putchar_fd('0', 1);
        ft_putstr_fd(num + minus, 1);
        if (flag->minus == 1)
                while (size < flag->width)
                {
                        size++;
                        ft_putchar_fd(' ', 1);
                }
        free(num);
}

int                             print_int(t_flag *flag, va_list ap)
{
        char    *num;
        size_t  pure_size;
        size_t  num_size;
		int len;

        num = int2str(va_arg(ap, int), &len);
        if (num == NULL)
                return (0);
        if (num[0] == '0' && flag->precision == 0)
                num[0] = '\0';
        num_size = ft_strlen(num);
        pure_size = num[0] == '-' ? num_size - 1 : num_size;
        if (flag->precision >= 0 && (size_t)flag->precision > pure_size)
        {
                flag->precision = flag->precision - (int)pure_size;
                pure_size = pure_size + flag->precision;
        }
        else if (flag->zero == 1 && flag->width > num_size)
        {
                flag->precision = (int)(flag->width - num_size);
                pure_size = pure_size + flag->precision;
        }
        else
                flag->precision = 0;
        print_flag(flag, num, pure_size);
        return ((int)flag->width + flag->indent);
}

int                             print_uint(t_flag *flag, va_list ap)
{
        char    *num;
        size_t  num_size;
		int len;

        num = int2str(va_arg(ap, unsigned int), &len);
        if (num == NULL)
                return (0);
        if (num[0] == '0' && flag->precision == 0)
                num[0] = '\0';
        num_size = ft_strlen(num);
        if (flag->precision >= 0 && (size_t)flag->precision > num_size)
        {
                flag->precision = flag->precision - (int)num_size;
                num_size = num_size + flag->precision;
        }
        else if (flag->zero == 1 && flag->width > num_size)
        {
                flag->precision = (int)(flag->width - num_size);
                num_size = num_size + flag->precision;
        }
        else
                flag->precision = 0;
        print_flag(flag, num, num_size);
        return ((int)flag->width + flag->indent);
}

