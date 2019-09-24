/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heuristic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerli <tmerli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 10:47:50 by tmerli            #+#    #+#             */
/*   Updated: 2019/09/24 14:26:14 by etieberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_puzzle.h"

int	find_goal(int current, int *goal)
{
	int i;

	i = 0;
	while (goal[i])
	{
		if (goal[i] == current)
			return (i);
		i++;
	}
	return (0);
}

int	hamming(int *current, int *goal, int n)
{
	int i;
	int j;
	int h;

	(void)n;
	i = 0;
	h = 0;
	while (current[i])
	{
		if (current[i] != -1)
		{
			j = find_goal(current[i], goal);
			if (j != i)
				h += 1;
		}
		i++;
	}
	return (h);
}

int	manhatan(int *current, int *goal, int n)
{
	int i;
	int j;
	int h;

	i = 0;
	h = 0;
	while (current[i])
	{
		if (current[i] != -1)
		{
			j = find_goal(current[i], goal);
			h += ft_abs(j % n - i % n) + ft_abs(j / n - i / n);
		}
		i++;
	}
	return (h);
}

int	conflict(int *coord, int j, int goal_j, int n)
{
	int coord2[4];

	coord2[0] = j % n;
	coord2[1] = j / n;
	coord2[2] = goal_j % n;
	coord2[3] = goal_j % n;
	if ((coord2[0] == coord[0] && coord2[2] == coord[2]) ||
		(coord2[1] == coord[1] && coord2[3] == coord[3]))
	{
		if ((coord2[0] == coord[0] &&
			(ft_in_interval(coord2[1], coord[1], coord[3]) ||
			ft_in_interval(coord[1], coord2[1], coord2[3]))) ||
			(coord2[1] == coord[1] &&
			(ft_in_interval(coord2[0], coord[0], coord[2]) ||
			ft_in_interval(coord[0], coord2[0], coord2[2]))))
			return (1);
	}
	return (0);
}

int	linear_conflict_manhattan(int *current, int *goal, int n)
{
	int i = -1;
	int j;
	int coord[4];
	int h = manhatan(current, goal, n);
	int *current_cpy = copy_puzzle(current, n);
	int current_goal;

	while (current_cpy[++i])
	{
		if (current_cpy[i] != -1)
		{
			current_goal = find_goal(current_cpy[i], goal);
			coord[0] = i % n;
			coord[1] = i / n;
			coord[2] = current_goal % n;
			coord[3] = current_goal / n;
			j = i;
			while (current_cpy[++j])
			{
				if (current_cpy[j] != -1 && conflict(coord, j, find_goal(current_cpy[j], goal), n))
				{
					h += 2;
					current_cpy[j] = -1;
				}
			}
		}
	}
	ft_memdel((void **)&current_cpy);
	return (h);
}
