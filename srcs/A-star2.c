/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A-star2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerli <tmerli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 16:38:08 by tmerli            #+#    #+#             */
/*   Updated: 2019/09/11 17:55:32 by tmerli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/n_puzzle.h"

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
