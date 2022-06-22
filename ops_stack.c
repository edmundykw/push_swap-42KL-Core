/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeen-wy <ekeen-wy@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 21:58:45 by ekeen-wy          #+#    #+#             */
/*   Updated: 2022/06/22 17:09:00 by ekeen-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_push(t_stack_info *stack_i,
		int (*f)(t_stack_info *s, int i), char c)
{
	int	count;

	if (c == 't')
		count = stack_i -> steps[TOP];
	else
		count = stack_i -> steps[BOTTOM];
	while (count-- > 0)
		(*f)(stack_i, 1);
}

void	find_from_top(t_stack_info *stack_i, t_list *s, int pivot, char c)
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
		if (c == 'a')
			if (temp -> content <= pivot)
				break ;
		else if (c == 'b')
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

void	rotate(t_stack_info *stack_i, int i)
{
	static int	(*f_action[])(t_stack_info *stack_info, int show) = {
		&ra, &rra, &rb, &rrb};

	if (i == 0 || i == 2)
		rotate_push(stack_i, f_action[i], 't');
	else if (i == 1 || i == 3)
		rotate_push(stack_i, f_action[i], 'b');
	if (i < 2)
		pb(stack_i, 1);
	else
		pa(stack_i, 1);
	stack_i -> steps[TOP] = 0;
	stack_i -> steps[BOTTOM] = 0;
	stack_i -> target[ACT] = 0;
	stack_i -> target[YES] = 0;
}
