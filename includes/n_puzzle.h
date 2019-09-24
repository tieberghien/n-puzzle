/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_puzzle.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerli <tmerli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 17:13:32 by tmerli            #+#    #+#             */
/*   Updated: 2019/09/24 14:30:20 by etieberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef N_PUZZLE_H
# define N_PUZZLE_H
# define USAGE "Usage: ./solver [-mhl] [sourcefile]"
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include "libft.h"
# include <stdio.h>

typedef struct		s_node
{
	int				g_score;
	int				h_score;
	int				*puzzle;
	struct s_node	*next;
	struct s_node	*from;
}					t_node;

typedef struct		s_set
{
	t_node			*open;
	t_node			*closed;
	t_node			*path;
	int				*goal;
	int				open_size;
	int				closed_size;
	int				size;
	int				heuristic;
}					t_set;

int					linear_conflict_manhattan(int *current, int *goal, int n);
int					manhatan(int *current, int *goal, int n);
int					hamming(int *current, int *goal, int n);
int					euclidian(int *current, int *goal, int n);
int					find_goal(int current, int *goal);
int					get_blank_pos(int *puzzle);
t_node				*get_next_step(t_set *set);
int					in_queue(int *puzzle, t_node *queue, int size);
int					*get_goal(int size);
void				a_star(int *puzzle, int size, int heuristic);
void				print_puzzle(int *puzzle, int size);
int					*copy_puzzle(int *puzzle, int size);
int					is_solvable(int *puzzle, int *goal, int size);
t_node				*new_node(t_node *current, int *puzzle, t_set *set);
int					is_solution(int *puzzle, t_node *current, t_set *set);
void				push(t_node *new, t_set *set);
int					linear_conflict_manhattan(int *current, int *goal, int n);
int					manhatan(int *current, int *goal, int n);
int					hamming(int *current, int *goal, int n);
int					read_file(int fd, int **puzzle);
void				get_coord(int place, int size, int *puzzle, int *x, int *y);
t_node				*get_next_step(t_set *set);
int					in_queue(int *puzzle, t_node *queue, int size);
int					*get_goal(int size);
void				a_star(int *puzzle, int size, int heuristic);
void				print_puzzle(int *puzzle, int size);
int					*copy_puzzle(int *puzzle, int size);
int					is_solvable(int *puzzle, int *goal, int size);
void				return_failure(char *str, void *op);
char				**ft_split(char const *s);
int					astar_score(t_node *curr);
int					greedy_score(t_node *curr);
int					uniform_score(t_node *curr);
void				print_end(t_set *set);
void				free_all(t_set *set);

#endif
