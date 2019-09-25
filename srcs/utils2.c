/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerli <tmerli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 15:27:15 by tmerli            #+#    #+#             */
/*   Updated: 2019/09/25 14:15:49 by etieberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_puzzle.h"

int	(*g_heuristic[4])(int *curr, int *goal, int n) = {linear_conflict_manhattan,
	manhatan, hamming, euclidian};

t_node	*new_node(t_node *current, int *puzzle, t_set *set)
{
	t_node *new;

	if (!(new = (t_node*)malloc(sizeof(t_node))))
		return (NULL);
	new->g_score = current->g_score + 1;
	new->h_score = (*g_heuristic[set->heuristic])(puzzle, set->goal, set->size);
	new->from = current;
	new->puzzle = copy_puzzle(puzzle, set->size);
	new->next = NULL;
	set->open_size += 1;
	return (new);
}

int		is_solution(int *puzzle, t_node *current, t_set *set)
{
	if (!ft_memcmp(set->goal, puzzle, set->size * set->size *
				sizeof(int) + sizeof(int)))
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

void	push(t_node *new, t_set *set)
{
	t_node *curs;
	t_node *last;

	curs = set->open;
	last = NULL;
	set->open = !curs ? new : set->open;
	if (curs)
	{
		while (curs)
		{
			if (curs->g_score + curs->h_score >= new->h_score + new->g_score)
			{
				if (last)
					last->next = new;
				else
					set->open = new;
				new->next = curs;
				break ;
			}
			last = curs;
			curs = curs->next;
		}
		if (!curs)
			last->next = new;
	}
}
