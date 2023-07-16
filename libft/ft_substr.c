/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 14:47:36 by mtigunit          #+#    #+#             */
/*   Updated: 2022/10/14 14:47:38 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;

	if (!s)
		return (0);
	if (start >= ft_strlen(s))
		return (ft_strdup("\0"));
	if (len > ft_strlen (&s[start]))
		len = ft_strlen (&s[start]);
	p = (char *)malloc(len + 1);
	if (!p)
		return (0);
	ft_strlcpy(p, &s[start], len + 1);
	return (p);
}
