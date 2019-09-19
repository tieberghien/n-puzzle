/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etieberg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 14:57:49 by etieberg          #+#    #+#             */
/*   Updated: 2019/09/19 16:20:51 by etieberg         ###   ########.fr       */
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
	if (!read_file(fd, &tab))
	{
		ft_putstr_fd("SYNTAX ERROR\n", 2);
		return (-1);
	}
	close(fd);
	free(tab);
	return (0);
}
