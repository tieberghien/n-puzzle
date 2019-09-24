/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heuristic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerli <tmerli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 10:47:50 by tmerli            #+#    #+#             */
/*   Updated: 2019/09/24 16:29:43 by etieberg         ###   ########.fr       */
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
