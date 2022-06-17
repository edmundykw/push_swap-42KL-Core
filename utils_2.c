/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeen-wy <ekeen-wy@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 10:27:52 by ekeen-wy          #+#    #+#             */
/*   Updated: 2022/06/17 10:58:50 by ekeen-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	free_mem(t_stack_info *stack_i)
{
	free(stack_i->array_in);
	free(stack_i->array_sorted);
}
