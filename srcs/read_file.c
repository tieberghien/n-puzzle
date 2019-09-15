/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etieberg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 20:56:09 by etieberg          #+#    #+#             */
/*   Updated: 2019/09/15 17:25:33 by etieberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_puzzle.h"

int		is_comment(char *line)
{
	int i;

	i = -1;
	while (ft_isprint(line[++i]))
		if (line[i] == '#' || !line[i])
			return (1);
	return (0);
}

static int	get_n(char *input)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (input[i] && !ft_isdigit(input[i]) && input[i] != '-')
		i++;
	if (i < ft_strlen(input))
		n = ft_atoi(input + i);
	while (input[i] == ' ' || input[i] == '\t')
		i++;
	if (i + ft_intlen(n, 10) < ft_strlen(input))
		dprintf(2, "EH\n");
	return (n);
}

static int	check_puzzle(int *puzzle, int n)
{
	int	i;
	int size;

	i = -1;
	size = n*n;
	while (puzzle[++i])
	{
		if (puzzle[i] > size - 1 || puzzle[i] < -1)
			return (0);
	}
	return (1);
}

static int *get_puzzle(char **tab, int i, int n)
{
	int		j;
	int		k;
	int		*puzzle;

	k = 0;
	if (!(puzzle = (int*)malloc(sizeof(int) * (n * n) + 1)))
		return (NULL);
	i++;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j] && k < (n * n))
		{
			if (ft_isdigit(tab[i][j]))
			{
				puzzle[k] = ft_atoi(&tab[i][j]);
				if (puzzle[k] == 0)
					puzzle[k] = -1;
				k++;
			}
			j++;
		}
		i++;
	}
	if (!check_puzzle(puzzle, n))
		return (0);
	k = 0;
	while (puzzle[k])
	{
		dprintf(2, "%d,", puzzle[k]);
		k++;
	}
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

int			read_file(int fd)
{
	int		i;
	int		j;
	int		n;
	char	*line;
	char	**tab;

	i = -1;
	n = 0;
	line = get_input(fd);
	if (*line == 0)
	{
		free(line);
		return_failure("Empty map.", NULL);
	}
	if ((tab = ft_strsplit(line, '\n')) == NULL)
	{
		free(line);
		return_failure("Could mot read input.", NULL);
	}
	while (tab[++i])
	{
		if (tab[i][0] == '#' && tab[i][0] == '\n')
			continue ;
		if (n == 0)
		{
			n = get_n(tab[i]);
			j = i;
		}
	}
	if (n < 3)
		return_failure("N needs to be at least 3x3.", NULL);
	if (!get_puzzle(tab, j, n))
		return (0);
	return (1);
}
