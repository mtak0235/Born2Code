#include "ft_printf.h"
#include "ft_utils.h"
#include <stdio.h>
int main()
{
	ft_printf("==================\n");
	printf("-->|%*.c|<--\n",-4, 'y');
	ft_printf("-->|%*.c|<--\n",-4, 'y');
	printf("-->|%*.c|<--\n",-3,'y');
	ft_printf("-->|%*.c|<--\n",-3,'y');
	ft_printf("==================1\n");
	char *s = "abc";
	printf("-->|%-16.s|<--\n", s);
	printf("-->|%-16.*s|<--\n", -4, s);
	printf("-->|%-16.*s|<--\n", -3, s);
	printf("-->|%-16.*s|<--\n", -2, s);
	printf("-->|%-16.*s|<--\n", -1, s);
	printf("returns failed");
	ft_printf("==================2\n");
	char *p = s;
	printf("-->|%-16.p|<--\n", p);
	printf("-->|%-16p|<--\n", p);
	printf("-->|%-15.p|<--\n", p);
	printf("-->|%-15p|<--\n", p);
	printf("-->|%-14.p|<--\n", p);
	printf("-->|%-15p|<--\n", p);
	printf("-->|%-16.p|<--\n", p);
	printf("-->|%-16p|<--\n", p);
	printf("returns failed");
	ft_printf("==================3\n");
	int d = -135;
	printf("-->|%-4.*d|<--\n", -4, d);
	printf("-->|%-4.*d|<--\n", -3, d);
	printf("-->|%-4.*d|<--\n", -2, d);
	printf("-->|%-4.*d|<--\n", -1, d);
	d = 198;
	printf("-->|%-4d|<--\n", d);
	printf("returns failed");
	ft_printf("==================4\n");
	unsigned int u = 4294967161;
	printf("-->|%-4.*u|<--\n", -4, u);
	printf("-->|%-4.*u|<--\n", -3, u);
	printf("-->|%-4.*u|<--\n", -2, u);
	printf("-->|%-4.*u|<--\n", -1, u);
	u = 198;
	printf("-->|%-4u|<--\n", u);
	printf("returns failed");
	ft_printf("==================5\n");
	int x = 0xffffff79;
	printf("-->|%-4.*x|<--\n", -4, x);
	printf("-->|%-4.*x|<--\n", -3, x);
	printf("-->|%-4.*x|<--\n", -2, x);
	printf("-->|%-4.*x|<--\n", -1, x);
	x = 0xc6;
	printf("-->|%-4x|<--\n", x);
	ft_printf("==================6\n");
	printf("-->|%-4.%|<--\n");
	ft_printf("-->|%-4.%|<--\n");
	printf("-->|%-4.*%|<--\n", -4);
	ft_printf("-->|%-4.*%|<--\n", -4);
	printf("-->|%-4.*%|<--\n", -3);
	ft_printf("-->|%-4.*%|<--\n", -3);
	printf("-->|%-4.*%|<--\n", -2);
	ft_printf("-->|%-4.*%|<--\n", -2);
	printf("-->|%-4.*%|<--\n", -1);
	ft_printf("-->|%-4.*%|<--\n", -1);
}
