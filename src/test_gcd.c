#include <stdio.h>
#include <stdlib.h>
#include "strtoi.h"
#include "tut3.h"

/* --- function prototypes -------------------------------------------------- */

int gcd_c(int a, int b);

/* --- main routine --------------------------------------------------------- */

int main(int argc, char *argv[])
{
	int a, b, rslt_asm, rslt_c;

	/* check command-line arguments */
	if (argc != 3)
		goto usage;

	/* convert command-line arguments */
	if (strtoi(argv[1], &a) != EXIT_SUCCESS)
		goto usage;
	if (strtoi(argv[2], &b) != EXIT_SUCCESS)
		goto usage;

	/* test */
	rslt_asm = gcd(a, b);
	rslt_c = gcd_c(a, b);

	printf("gcd(%d, %d) returned %d -- ", a, b, rslt_asm);
	if (rslt_asm == rslt_c)
		printf("\033[32mcorrect\033[m\n");
	else
		printf("\033[31mincorrect\033[m -- should return %d\n", rslt_c);

	return EXIT_SUCCESS;

usage:
	fprintf(stderr, "usage: %s <int> <int>\n", argv[0]);
	return EXIT_FAILURE;
}

/* --- library -------------------------------------------------------------- */

int gcd_c(int a, int b)
{
	int r;

	/* Euclid's algorithm */
	do {
		r = a % b;
		if (r != 0) {
			a = b;
			b = r;
		}
	} while (r != 0);

	return b;
}
