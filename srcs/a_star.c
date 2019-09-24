/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A-star.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerli <tmerli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 11:32:19 by tmerli            #+#    #+#             */
/*   Updated: 2019/09/24 15:53:14 by etieberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_puzzle.h"

/*
** Initialize the set with the right value, mem allocation etc..
*/

void	init_set(t_set *set, int *puzzle, int size, t_node **current)
{
	set->goal = get_goal(size);
	set->size = size;
	set->open_size = 0;
	set->closed_size = 0;
	*current = ft_malloc_check(sizeof(t_node));
	current[0]->puzzle = puzzle;
	current[0]->g_score = 0;
	current[0]->next = NULL;
	current[0]->from = NULL;
	set->closed = NULL;
	set->open = NULL;
	set->path = NULL;
}

/*
** If a puzzle configuration is not in the closed list,
** it create a node, give it the right value (h score, gscore etc..)
** put it in the open queue
*/

void	add_to_list(int *puzzle, t_node *current, t_set *set)
{
	t_node *new;
	t_node *last;

	last = NULL;
	if (!is_solution(puzzle, current, set) && !set->path)
	{
		if (!in_queue(puzzle, set->closed, set->size)
			&& !in_queue(puzzle, set->open, set->size))
		{
			new = new_node(current, puzzle, set);
			push(new, set);
		}
	}
}

/*
** create the new puzzle config and send to the add_to _list func
*/

void	set_new_puzzle(int replaced, t_node *current, t_set *set)
{
	int puzzle[set->size * set->size + 1];
	int i;

	puzzle[set->size * set->size] = 0;
	i = 0;
	while (current->puzzle[i])
	{
		if (current->puzzle[i] == replaced)
			puzzle[i] = -1;
		else if (current->puzzle[i] == -1)
			puzzle[i] = replaced;
		else
			puzzle[i] = current->puzzle[i];
		i++;
	}
	add_to_list(puzzle, current, set);
}

/*
** fill the open queue with the potential puzzle with the current node
** thanks to the other last 2 functions
*/

void	fill_open(t_set *set, t_node *current)
{
	int blank_pos;
	int coord[2];

	blank_pos = get_blank_pos(current->puzzle);
	coord[0] = blank_pos % set->size;
	coord[1] = blank_pos / set->size;
	if (coord[0] + 1 < set->size)
		set_new_puzzle(current->puzzle[coord[0] + 1 + coord[1] * set->size],
		current, set);
	if (coord[0] - 1 >= 0)
		set_new_puzzle(current->puzzle[coord[0] - 1 + coord[1] * set->size],
		current, set);
	if (coord[1] + 1 < set->size)
		set_new_puzzle(current->puzzle[coord[0] + (coord[1] + 1) * set->size],
		current, set);
	if (coord[1] - 1 >= 0)
		set_new_puzzle(current->puzzle[coord[0] + (coord[1] - 1) * set->size],
		current, set);
}

/*
** contain the whole algorithm
*/

void	a_star(int *puzzle, int size, int heuristic)
{
	t_set	set;
	t_node	*current;

	init_set(&set, puzzle, size, &current);
	set.heuristic = heuristic;
	if (is_solvable(puzzle, set.goal, size))
	{
		while (!set.path)
		{
			fill_open(&set, current);
			current->next = set.closed;
			set.closed = current;
			current = set.open;
			set.open = current->next;
			set.closed_size += 1;
			set.open_size -= 1;
		}
	}
	print_end(&set);
	free_all(&set);
	if (current)
	{
		free(current);
		free(current->puzzle);
	}
}
