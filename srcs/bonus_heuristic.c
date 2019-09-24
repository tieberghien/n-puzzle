/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heuristic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerli <tmerli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 10:47:50 by tmerli            #+#    #+#             */
/*   Updated: 2019/09/24 14:24:44 by etieberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_puzzle.h"

int	euclidian(int *current, int *goal, int n)
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
			h += (int)sqrt(((j % n - i % n) * (j % n - i % n)) +
				((j / n - i / n) * (j / n - i / n)));
		}
		i++;
	}
	return (h);
}
