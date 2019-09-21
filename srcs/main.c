/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerli <tmerli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 14:57:49 by etieberg          #+#    #+#             */
/*   Updated: 2019/09/21 16:45:06 by etieberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_puzzle.h"

void	return_failure(char *str, void *op)
{
	ft_putendl_fd(str, 2);
	if (op != NULL)
		free(op);
	exit(0);
}

static int	get_heuristic(int ac, char **av)
{
	int ch;

	while ((ch = getopt (ac, av, "mhl:")) != -1)
	{
		if (ch == 'm')
			return (0);
		if (ch == 'h')
			return (1);
		if (ch == 'l')
			return (2);
		break ;
	}
	return (-1);
}

int		main(int ac, char **av)
{
	int		fd;
	int		*tab;
	int flag;
	int n;
	int i;

	i = 1;
	tab = NULL;
	if (ac < 2)
		return_failure(USAGE, NULL);
	if ((flag = get_heuristic(ac, av)) != -1)
		i++;
	flag = (flag == -1) ? 0 : flag;
	if ((fd = open(av[i], O_RDONLY)) == -1)
	{
		ft_putstr_fd("Can't read source file ", 2);
		ft_putstr_fd(av[i], 2);
		ft_putchar_fd('\n', 2);
		return (-1);
	}
	if (!(n = read_file(fd, &tab)))
	{
		ft_putstr_fd("SYNTAX ERROR\n", 2);
		return (-1);
	}
	a_star(tab, n, flag);
	close(fd);
	free(tab);
	return (0);
}
