#include <unistd.h>

int inter(int argc, char **argv) {
		int asc[128];
			char *c;

				if (argc == 3)
						{
									while (*argv[2])
													asc[(int)*argv[2]++] = 1;
											while (*argv[1])
														{
																		if (asc[(int)*argv[1]] == 1)
																						{
																											c = argv[1];
																															asc[*c] = 0;
																																			write(1, c, 1);
																																						}
																					argv[1]++;
																							}
												}
					write(1,"\n",1);
						return (0);
}
