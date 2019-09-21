/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerli <tmerli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 14:57:49 by etieberg          #+#    #+#             */
/*   Updated: 2019/09/21 16:06:08 by etieberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_puzzle.h"

void	return_failure(char *str, void *op)
{
	ft_putstr_fd(str, 2);
	if (op != NULL)
		free(op);
	ft_putchar_fd('\n', 2);
	exit(0);
}

static int	get_heuristic(char *str)
{
	if (!(ft_strncmp(str, "MANHATTAN", 9)))
		return (0);
	else if (!(ft_strncmp(str, "HAMMING", 7)))
		return (1);
	else if (!(ft_strncmp(str, "L_CONFLICT", 10)))
		return (2);
	return (-1);
}

int		main(int ac, char **av)
{
	int		fd;
	int		*tab;
	int heuristic;
	int n;

	tab = NULL;
	if (ac < 2)
		return_failure(USAGE, NULL);
	if ((fd = open(av[1], O_RDONLY)) == -1)
	{
		ft_putstr_fd("Can't read source file ", 2);
		ft_putstr_fd(av[1], 2);
		ft_putchar_fd('\n', 2);
		return (-1);
	}
	if (!(n = read_file(fd, &tab)))
	{
		ft_putstr_fd("SYNTAX ERROR\n", 2);
		return (-1);
	}
	heuristic = 0;
	if (ac == 3)
		if ((heuristic = get_heuristic(av[2])) == -1)
			return_failure(USAGE, NULL);
	a_star(tab, n, heuristic);
	close(fd);
	free(tab);
	return (0);
}
