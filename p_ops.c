/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_ops.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeen-wy <ekeen-wy@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 21:41:07 by ekeen-wy          #+#    #+#             */
/*   Updated: 2022/06/15 11:48:42 by ekeen-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty. */

void	pa(t_stack_info *stack_info, int show)
{
	t_list	*top_a;
	t_list	*top_b;
	t_list	*temp_b;

	top_a = stack_info -> stack_a;
	top_b = stack_info -> stack_b;
	temp_b = top_b -> next;
	if (top_b != NULL)
	{
		top_b -> next = top_a;
		stack_info -> stack_a = top_b;
		stack_info -> stack_b = temp_b;
	}
	else
		return ;
	if (show)
		ft_putstr_fd("pa\n", 1);
}

/* Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty. */

void	pb(t_stack_info *stack_info, int show)
{
	t_list	*top_a;
	t_list	*top_b;
	t_list	*temp_a;

	top_a = stack_info -> stack_a;
	top_b = stack_info -> stack_b;
	temp_a = top_a -> next;
	if (top_a != NULL)
	{
		top_a -> next = top_b;
		stack_info -> stack_b = top_a;
		stack_info -> stack_a = temp_a;
	}
	else
		return ;
	if (show)
		ft_putstr_fd("pb\n", 1);
}
