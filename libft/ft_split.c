/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 15:53:41 by mtigunit          #+#    #+#             */
/*   Updated: 2022/10/17 15:53:44 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**free_prev(char **p, int j)
{
	while (--j >= 0)
		free(p[j]);
	free(p);
	return (0);
}

static int	alloc_2d_size(char const *s, char c)
{
	int	i;
	int	notif;

	i = 0;
	notif = 0;
	while (*s)
	{
		if (*s != c && notif == 0)
		{
			notif = 1;
			i++;
		}
		else if (*s == c)
			notif = 0;
		s++;
	}
	return (i);
}

static char	**return_split(char const *s, char c, char **p)
{
	size_t		i;
	size_t		j;

	j = 0;
	while (*s)
	{
		i = 0;
		while (*s != c && *s)
		{
			i++;
			s++;
		}
		p[j] = ft_substr((s - i), 0, i);
		if (!p[j])
			return (free_prev(p, j));
		j++;
		while (*s == c && *s)
			s++;
	}
	return (p);
}

char	**ft_split(char const *s, char c)
{
	char	**p;
	int		i;

	if (!s)
		return (0);
	while (*s == c && *s)
		s++;
	i = alloc_2d_size(s, c);
	p = (char **)malloc(sizeof(char *) * (i + 1));
	if (!p)
		return (0);
	p[i] = NULL;
	return (return_split(s, c, p));
}
