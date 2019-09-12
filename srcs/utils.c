/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerli <tmerli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 14:36:00 by tmerli            #+#    #+#             */
/*   Updated: 2019/09/12 19:08:49 by tmerli           ###   ########.fr       */
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
