/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_ab_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeen-wy <ekeen-wy@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 12:13:59 by ekeen-wy          #+#    #+#             */
/*   Updated: 2022/06/15 17:03:55 by ekeen-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Shift up all elements of stack a by 1.
The first element becomes the last one. */

int	ra(t_stack_info *stack_info, int show)
{
	t_list	*temp;

	temp = stack_info -> stack_a -> next;
	if (stack_info -> stack_a != NULL)
	{
		ft_lstadd_back(&stack_info -> stack_a, stack_info -> stack_a);
		stack_info -> stack_a = temp;
	}
	else
		return (0);
	if (show)
		ft_putstr_fd("ra\n", 1);
	return (1);
}

/* Shift up all elements of stack b by 1.
The first element becomes the last one. */

int	rb(t_stack_info *stack_info, int show)
{
	t_list	*temp;

	temp = stack_info -> stack_b -> next;
	if (stack_info -> stack_b != NULL)
	{
		ft_lstadd_back(&stack_info -> stack_b, stack_info -> stack_b);
		stack_info -> stack_b = temp;
	}
	else
		return (0);
	if (show)
		ft_putstr_fd("rb\n", 1);
	return (1);
}

int	rr(t_stack_info *stack_info, int show)
{
	int	i;
	int	j;

	i = ra(stack_info, 0);
	j = rb(stack_info, 0);
	if (show && i && j)
	{
		ft_putstr_fd("rr\n", 1);
		return (1);
	}
	return (0);
}
