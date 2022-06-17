/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeen-wy <ekeen-wy@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 10:27:52 by ekeen-wy          #+#    #+#             */
/*   Updated: 2022/06/17 22:49:21 by ekeen-wy         ###   ########.fr       */
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

int	ft_lstsize(t_list *lst)
{
	int	len;

	len = 0;
	while (lst != NULL)
	{
		len++;
		lst = lst -> next;
	}
	return (len);
}

void	check_min(t_stack_info *stack_i)
{
	int		*min;
	size_t	i;
	t_list	*temp;

	min = stack_i->array_sorted;
	i = 0;
	while (i < stack_i->array_size - 1)
	{
		temp = stack_i->stack_a;
		while (temp != NULL)
		{
			if (min[i] == temp->content)
			{
				stack_i->steps[TOP] += 1;
				return ;
			}
			temp = temp->next;
		}
		i++;
	}
}
