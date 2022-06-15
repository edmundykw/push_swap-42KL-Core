/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_ops.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeen-wy <ekeen-wy@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 18:28:46 by ekeen-wy          #+#    #+#             */
/*   Updated: 2022/06/15 16:44:33 by ekeen-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Swap the first 2 elements at the top of stack a.
Do nothing if there is only one or no elements. */

int	sa(t_stack_info *stack_info, int show)
{
	t_list	*top;
	t_list	*temp;

	top = stack_info -> stack_a;
	if (top != NULL)
	{
		if (top -> next != NULL)
		{
			temp = top -> next;
			top -> next = temp -> next;
			temp -> next = top;
			stack_info -> stack_a = temp;
		}
		else
			return (0);
	}
	else
		return (0);
	if (show)
		ft_putstr_fd("sa\n", 1);
	return (1);
}

/* Swap the first 2 elements at the top of stack b.
Do nothing if there is only one or no elements. */

int	sb(t_stack_info *stack_info, int show)
{
	t_list	*top;
	t_list	*temp;

	top = stack_info -> stack_b;
	if (top != NULL)
	{
		if (top -> next != NULL)
		{
			temp = top -> next;
			top -> next = temp -> next;
			temp -> next = top;
			stack_info -> stack_b = temp;
		}
		else
			return (0);
	}
	else
		return (0);
	if (show)
		ft_putstr_fd("sb\n", 1);
	return (1);
}

int	ss(t_stack_info *stack_info, int show)
{
	int	i;
	int	j;

	i = sa(stack_info, 0);
	j = sb(stack_info, 0);
	if (show && i && j)
	{
		ft_putstr_fd("ss\n", 1);
		return (1);
	}
	return (0);
}
