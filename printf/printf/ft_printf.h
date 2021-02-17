#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
int ft_printf(const char *format, ...);
int parse(const char *format, va_list ap);

typedef struct s_flag
{
  unsigned int type;
  int width;
  int minus;
  int zero;
  int indent;
  int precision;
  int star;
}             t_flag;

void init_flag(t_flag *flag);
int is_valid_format(t_flag *flag, char* str,va_list ap );
int param_print(t_flag *flag, va_list ap);
int check_flag(t_flag *flag, char c);
int check_width(int c, va_list ap, t_flag *flag, int pin);
int check_precision(int c, va_list ap, t_flag *flag, int pin);
int check_type(char c, t_flag *flag);
void	fit_flag(t_flag *flag);

int print_char(t_flag *flag, va_list ap);
int print_string(t_flag *flag, va_list ap);
int print_ptr(t_flag *flag, va_list ap);
int print_int(t_flag *flag, va_list ap);
int print_uint(t_flag *flag, va_list ap);
int print_hex(t_flag *flag, va_list ap, int pin);
int print_percent(t_flag *flag);
char *int2hex(unsigned long long num, int pin);
int int2hex_len(unsigned long long n);
char *int2str(long long n, int *len);
char *ptr2hex(unsigned long long num);

#endif
