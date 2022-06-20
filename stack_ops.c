/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeen-wy <ekeen-wy@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 21:58:45 by ekeen-wy          #+#    #+#             */
/*   Updated: 2022/06/20 18:40:49 by ekeen-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_top(t_stack_info *stack_i, int (*f)(t_stack_info *s, int i), int j)
{
	while (stack_i -> steps[TOP] > 0)
	{
		(*f)(stack_i, j);
		stack_i -> steps[TOP]--;
	}
}

void	push_bot(t_stack_info *stack_i, int (*f)(t_stack_info *s, int i), int j)
{
	while (stack_i -> steps[BOTTOM] > 0)
	{
		(*f)(stack_i, j);
		stack_i -> steps[BOTTOM]--;
	}
}

void	find_from_top_a(t_stack_info *stack_i, t_list *s, int pivot)
{
	size_t	i;
	size_t	size;	
	t_list	*temp;

	i = 0;
	size = ft_lstsize(s);
	temp = s;
	while (temp != NULL)
	{
		stack_i -> steps[TOP] = i;
		if (temp -> content <= pivot)
			break ;
		temp = temp -> next;
		i++;
	}
	if (i == size)
	{
		stack_i -> steps[TOP] = 0;
		stack_i -> steps[BOTTOM] = 0;
	}
}

void	find_from_top_b(t_stack_info *stack_i, t_list *s, int pivot)
{
	size_t	i;
	size_t	size;	
	t_list	*temp;

	i = 0;
	size = ft_lstsize(s);
	temp = s;
	while (temp != NULL)
	{
		stack_i -> steps[TOP] = i;
		if (temp -> content == pivot)
			break ;
		temp = temp -> next;
		i++;
	}
	if (i == size)
	{
		stack_i -> steps[TOP] = 0;
		stack_i -> steps[BOTTOM] = 0;
	}
}

/* find_from_bot is to check if a number within the specified
pivot range exists from the bottom of the stack. It will the 
steps required to push this number to stack b. The target[2] 
array is to keep track of the existence of such number. Index 0
to keep track of the steps required. Index 1 to indicate the
existing of such number. */

void	find_from_bot(t_stack_info *stack_i, t_list *s, int pivot)
{
	t_list	*temp;
	size_t	size;
	size_t	i;

	size = ft_lstsize(s);
	temp = s;
	i = 0;
	while (temp != NULL)
	{
		if (temp -> content <= pivot)
		{
			stack_i -> target[ACT] = i;
			stack_i -> target[YES] = 1;
		}
		temp = temp -> next;
		i++;
	}
	if (stack_i -> steps[TOP] == 0 && stack_i -> target[YES] == 0)
		stack_i -> steps[BOTTOM] = 0;
	else
		stack_i -> steps[BOTTOM] = size - stack_i -> steps[TOP];
}
