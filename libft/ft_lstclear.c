/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeen-wy <ekeen-wy@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 20:59:04 by ekeen-wy          #+#    #+#             */
/*   Updated: 2022/06/19 22:08:50 by ekeen-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*tempnode;

	while (*lst != NULL)
	{
		tempnode = *lst;
		*lst = tempnode -> next;
		free(tempnode);
	}
	*lst = NULL;
}
