#include <unistd.h>

void print(int *asc, char *str)
{
		char *c;

			while (*str)
					{
								if (asc[*str] == 1)
											{
															c = str;
																		asc[*str] = 0;
																					write(1, c, 1);
																							}
										str++;
											}
}

int unionn(int argc, char **argv)
{
		char *c;
			int asc[128];
				char *first = argv[1];
					char *second = argv[2];

						if (argc == 3)
								{
											while (*argv[2])
															asc[*argv[2]++] = 1;
													while (*argv[1])
																	asc[*argv[1]++] = 1;
															print(asc, first);
																	print(asc, second);
																		}
							write(1,"\n", 1);
}
