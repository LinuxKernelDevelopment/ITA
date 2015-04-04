#include <stdio.h>
#include <stdlib.h>

int extended_bottom_up_cut_rod(int*, int, int*, int*);
void print_cut_rod_solution(int *, int, int *, int*);

int
main(void)
{
	int p[] = { 0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
	int r[13], s[13];
	print_cut_rod_solution(p, 11, r, s);
	return 0;
}

#define max(a, b) (a > b ? a : b)

int extended_bottom_up_cut_rod(int *p, int n, int *r, int *s)
{
	int j, i, q;
	r[0] = 0;
	for (j = 1; j <= n; j++) {
		q = -32468;
		for (i = 1; i <= j; i++) {
			if (q < p[i] + r[j - i]) {
				q = p[i] + r[j - i];
				s[j] = i;
			}
		}
		r[j] = q;
	}
	return r[n];
}

void print_cut_rod_solution(int *p, int n, int *r, int *s)
{
	int i;
	extended_bottom_up_cut_rod(p, n, r, s);
	for (i = 0; i < 13; i++) {
		printf("%d\t%d\n", r[i], s[i]);
	}
	/*while (n > 0) {
		printf("%d\t", s[n]);
		n = n - s[n];
	}*/
}
