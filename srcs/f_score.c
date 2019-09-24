/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_score.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etieberg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 12:19:32 by etieberg          #+#    #+#             */
/*   Updated: 2019/09/24 12:22:35 by etieberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_puzzle.h"

int		astar_score(t_node *curr)
{
	return (curr->g_score + curr->h_score);
}

int		greedy_score(t_node *curr)
{
	return (curr->h_score);
}

int		uniform_score(t_node *curr)
{
	return (curr->g_score);
}
