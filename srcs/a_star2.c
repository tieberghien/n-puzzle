/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_star2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerli <tmerli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 16:38:08 by tmerli            #+#    #+#             */
/*   Updated: 2019/09/25 18:05:06 by tmerli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_puzzle.h"

/*
** Check if a configurtion of the n Puzzle is present in the closed hashmap
*/

int		in_closed(int *puzzle, t_set *set)
{
	int key1;
	int key2;

	key1 = hash1(puzzle);
	key2 = hash2(puzzle);
	if ((set->hashmap1[key1 / 8] >> key1 % 8) & 1 &&
		((set->hashmap2[key2 / 8] >> key2 % 8) & 1))
		return (1);
	return (0);
}

/*
** increment or decrement the coordinates in the right direction
** in order to reproduce a snail
*/

void	increment_coord(int *coord, int *direction, int size, int *goal)
{
	if (*direction % 2 == 0)
	{
		coord[1] = *direction == 0 ? coord[1] + 1 : coord[1] - 1;
		if (coord[1] == size || coord[1] < 0
			|| goal[coord[0] + coord[1] * size])
		{
			coord[1] = *direction == 0 ? coord[1] - 1 : coord[1] + 1;
			*direction = (*direction + 1) % 4;
			increment_coord(coord, direction, size, goal);
		}
	}
	else
	{
		coord[0] = *direction == 3 ? coord[0] + 1 : coord[0] - 1;
		if (coord[0] == size || coord[0] < 0
			|| goal[coord[0] + coord[1] * size])
		{
			coord[0] = *direction == 3 ? coord[0] - 1 : coord[0] + 1;
			*direction = (*direction + 1) % 4;
			increment_coord(coord, direction, size, goal);
		}
	}
}

/*
** Get the goal  of an  N puzzle (snail solution)
*/

int		*get_goal(int size)
{
	int *goal;
	int coord[2];
	int direction;
	int i;
	int nb_tile;

	nb_tile = size * size;
	goal = ft_memalloc(nb_tile * sizeof(int) + sizeof(int));
	coord[0] = 0;
	coord[1] = 0;
	i = 1;
	direction = 3;
	while (i <= nb_tile)
	{
		goal[coord[0] + coord[1] * size] = i == nb_tile ? -1 : i;
		if (i != nb_tile)
			increment_coord(coord, &direction, size, goal);
		i++;
	}
	return (goal);
}
