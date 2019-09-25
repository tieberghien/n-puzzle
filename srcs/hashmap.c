/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerli <tmerli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 12:51:43 by tmerli            #+#    #+#             */
/*   Updated: 2019/09/25 15:23:19 by tmerli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_puzzle.h"

int hash1(int *puzzle)
{
	int key;
	int i;

i = 0;
	key = 0;
	while (puzzle[i])
	{
		if (puzzle[i] != -1)
		{
			key |= puzzle[i] << (i * 4);
		}
		i++;
	}
	return (key % MAP_SIZE * 8);
}

int	hash2(int *puzzle,  int size)
{
	int i;
	int	j;
	int k;
	int n = size * size;
	int curr;
	int greater_nums;
	long long hash = 0;

	i = -1;
	while (++i < size)
	{
		hash += 1;
		if (puzzle[i] == curr + 1)
		{
			curr = puzzle[i];
			continue ;
		}
		else
		{
			greater_nums = n - puzzle[i];
			j = puzzle[i] - 1;
			k = 1;
			while (j > curr)
			{
				hash += 1LL << (greater_nums + k);
				j--;
				k++;
			}
			curr = puzzle[i];
		}
	}
	return ((int)hash % MAP_SIZE * 8);
}


void add_to_map(int *puzzle, t_set *set)
{
	int key1;
	int key2;

	key1 = hash1(puzzle);
	key2 = hash2(puzzle, set->size);

	set->hashmap1[key1/8] |= 1 << key1 % 8;
	set->hashmap2[key2/8] |= 1 << key2 % 8;

	set->map_space--;
}
