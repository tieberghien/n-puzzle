/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etieberg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 20:56:09 by etieberg          #+#    #+#             */
/*   Updated: 2019/09/08 21:17:35 by etieberg         ###   ########.fr       */
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

int			read_file(int fd)
{
	int		i;
	char	*line;

	i = 0;
	while (get_next_line(fd, &line) > 0 && ++i)
	{
		if (is_comment(line))
			dprintf(2, "%s\n", line);
	//	line++;
	//	get_line(&line, i); stockage du puzzle
	}
	/**
		conditions a remplir (taille puzzle + cases puzzle)
	if (!get_n(a) || !get_puzzle(a))
		return (0);
	**/
//	clean_lines(a); rm comments;
	return (1);
}
