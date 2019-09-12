#include "../includes/n_puzzle.h"

int main(void)
{

	int input[27] = {5,
					 24, 4, 1, 11, 5,
					 3, 18, 9, 20, 19,
					 10, 15, 23, 12, 17,
					 13, 21, 22, -1, 6,
					 2, 16, 8, 14, 7, 0};

	a_star(input, 5, 0);

	return 0;
}
