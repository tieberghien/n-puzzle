/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_puzzle.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerli <tmerli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 14:57:28 by etieberg          #+#    #+#             */
/*   Updated: 2019/09/19 14:29:42 by tmerli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef N_PUZZLE_H
#define N_PUZZLE_H
#define USAGE "Usage: ./solver <sourcefile>"
#include <fcntl.h>
#include "../libft/includes/libft.h"
#include <stdio.h>

typedef struct s_node
{
	int g_score;
	int h_score;
	int *puzzle;
	struct s_node *next;
	struct s_node *from;
} t_node;

typedef struct s_set
{
	t_node *open;
	t_node *closed;
	t_node *path;
	int *goal;
	int open_size;
	int closed_size;
	int size;
	int heuristic;
} t_set;

int linear_conflict_manhattan(int *current, int *goal, int n);
int manhatan(int *current, int *goal, int n);
int hamming(int *current, int *goal, int n);
int read_file(int fd);
int get_blank_pos(int *puzzle);
t_node *get_next_step(t_set *set);
int in_queue(int *puzzle, t_node *queue, int size);
int *get_goal(int size);
void a_star(int *puzzle, int size, int heuristic);
void print_puzzle(int *puzzle, int size);
int *copy_puzzle(int *puzzle, int size);
int is_solvable(int *puzzle, int *goal, int size);
#endif
