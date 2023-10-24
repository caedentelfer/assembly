#include <stdio.h>
#include <stdlib.h>
#include "strtoi.h"
#include "tut3.h"

/* --- function prototypes -------------------------------------------------- */

int max_c(int x, int y);

/* --- main routine --------------------------------------------------------- */

int main(int argc, char *argv[])
{
	int ma, mc, x, y;

	/* check command-line arguments */
	if (argc != 3)
		goto usage;

	/* convert command-line arguments */
	if (strtoi(argv[1], &x) != EXIT_SUCCESS)
		goto usage;
	if (strtoi(argv[2], &y) != EXIT_SUCCESS)
		goto usage;

	/* test */
	ma = max(x, y);
	mc = max_c(x, y);

	printf("max(%d, %d) returned %d -- ", x, y, ma);
	if (ma == mc)
		printf("\033[32mcorrect\033[m\n");
	else
		printf("\033[31mincorrect\033[m -- should return %d\n", mc);

	return EXIT_SUCCESS;

usage:
	fprintf(stderr, "usage: %s <int> <int>\n", argv[0]);
	return EXIT_FAILURE;
}

/* --- library -------------------------------------------------------------- */

int max_c(int x, int y)
{
	if (x > y)
		return x;
	else
		return y;
}
