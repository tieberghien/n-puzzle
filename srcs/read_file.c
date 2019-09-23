/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerli <tmerli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 20:56:09 by etieberg          #+#    #+#             */
/*   Updated: 2019/09/23 14:32:40 by etieberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_puzzle.h"

static int	check_puzzle(int *puzzle, int n)
{
	int	i;
	int size;

	i = 0;
	size = n * n;
	while (puzzle[i])
	{
		if (puzzle[i] > size - 1 || puzzle[i] < -1)
			return (0);
		i++;
	}
	if (i < size)
		return (0);
	return (1);
}

static int	check_tab(char **tab)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (tab[i])
	{
		if (ft_isdigit(*tab[i]))
			count++;
		i++;
	}
	return (count);
}

static int	*get_puzzle(char **tab, int i, int n)
{
	int		k;
	int		*puzzle;

	k = 0;
	if (check_tab(tab + i + 1) > (n * n))
		return (0);
	if (!(puzzle = (int*)malloc(sizeof(int) * (n * n) + sizeof(int))))
		return (NULL);
	i++;
	while (tab[i] && k < (n * n))
	{
		if (ft_isdigit(*tab[i]))
		{
			puzzle[k] = ft_atoi(tab[i]);
			if (puzzle[k] == 0)
				puzzle[k] = -1;
			k++;
		}
		i++;
	}
	puzzle[k] = 0;
	if (!check_puzzle(puzzle, n))
		return (0);
	return (puzzle);
}

char		*get_input(int fd)
{
	char	buff[4096];
	char	*cmd;
	char	*tmp;

	cmd = ft_strnew(0);
	while (1)
	{
		ft_bzero(buff, 4096);
		read(fd, buff, 1);
		if (buff[0] == '\0')
			break ;
		tmp = cmd;
		cmd = ft_strjoin(cmd, buff);
		free(tmp);
	}
	return (cmd);
}

int			read_file(int fd, int **tmp)
{
	int		i;
	int		n;
	char	*line;
	char	**tab;

	i = -1;
	n = 0;
	line = get_input(fd);
	if (line && *line == 0)
		return_failure("Empty map.", line);
	if ((tab = ft_split(line)) == NULL)
		return_failure("Could not read input.", line);
	while (tab[++i])
		if (n == 0 && ft_isdigit(*tab[i]))
		{
			n = ft_atoi(tab[i]);
			break ;
		}
	free(line);
	if (n < 3)
		return_failure("N needs to be at least 3x3.", NULL);
	if (!(*tmp = get_puzzle(tab, i, n)))
		return (0);
	double_free(tab);
	return (n);
}
