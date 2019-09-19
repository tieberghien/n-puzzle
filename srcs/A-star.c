/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A-star.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerli <tmerli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 11:32:19 by tmerli            #+#    #+#             */
/*   Updated: 2019/09/17 17:41:03 by tmerli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/n_puzzle.h"

int (*g_heuristic[3])(int *current, int *goal, int n) =
	{linear_conflict_manhattan, manhatan, hamming};

/*
** Initialize the set with the right value, mem allocation etc..
*/
void init_set(t_set *set, int *puzzle, int size, int heuristic, t_node **current)
{
	set->goal = get_goal(size);
	set->size = size;
	set->heuristic = heuristic;
	set->open_size = 0;
	set->closed_size = 0;
	*current = ft_malloc_check(sizeof(t_node));
	current[0]->puzzle = puzzle;
	current[0]->g_score = 0;
	current[0]->next = NULL;
	current[0]->from = NULL;
	set->closed = NULL;
	set->open = NULL;
}

/*
** If a puzzle configuration is not in the closed list,
** it create a node, give it the right value (h score, gscore etc..)
** put it in the open queue
*/
void add_to_list(int *puzzle, t_node *current, t_set *set)
{
	t_node *new;
	int h;

	h = (*g_heuristic[set->heuristic])(puzzle, set->goal, set->size);

	if (!in_queue(puzzle, set->closed, set->size) && !in_queue(puzzle, set->open, set->size))
	{
		new = ft_malloc_check(sizeof(t_node));
		new->g_score = current->g_score + 1;
		new->h_score = h;
		new->from = current;
		new->puzzle = copy_puzzle(puzzle, set->size);
		new->next = set->open;
		set->open = new;
		set->open_size += 1;
	}
}

/*
** create the new puzzle config and send to the add_to _list func
*/
void set_new_puzzle(int replaced, t_node *current, t_set *set)
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
void fill_open(t_set *set, t_node *current)
{
	int coord[2];

	get_coord(-1, set->size, current->puzzle, &coord[0], &coord[1]);
	if (coord[0] + 1 < set->size)
		set_new_puzzle(current->puzzle[coord[0] + 1 + coord[1] * set->size], current, set);
	if (coord[0] - 1 >= 0)
		set_new_puzzle(current->puzzle[coord[0] - 1 + coord[1] * set->size], current, set);
	if (coord[1] + 1 < set->size)
		set_new_puzzle(current->puzzle[coord[0] + (coord[1] + 1) * set->size], current, set);
	if (coord[1] - 1 >= 0)
		set_new_puzzle(current->puzzle[coord[0] + (coord[1] - 1) * set->size], current, set);
}

/*
** contain the whole algorithm
*/
void a_star(int *puzzle, int size, int heuristic)
{
	t_set set;
	t_node *current;

	printf("\n");
	init_set(&set, puzzle, size, heuristic, &current);
	print_puzzle(set.goal, size);
	printf("\nis solvable : %i\n", is_solvable(puzzle, set.goal, size));
	// while (current)
	// {
	// 	fill_open(&set, current);
	// 	current->next = set.closed;
	// 	set.closed = current;
	// 	current = get_next_step(&set);
	// 	set.closed_size += 1;
	// }
	// printf("time complexity: %i, size complexity: + %i = %i\n", set.closed_size, set.open_size, set.open_size + set.closed_size);
	// printf("path:\n");
	// while (set.path)
	// {
	// 	print_puzzle(set.path->puzzle, size);
	// 	printf("\n");
	// 	set.path = set.path->from;
	// }
	// printf("end\n");
	// print_end(set); // <----  TO DO void print_end(set) : print the result
	// free_all(set);  // <---- TO DO 	void free_all(set)  : free all list, pointer etc.. of the set
}
