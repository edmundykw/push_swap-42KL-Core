/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeen-wy <ekeen-wy@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 21:58:45 by ekeen-wy          #+#    #+#             */
/*   Updated: 2022/06/18 22:07:44 by ekeen-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_top(t_stack_info *stack_i)
{
	while (stack_i -> steps[TOP] - 1 > 0)
	{
		ra(stack_i, 1);
		stack_i -> steps[TOP]--;
	}
}

void	push_bottom(t_stack_info *stack_i)
{
	while (stack_i -> steps[BOTTOM] > 0)
	{
		rra(stack_i, 1);
		stack_i -> steps[BOTTOM]--;
	}
}
