/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heuristic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerli <tmerli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 10:47:50 by tmerli            #+#    #+#             */
/*   Updated: 2019/09/24 16:31:32 by etieberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_puzzle.h"

static int	conflict(int *coord, int j, int goal_j, int n)
{
	int coord2[4];

	coord2[0] = j % n;
	coord2[1] = j / n;
	coord2[2] = goal_j % n;
	coord2[3] = goal_j % n;
	if ((coord2[0] == coord[0] && coord2[2] == coord[2])
		|| (coord2[1] == coord[1] && coord2[3] == coord[3]))
	{
		if ((coord2[0] == coord[0]
			&& (ft_in_interval(coord2[1], coord[1], coord[3])
			|| ft_in_interval(coord[1], coord2[1], coord2[3])))
			|| (coord2[1] == coord[1]
			&& (ft_in_interval(coord2[0], coord[0], coord[2])
			|| ft_in_interval(coord[0], coord2[0], coord2[2]))))
			return (1);
	}
	return (0);
}

static void	fill_coord(int coord[4], int i, int j, int n)
{
	coord[0] = i % n;
	coord[1] = i / n;
	coord[2] = j % n;
	coord[3] = j / n;
}

int			linear_conflict_manhattan(int *current, int *goal, int n)
{
	int i;
	int j;
	int coord[4];
	int h;
	int *current_cpy;

	i = -1;
	h = manhatan(current, goal, n);
	current_cpy = copy_puzzle(current, n);
	while (current_cpy[++i])
		if (current_cpy[i] != -1)
		{
			j = find_goal(current_cpy[i], goal);
			fill_coord(coord, i, j, n);
			j = i;
			while (current_cpy[++j])
				if (current_cpy[j] != -1 && conflict(coord, j,
					find_goal(current_cpy[j], goal), n))
				{
					h += 2;
					current_cpy[j] = -1;
				}
		}
	ft_memdel((void **)&current_cpy);
	return (h);
}
