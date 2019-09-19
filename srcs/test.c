#include "../includes/n_puzzle.h"

int main(int ac, char **av)
{

	int input[ac + 1];
	int size = atoi(av[ac - 1]);
	int big_size = size * size;

	int i = 0;
	while (i < big_size)
	{
		input[i] = atoi(av[i + 1]);
		i++;
	}
	input[i] = 0;
	print_puzzle(input, size);
	a_star(input, size, 0);

	return 0;
}
