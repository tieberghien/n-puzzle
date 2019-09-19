/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerli <tmerli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 14:36:00 by tmerli            #+#    #+#             */
/*   Updated: 2019/09/19 17:13:17 by tmerli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/n_puzzle.h"

int get_blank_pos(int *puzzle)
{
	int i;

	i = 0;
	while (puzzle[i] > 0)
		i++;
	if (!puzzle[i])
		printf("error !!\n");
	return (i);
}

void print_puzzle(int *puzzle, int size)
{
	int x;
	int y;

	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			printf("%- 4i", puzzle[x + y * size] == -1 ? 0 : puzzle[x + y * size]);
			x++;
		}
		printf("\n");
		y++;
	}
}

int *copy_puzzle(int *puzzle, int size)
{
	int i;
	int *new;

	new = ft_memalloc(sizeof(int) * size * size + sizeof(int));
	i = 0;
	while (puzzle[i])
	{
		new[i] = puzzle[i];
		i++;
	}
	return (new);
}

int inversion_count(int *tab)
{
	int inversion;
	int i;
	int j;

	i = 0;
	inversion = 0;
	while (tab[i])
	{
		if (tab[i] != -1)
		{
			j = i + 1;
			while (tab[j])
			{
				if (tab[j] != -1 && tab[i] > tab[j])
					inversion++;
				j++;
			}
		}
		i++;
	}
	return (inversion);
}

int is_solvable(int *puzzle, int *goal, int size)
{
	int inv_puz;
	int inv_goal;

	inv_puz = inversion_count(puzzle);
	inv_goal = inversion_count(goal);
	if (size % 2 == 0)
	{
		inv_puz += get_blank_pos(puzzle);
		inv_goal += get_blank_pos(goal);
	}
	return (inv_puz % 2 == inv_goal % 2);
}
