/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A-star2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerli <tmerli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 16:38:08 by tmerli            #+#    #+#             */
/*   Updated: 2019/09/12 12:02:13 by tmerli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/n_puzzle.h"

/*
** Check if a configurtion of the n Puzzle is present in the closed list
*/

int in_closed(int *puzzle, t_node *closed, int size)
{
	t_node *cursor;

	cursor = closed;
	while (cursor)
	{
		if (!ft_memcmp(puzzle, cursor->puzzle, size * size * sizeof(int) + sizeof(int)))
			return (0);
		cursor = cursor->next;
	}
	return (1);
}

/*
** Find the node with the lowest f score in the open queue,
** take it out of the queue and return it.
** If the goal is in the open queu,
** it put it in the set as the path and return NULL.
** If the open queue is empty it return NULL
*/

t_node *get_next_step(t_set *set)
{
	t_node *cursor;
	t_node *next;
	t_node *last;
	t_node *before_next;

	next = NULL;
	last = NULL;
	before_next = NULL;
	cursor = set->open;
	while (cursor)
	{
		if (!ft_memcmp(set->goal, cursor->puzzle, set->size * set->size * sizeof(int) + sizeof(int)))
		{
			set->path = cursor;
			return (NULL);
		}
		if (!next || cursor->h_score + cursor->g_score < next->h_score + next->g_score)
		{
			next = cursor;
			before_next = last;
		}
		last = cursor;
		cursor = cursor->next;
	}
	if (next)
	{
		if (before_next)
			before_next->next = next->next;
		else
			set->open = next->next;
	}
	return (next);
}
