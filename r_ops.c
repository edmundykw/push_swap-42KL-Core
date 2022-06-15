/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_ops.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeen-wy <ekeen-wy@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 12:13:59 by ekeen-wy          #+#    #+#             */
/*   Updated: 2022/06/15 12:55:05 by ekeen-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Shift up all elements of stack a by 1.
The first element becomes the last one. */

int	ra(t_stack_info *stack_info, int show)
{
	t_list	*top;
	t_list	*temp;

	top = stack_info -> stack_a;
	temp = top -> next;
	if (top != NULL)
	{
		ft_lstadd_back(&top, top);
		stack_info -> stack_a = temp;
	}
	else
		return (0);
	if (show)
		ft_putstr_fd("sa\n", 1);
	return (1);
}
