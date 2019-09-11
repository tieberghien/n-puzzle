#include "../includes/n_puzzle.h"

int main(void)
{
	int current[10] = {4, 2, 5, 1, -1, 6, 3, 8, 7, 0};
	int *goal = ft_malloc_check(9 * sizeof(int) + sizeof(int));
	int i = 0;

	while(current[i]){
		goal[i] = current[i];
		i++;
	}
	goal[i] = 0;
	//printf("%i %i %i", linear_conflict_manhattan(current, goal, 3), manhatan(current, goal, 3), hamming(current, goal, 3));

	printf("%i", ft_memcmp(current, goal, 9 * sizeof(int) + sizeof(int)));

	return 0;
}
