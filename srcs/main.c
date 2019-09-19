/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerli <tmerli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 14:57:49 by etieberg          #+#    #+#             */
/*   Updated: 2019/09/19 17:34:01 by tmerli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_puzzle.h"

void	return_failure(char *str, char *op)
{
	ft_putstr_fd(str, 2);
	if (op != NULL)
		ft_putendl_fd(op, 2);
	else
		ft_putchar_fd('\n', 2);
	exit(0);
}

int		main(int ac, char **av)
{
	int		fd;
	int		*tab;
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
	printf("n: %i\n", n);
	print_puzzle(tab, n);
	a_star(tab, n, 0);
	close(fd);
	free(tab);
	return (0);
}
