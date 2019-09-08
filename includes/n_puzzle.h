/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_puzzle.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etieberg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 14:57:28 by etieberg          #+#    #+#             */
/*   Updated: 2019/09/08 22:00:41 by etieberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef N_PUZZLE_H
# define N_PUZZLE_H
# define USAGE "Usage: ./solver <sourcefile>"
# include <fcntl.h>
# include "libft.h"

typedef struct	s_puzzle
{
	size_t		n;
	int			puzzle[n*n];
}				t_puzzle;

int read_file(int fd);

#endif
