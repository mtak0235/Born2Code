#include "ft_printf.h"
#include "ft_utils.h"

static void             print_flag(t_flag *flag, char *num, int precision_size)
{
        if (flag->indent)
                ft_strdup(" ");
        if (flag->minus == 0)
                while (precision_size < flag->width)
                {
                        if (flag->zero == 1)
                                ft_putchar_fd('0', 1);
                        else
                                ft_putchar_fd(' ', 1);
                        precision_size++;
                }
        while (flag->precision--)
                ft_putchar_fd(*num++, 1);
        if (flag->minus == 1)
                while (precision_size < flag->width)
                {
                        ft_putchar_fd(' ', 1);
                        precision_size++;
                }
}

int                             print_string(t_flag *flag, va_list ap)
{
        char    *str;
        int  str_size;
        int             pin;

        pin = 0;
        str = va_arg(ap, char *);
        if (str == NULL)
        {
                pin = 1;
                str = ft_strdup("(null)");
                if (str == NULL)
                        return (0);
        }
        str_size = ft_strlen(str);
        if (flag->precision >= 0 && flag->precision > str_size)
                flag->precision = str_size;
        else if (flag->precision < 0)
                flag->precision = str_size;
        str_size = flag->precision;
        flag->width = str_size > flag->width ? str_size : flag->width;
        print_flag(flag, str, str_size);
        if (pin)
                free(str);
        return (flag->width);
}

int                             print_char(t_flag *flag, va_list ap)
{
        char    *str;

        if (flag->width < 1)
                flag->width = 1;
        str = (char *)malloc(sizeof(char) * 2);
        if (str == NULL)
                return (0);
        str[0] = (char)va_arg(ap, int);
        str[1] = '\0';
        flag->precision = 1;
        print_flag(flag, str, 1);
        free(str);
        return (flag->width + flag->indent);
}

int                             print_percent(t_flag *flag)
{
        char    *str;

        if (flag->width < 1)
                flag->width = 1;
        str = (char *)malloc(sizeof(char) * 2);
        if (str == NULL)
                return (0);
        str[0] = '%';
        str[1] = '\0';
        flag->precision = 1;
        print_flag(flag, str, 1);
        free(str);
        return (flag->width + flag->indent);
}
