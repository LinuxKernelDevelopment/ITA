#include "btree.h"
#include <stdio.h>

int main(void)
{
	int i;
	struct BTREE T;
	char num[] = {'F', 'S', 'Q', 'K', 'C', 'L', 'H', 'V', 'W', 'M', 'R', 'N', 'P', 'A', 'B', 'X', 'Y', 'D', 'Z', 'E'};
	//char test[] = {'G', 'M', 'P', 'X', 'A', 'C', 'D', 'E', 'J', 'K', 'N', 'O', 'R', 'S', 'T', 'U', 'V', 'Y', 'Z','B','Q', 'L', 'F', 'I'};
	b_tree_create(&T);
	for (i = 0; i < sizeof(num) / sizeof(char); i++) {
		b_tree_insert(&T, num[i]);
		printf("%c\n", num[i]);
	}
	pause();
	return 0;
}

