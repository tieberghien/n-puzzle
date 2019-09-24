/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerli <tmerli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 16:45:05 by tmerli            #+#    #+#             */
/*   Updated: 2019/09/24 16:17:25 by tmerli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int main(void)
{
	char map[50] = {0};
	unsigned int hash = 0;
	int puzzle[10] = {1, 2, 3, 4, -1, 5, 6, 7, 8, 0};
	int i = 0;

	while (puzzle[i])
	{
		hash += *puzzle;
		hash *= 13;
		i++;
	}
	hash = hash % (49 * 8);
	map[hash / 8] |= (1 << (hash % 8));
	i = 0;
	int value;
	while (i < 50 * 8)
	{
		value = (map[i/8] & (1 << (i%8))) != 0;
		printf("%i ", value);
		i++;
		if (i % 8 == 0)
			printf("\n");
	}
}
