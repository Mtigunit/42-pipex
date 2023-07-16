/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 12:01:03 by mtigunit          #+#    #+#             */
/*   Updated: 2022/10/14 12:01:05 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void		*dstp;
	const void	*srcp;

	if (dst > src)
	{
		dstp = dst + len - 1;
		srcp = src + len - 1;
		while (len > 0)
		{
			*(unsigned char *)dstp = *(unsigned char *)srcp;
			len--;
			srcp--;
			dstp--;
		}
	}
	else
		return (ft_memcpy(dst, src, len));
	return (dst);
}
