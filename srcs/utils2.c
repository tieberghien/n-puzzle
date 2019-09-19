/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerli <tmerli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 15:27:15 by tmerli            #+#    #+#             */
/*   Updated: 2019/09/19 17:00:59 by tmerli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/n_puzzle.h"

int (*g_heuristic[3])(int *current, int *goal, int n) =
	{linear_conflict_manhattan, manhatan, hamming};

t_node *new_node(t_node *current, int *puzzle, t_set *set)
{
	t_node *new;

	new = ft_malloc_check(sizeof(t_node));
	new->g_score = current->g_score + 1;
	new->h_score = (*g_heuristic[set->heuristic])(puzzle, set->goal, set->size);
	new->from = current;
	new->puzzle = copy_puzzle(puzzle, set->size);
	new->next = NULL;
	set->open_size += 1;

	return (new);
}

int is_solution(int *puzzle, t_node *current, t_set *set)
{
	if (!ft_memcmp(set->goal, puzzle, set->size * set->size * sizeof(int) + sizeof(int)))
	{
		set->path = new_node(current, puzzle, set);
		set->path->next = set->closed;
		set->closed_size += 1;
		set->open_size -= 1;
		set->closed = set->path;
		return (1);
	}
	return (0);
}

void push(t_node *new, t_set *set)
{
	t_node *cursor;
	t_node *last;

	cursor = set->open;
	if (!cursor)
		set->open = new;
	else
	{
		while (cursor)
		{
			if (cursor->g_score + cursor->h_score >= new->h_score + new->g_score)
			{
				if (last)
					last->next = new;
				else
					set->open = new;
				new->next = cursor;
				break;
			}
			last = cursor;
			cursor = cursor->next;
		}
		if (!cursor)
			last->next = new;
	}
}