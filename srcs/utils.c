/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerli <tmerli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 14:36:00 by tmerli            #+#    #+#             */
/*   Updated: 2019/09/19 12:55:53 by etieberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/n_puzzle.h"

void get_coord(int num, int size, int *puzzle, int *x, int *y)
{
	int i;

	i = 0;
	while (puzzle[i] && puzzle[i] != num)
		i++;

	if (i == size * size)
	{
		printf("error !!\n");
	}
	*x = i % size;
	*y = i / size;
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

int	invertion_count(int *tab)
{
	int i;
	int j;
	int inversion;

	i = 0;
	j = 0;
	inversion = 0;
	while (tab[i])
	{
		if (tab[i] != -1 && i != 0 && i > tab[i])
			inversion++;
		i++;
	}
	return (inversion);
}

int is_solvable(int *puzzle, int *goal, int size)
{
	int	inv_puz;
	int inv_goal;

	inv_puz = invertion_count(puzzle);
	inv_goal = invertion_count(goal);
	if (size % 2 == 0)
	{
		inv_puz += puzzle[0];
		inv_goal += goal[0];
	}
	return (inv_puz % 2 == inv_goal % 2);
}

/*
int is_solvable(int *puzzle, int *goal, int size)
{
	int inversion;
	int i;
	int j;
	int goal_pos[size * size + 1];
	int blank_pos;

	i = 0;
	inversion = 0;
	while (goal[i])
	{
		goal_pos[goal[i] == -1 ? 0 : goal[i]] = i;
		i++;
	}
	i = 0;
	while (puzzle[i])
	{
		if (puzzle[i] != -1)
		{
			j = i + 1;
			while (puzzle[j])
			{
				if (puzzle[j] != -1 && goal_pos[puzzle[j]] < goal_pos[puzzle[i]])
					inversion++;
				j++;
			}
		}
		else
			blank_pos = i;
		i++;
	}
	printf("inversion: %i, blank_pos: %i, blank row: %i", inversion, blank_pos, size - blank_pos / size);
	if (size % 2 != 0)
		return inversion % 2 == 0;
	else
		return (size - blank_pos / size) % 2 != inversion % 2;
}
*/
