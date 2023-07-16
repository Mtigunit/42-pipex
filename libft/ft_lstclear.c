/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 17:18:47 by mtigunit          #+#    #+#             */
/*   Updated: 2022/10/14 17:18:49 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*curr;

	if (!lst)
		return ;
	while ((*lst))
	{
		curr = (*lst)->next;
		ft_lstdelone(*lst, del);
		(*lst) = curr;
	}
	lst = NULL;
}
