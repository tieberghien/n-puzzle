/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerli <tmerli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 14:57:49 by etieberg          #+#    #+#             */
/*   Updated: 2019/09/24 16:04:27 by etieberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_puzzle.h"

void		return_failure(char *str, void *op)
{
	ft_putendl_fd(str, 2);
	if (op != NULL)
		free(op);
	exit(0);
}

static int	get_heuristic(int ac, char **av, int *flag, int *algo)
{
	int ch;

	*flag = 0;
	*algo = 0;
	while ((ch = getopt(ac, av, "mhle")) != -1)
	{
		if (ch == 'm')
			*flag = 0;
		else if (ch == 'h')
			*flag = 1;
		else if (ch == 'l')
			*flag = 2;
		else if (ch == 'e')
			*flag = 3;
		break ;
	}
	while ((ch = getopt(ac, av, "gu")) != -1)
	{
		if (ch == 'g')
			*algo = 1;
		else if (ch == 'u')
			*algo = 2;
		break ;
	}
	return (optind);
}

int			main(int ac, char **av)
{
	int	fd;
	int	*tab;
	int	flag;
	int	algo;
	int	i;

	i = 1;
	tab = NULL;
	if (ac < 2)
		return_failure(USAGE, NULL);
	i = get_heuristic(ac, av, &flag, &algo);
	if ((fd = open(av[i], O_RDONLY)) == -1)
		return_failure("Can't read source file.", NULL);
	if (!(i = read_file(fd, &tab)))
		return_failure("Invalid puzzle.", NULL);
	a_star(tab, i, flag, algo);
	close(fd);
	return (0);
}
