/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A-star.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerli <tmerli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 11:32:19 by tmerli            #+#    #+#             */
/*   Updated: 2019/09/11 17:59:47 by tmerli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/n_puzzle.h"

void init_set(t_set *set, int *puzzle, int size, int heuristic)
{
	set->goal = get_goal(size); // <----  TO DO int *get_goal(int size) : get the array corresponding to the goal (snake solution) of the puzzle
	set->size = size;
	set->heuristic = heuristic;
	set->closed = ft_malloc_check(sizeof(t_node));
	set->closed->puzzle = puzzle;
	set->closed->g_score = 0;
	set->closed->next = NULL;
	set->open = NULL;
}

void set_new_node(int *puzzle, t_node *current, t_set *set)
{
	t_node *new;

	if (!in_closed(puzzle, set->closed, set->size))
	{
		new = ft_malloc_check(sizeof(t_node));
		new->g_score = current->g_score + 1;
		new->h_score = (*g_heuristic[set->heuristic])(puzzle, set->goal, set->size);
		new->from = current;
		new->puzzle = ft_memcpy(ft_memalloc(set->size * set->size * sizeof(int) + sizeof(int)),
								puzzle, set->size * set->size * sizeof(int) + sizeof(int));
		new->next = set->open;
		set->open = new;
		set->open_size += 1;
		set->open_max_size = set->open_size > set->open_max_size ? set->open_size : set->open_max_size;
	}
}

void ad_to_list(int replaced, t_node *current, t_set *set)
{
	int puzzle[set->size + 1];
	int i;

	puzzle[set->size] = 0;
	while (current->puzzle[i])
	{
		if (current->puzzle[i] == replaced)
			puzzle[i] = -1;
		else if (current->puzzle[i] == -1)
			puzzle[i] = replaced;
		else
			puzzle[i] = current->puzzle[i];
	}
	set_new_node(puzzle, current, set);
}

void fill_open(t_set *set, t_node *current)
{
	int coord[2];

	get_coord(-1, set->size, current->puzzle, &coord[0], &coord[1]);
	if (coord[0] + 1 < set->size)
		add_to_list(current->puzzle[coord[0] + 1 + coord[1] * set->size], current, set);
	if (coord[0] - 1 >= 0)
		add_to_list(current->puzzle[coord[0] - 1 + coord[1] * set->size], current, set);
	if (coord[1] + 1 < set->size)
		add_to_list(current->puzzle[coord[0] + coord[1] + 1 * set->size], current, set);
	if (coord[1] - 1 < set->size)
		add_to_list(current->puzzle[coord[0] + coord[1] - 1 * set->size], current, set);
}

void Astar(int *puzzle, int size, int heuristic)
{
	t_set set;
	t_node *current;

	init_set(&set, puzzle, size, heuristic);
	current = set.closed;

	while (current)
	{
		fill_open(&set, current);
		current->next = set.closed;
		set.closed = current;
		current = get_next_step(&set);
	}
	print_end(set); // <----  TO DO void print_end(set) : print the result
	free_all(set);  // <---- TO DO 	void free_all(set)  : free all list, pointer etc.. of the set
}
