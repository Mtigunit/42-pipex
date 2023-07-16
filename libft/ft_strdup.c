/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 14:41:50 by mtigunit          #+#    #+#             */
/*   Updated: 2022/10/14 14:41:52 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*p;
	int		i;

	i = ft_strlen(s1);
	p = (char *)malloc(i + 1);
	if (!p)
		return (0);
	ft_memcpy(p, s1, i);
	p[i] = '\0';
	return (p);
}
