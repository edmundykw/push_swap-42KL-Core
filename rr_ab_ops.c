/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_ab_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeen-wy <ekeen-wy@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 13:13:56 by ekeen-wy          #+#    #+#             */
/*   Updated: 2022/06/15 16:58:43 by ekeen-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Shift down all elements of stack a by 1.
The last element becomes the first one. */

int	rra(t_stack_info *stack_info, int show)
{
	t_list	*temp;
	t_list	*temp_2;

	temp = ft_lstlast(stack_info -> stack_a);
	temp_2 = ft_lstseclast(stack_info -> stack_a);
	if (stack_info -> stack_a != NULL)
	{
		ft_lstadd_front(&stack_info -> stack_a, temp);
		temp_2 -> next = NULL;
	}
	else
		return (0);
	if (show)
		printf("rra\n");
	return (1);
}
