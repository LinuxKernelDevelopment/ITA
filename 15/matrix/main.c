#include <stdio.h>
#include <stdlib.h>

int
main(void)
{
	unsigned int *m;
	int *s;
	int p[] = {30, 35, 15, 5, 10, 20, 25};
	m = malloc(sizeof(unsigned int) * 6 * 6);
	s = malloc(sizeof(int) * 6 * 6);
	matrix_chain_order(p, sizeof(p), m, s);
	print_optimal_parens(s, 1, 6);
	return 0;
}
