/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerli <tmerli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 14:57:49 by etieberg          #+#    #+#             */
/*   Updated: 2019/09/25 18:09:18 by etieberg         ###   ########.fr       */
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

static int	get_algo(int ac, char **av, int *algo)
{
	int ch;

	while ((ch = getopt(ac, av, "gu")) != -1)
	{
		if (ch == 'g')
			*algo = 1;
		else if (ch == 'u')
			*algo = 2;
		else
			return_failure("Invalid option.", NULL);
		break ;
	}
	return (optind);
}

static int	get_heuristic(int ac, char **av, int *flag, int *algo)
{
	int ch;

	while ((ch = getopt(ac, av, "mhlegu")) != -1)
	{
		if (ch == 'm')
			*flag = 0;
		else if (ch == 'h')
			*flag = 1;
		else if (ch == 'l')
			*flag = 2;
		else if (ch == 'e')
			*flag = 3;
		else if (ch == 'g')
			*algo = 1;
		else if (ch == 'u')
			*algo = 2;
		else
			return_failure("Invalid option.", NULL);
		break ;
	}
	return (get_algo(ac, av, algo));
}

int			main(int ac, char **av)
{
	int	fd;
	int	*tab;
	int	flag;
	int	algo;
	int	i;

	i = 1;
	flag = 0;
	algo = 0;
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
