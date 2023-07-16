/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 15:38:50 by mtigunit          #+#    #+#             */
/*   Updated: 2022/10/14 15:38:52 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		len;
	char	*p;

	if (!s1 || !set)
		return (0);
	len = ft_strlen(s1) - 1;
	while (len > 0 && ft_strchr(set, s1[len]))
		len--;
	while (len >= 0 && *s1 && ft_strchr(set, *s1))
	{
		s1++;
		len--;
	}
	len++;
	p = (char *)malloc(len + 1);
	if (!p)
		return (0);
	p[len] = '\0';
	ft_memcpy(p, s1, len);
	return (p);
}
