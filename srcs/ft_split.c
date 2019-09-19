/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etieberg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 15:46:02 by etieberg          #+#    #+#             */
/*   Updated: 2019/09/19 15:51:34 by etieberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_puzzle.h"

static int	ft_count_words(char const *s)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && (s[i] == ' ' || s[i] == '\n'))
			i++;
		while (s[i] && (s[i] != ' ' && s[i] != '\n'))
			i++;
		if (s[i] != '\0' || s[i] != '\t' || s[i - 1] != '\n' || s[i - 1] != ' ')
			j++;
	}
	return (j);
}

char		**ft_split(char const *s)
{
	char	**tab;
	int		i;
	int		j;
	int		count;

	i = 0;
	if (!s)
		return (NULL);
	count = ft_count_words(s);
	if (!(tab = (char**)malloc(sizeof(char*) * (count + 1))))
		return (NULL);
	while (i < count)
	{
		j = 0;
		while (*s && (*s == ' ' || *s == '\n'))
			s++;
		while (*(s + j) && (*(s + j) != ' ' && *(s + j) != '\n'))
			j++;
		*(tab++) = ft_strsub(s, 0, j);
		s = s + j;
		i++;
	}
	*tab = NULL;
	return (tab - count);
}
