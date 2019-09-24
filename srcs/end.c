/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerli <tmerli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 13:56:00 by tmerli            #+#    #+#             */
/*   Updated: 2019/09/24 16:07:18 by etieberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_puzzle.h"

void	reverse_path(t_set *set)
{
	t_node *prev;
	t_node *cur;
	t_node *next;

	cur = set->path;
	prev = NULL;
	next = NULL;
	while (cur)
	{
		next = cur->from;
		cur->from = prev;
		prev = cur;
		cur = next;
	}
	set->path = prev;
}

void	print_end(t_set *set)
{
	int i;

	i = 1;
	if (set->path)
	{
		printf("time complexity: %i, size complexity: + %i = %i\n",
		set->closed_size, set->open_size, set->open_size + set->closed_size);
		printf("path:\n");
		reverse_path(set);
		while (set->path)
		{
			print_puzzle(set->path->puzzle, set->size);
			printf("\n");
			set->path = set->path->from;
			i++;
		}
		printf("path size: %i\n", i);
	}
	else
		printf("puzzle not solvable, time and size complexity : 0\n");
}

void	free_list(t_node *list)
{
	t_node *tmp;

	while (list)
	{
		tmp = list->next;
		free(list->puzzle);
		free(list);
		list = tmp;
	}
}

void	free_all(t_set *set)
{
	free_list(set->closed);
	free_list(set->open);
	free(set->goal);
}
