/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etieberg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 20:56:09 by etieberg          #+#    #+#             */
/*   Updated: 2019/09/08 21:57:16 by etieberg         ###   ########.fr       */
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
		if (buff[0] == '\n')
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
	char	*line;

	i = 0;
	while ((line = get_input(fd)) != NULL)
	{
		if (is_comment(line))
			continue ;
		//	if (!(get_line(&line, i)) ; stockage du puzzle
		//		break ;
	}
	/**
	  conditions a remplir (taille puzzle + cases puzzle)
	  if (!check_n(a) || !check_puzzle(a))
	  return (0);
	 **/
	//	clean_lines(a); rm comments;
	return (1);
}
