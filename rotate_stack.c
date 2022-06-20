/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeen-wy <ekeen-wy@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 12:52:45 by ekeen-wy          #+#    #+#             */
/*   Updated: 2022/06/20 14:59:33 by ekeen-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_stack_info *stack_i)
{
	if (stack_i -> steps[TOP] < stack_i -> steps[BOTTOM])
		push_top(stack_i, ra, 1);
	else if (stack_i -> steps[TOP] > stack_i -> steps[BOTTOM])
		push_bot(stack_i, rra, 1);
	pb(stack_i, 1);
	stack_i -> steps[TOP] = 0;
	stack_i -> steps[BOTTOM] = 0;
	stack_i -> target[ACT] = 0;
	stack_i -> target[YES] = 0;
}

void	rotate_b(t_stack_info *stack_i)
{
	if (stack_i -> steps[TOP] < stack_i -> steps[BOTTOM])
		push_top(stack_i, rb, 1);
	else if (stack_i -> steps[TOP] > stack_i -> steps[BOTTOM])
		push_bot(stack_i, rrb, 1);
	pa(stack_i, 1);
	stack_i -> steps[TOP] = 0;
	stack_i -> steps[BOTTOM] = 0;
	stack_i -> target[ACT] = 0;
	stack_i -> target[YES] = 0;
}
