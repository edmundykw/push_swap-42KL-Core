/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeen-wy <ekeen-wy@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 18:13:08 by ekeen-wy          #+#    #+#             */
/*   Updated: 2022/06/20 14:56:24 by ekeen-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* finds the second last node in the linked list */

t_list	*ft_lstseclast(t_list *lst)
{
	t_list	*ptr;

	ptr = lst;
	while (ptr != NULL)
	{
		if (ptr -> next -> next == NULL)
			return (ptr);
		ptr = ptr -> next;
	}
	return (ptr);
}

void	free_mem(t_stack_info *stack_i)
{
	free(stack_i -> array_in);
	free(stack_i -> array_sorted);
}

void	check_min(t_stack_info *stack_i)
{
	int		*min;
	size_t	i;
	t_list	*temp;

	min = stack_i -> array_sorted;
	i = 0;
	while (i < stack_i -> array_size - 1)
	{
		temp = stack_i -> stack_a;
		stack_i -> steps[TOP] = 0;
		while (temp != NULL)
		{
			stack_i -> steps[TOP] += 1;
			if (min[i] == temp -> content)
			{
				i = stack_i -> array_size;
				break ;
			}
			temp = temp -> next;
		}
		i++;
	}
	stack_i -> steps[BOTTOM] = ft_lstsize(stack_i -> stack_a)
		- stack_i -> steps[TOP] + 1;
}
