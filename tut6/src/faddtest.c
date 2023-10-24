#include <stdio.h>
#include <stdlib.h>
#include "fadd.h"

void add_c(float a, float b, float *x)
{
	*x = a + b;
}

void evaluate_add(float a, float b)
{
	float x;
	float y;
	
	add_c(a, b, &x);
	addf(a, b, &y);

	printf("add(%f, %f) returned %.8f", a, b, y);
	if (x == y)
		printf(" -- \033[32mcorrect!\033[m\n");
	else
		printf(" -- \033[31mincorrect\033[m -- should return %.8f\n", x);
}

int main()
{
	printf("***** Results for add *****\n");
	evaluate_add(0, 0);
	evaluate_add(1.0, 0);
	evaluate_add(-1.0, 1.0);
	evaluate_add(-1.0, -1.0);
	evaluate_add(3.7, 4.1);
	evaluate_add(1.5, 1.25);
	evaluate_add(10.6, 10.6);
	evaluate_add(5.321321, 54354);
	evaluate_add(13.0, -13.0);
	evaluate_add(913000.0, -3.1415927);
	return EXIT_SUCCESS;
}
