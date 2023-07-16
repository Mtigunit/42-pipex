/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 15:49:12 by mtigunit          #+#    #+#             */
/*   Updated: 2022/10/14 15:49:17 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	alloc_size(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i = 1;
	while (n > 0 || n < 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*p;
	int		i;
	int		j;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	j = 0;
	if (n < 0)
		j = 1;
	i = alloc_size(n);
	p = (char *)malloc(i + 1);
	if (!p)
		return (0);
	p[i--] = '\0';
	if (n < 0)
	{
		p[0] = '-';
		n = -n;
	}
	while (i >= j)
	{
		p[i--] = "0123456789"[n % 10];
		n = n / 10;
	}
	return (p);
}
