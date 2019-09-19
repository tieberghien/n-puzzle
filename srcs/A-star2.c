/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A-star2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerli <tmerli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 16:38:08 by tmerli            #+#    #+#             */
/*   Updated: 2019/09/17 16:30:54 by tmerli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/n_puzzle.h"

/*
** Check if a configurtion of the n Puzzle is present in the closed list
*/

int in_queue(int *puzzle, t_node *queue, int size)
{
	t_node *cursor;

	cursor = queue;
	while (cursor)
	{
		if (!ft_memcmp(puzzle, cursor->puzzle, size * size * sizeof(int) + sizeof(int)))
			return (1);
		cursor = cursor->next;
	}
	return (0);
}

int find_next(t_node **next, t_node **before_next, t_set *set)
{
	t_node *cursor;
	t_node *last;

	last = NULL;
	cursor = set->open;

	while (cursor)
	{
		if (!ft_memcmp(set->goal, cursor->puzzle, set->size * set->size * sizeof(int) + sizeof(int)))
		{
			set->path = cursor;
			cursor->next = set->closed;
			set->closed = cursor;
			return (0);
		}
		if (!*next || cursor->h_score + cursor->g_score < next[0]->h_score + next[0]->g_score)
		{
			*next = cursor;
			*before_next = last;
		}
		last = cursor;
		cursor = cursor->next;
	}
	return (1);
}
/*
** Find the node with the lowest f score in the open queue, (find_next func before)
** take it out of the queue and return it.
** If the goal is in the open queue,
** it put it in the set as the path and return NULL. (also find_next func before)
** If the open queue is empty it return NULL
*/

t_node *get_next_step(t_set *set)
{
	t_node *next;
	t_node *before_next;

	next = NULL;
	before_next = NULL;
	if (!find_next(&next, &before_next, set))
		return (NULL);

	if (next)
	{
		set->open_size -= 1;
		if (before_next)
			before_next->next = next->next;
		else
			set->open = next->next;
	}
	return (next);
}

/*
** increment or decrement the coordinates in the right direction
** in order to reproduce a snail
*/
void increment_coord(int *coord, int *direction, int size, int *goal)
{
	if (*direction % 2 == 0)
	{
		coord[1] = *direction == 0 ? coord[1] + 1 : coord[1] - 1;
		if (coord[1] == size || coord[1] < 0 || goal[coord[0] + coord[1] * size])
		{
			coord[1] = *direction == 0 ? coord[1] - 1 : coord[1] + 1;
			*direction = (*direction + 1) % 4;
			increment_coord(coord, direction, size, goal);
		}
	}
	else
	{
		coord[0] = *direction == 3 ? coord[0] + 1 : coord[0] - 1;
		if (coord[0] == size || coord[0] < 0 || goal[coord[0] + coord[1] * size])
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
int *get_goal(int size)
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
	return goal;
}
