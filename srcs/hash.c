/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etieberg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 14:42:39 by etieberg          #+#    #+#             */
/*   Updated: 2019/09/25 14:59:13 by etieberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_puzzle.h"

void	hash(int *puzzle, int n, int size, long long int *hash)
{
	int i;
	int	j;
	int k;
	int curr;
	int greater_nums;

	i = -1;
	while (++i < size)
	{
		*hash += 1;
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
				*hash += 1LL << (greater_nums + k);
				j--;
				k++;
			}
			curr = puzzle[i];
		}
	}
}
