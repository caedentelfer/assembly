#include <stdio.h>
#include <stdlib.h>
#include "strtoi.h"
#include "tut3.h"

/* --- function prototypes -------------------------------------------------- */

int power_c(int x, int n);

/* --- main routine --------------------------------------------------------- */

int main(int argc, char *argv[])
{
	int x, n, rslt_asm, rslt_c;

	/* check command-line arguments */
	if (argc != 3)
		goto usage;

	/* convert command-line arguments */
	if (strtoi(argv[1], &x) != EXIT_SUCCESS)
		goto usage;
	if (strtoi(argv[2], &n) != EXIT_SUCCESS)
		goto usage;

	/* test */
	rslt_asm = power(x, n);
	rslt_c = power_c(x, n);

	printf("power(%d, %d) returned %d -- ", x, n, rslt_asm);
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

int power_c(int x, int n)
{
	int z;

	/* Note that we implement exponentiation by squaring, which is more
	 * efficient than the naive approach.  Instead of O(n) multiplications, we
	 * expect O(log n) multiplications.  This particular version is written to
	 * so that bit operations can be used instead of arithmetic instructions in
	 * some places, which is not done here explicitly, but MUST be used in
	 * assembly language.
	 */
	z = 1;
	while (n > 0)
		if ((n % 2) == 1) {
			n = n - 1;
			z = z * x;
		} else {
			n = n / 2;
			x = x * x;
		}

	return z;
}
