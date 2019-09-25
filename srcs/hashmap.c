/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerli <tmerli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 12:51:43 by tmerli            #+#    #+#             */
/*   Updated: 2019/09/25 14:59:19 by tmerli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_puzzle.h"

int hash1(int *puzzle)
{
	int key;
	int i;

	key = 0;
	while (puzzle[i])
	{
		if (puzzle[i] != -1)
		{
			key |= puzzle[i] << (i * 4);
		}
	}
	return (key % MAP_SIZE);
}

void add_to_map(int *puzzle, t_set *set)
{
	int key1;
	int key2;

	key1 = hash1(puzzle);
	key2 = hash2(puzzle);

	set->hashmap1[key1/8] |= 1 << key1 % 8;
	set->hashmap2[key2/8] |= 1 << key2 % 8;

	set->map_space--;
}
