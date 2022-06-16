/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_ab_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeen-wy <ekeen-wy@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 13:13:56 by ekeen-wy          #+#    #+#             */
/*   Updated: 2022/06/16 18:10:08 by ekeen-wy         ###   ########.fr       */
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
		ft_putstr_fd("rra\n", 1);
	return (1);
}

/* Shift down all elements of stack b by 1.
The last element becomes the first one. */

int	rrb(t_stack_info *stack_info, int show)
{
	t_list	*temp;
	t_list	*temp_2;

	temp = ft_lstlast(stack_info -> stack_b);
	temp_2 = ft_lstseclast(stack_info -> stack_b);
	if (stack_info -> stack_b != NULL)
	{
		ft_lstadd_front(&stack_info -> stack_b, temp);
		temp_2 -> next = NULL;
	}
	else
		return (0);
	if (show)
		ft_putstr_fd("rrb\n", 1);
	return (1);
}

int	rrr(t_stack_info *stack_info, int show)
{
	int	i;
	int	j;

	i = rra(stack_info, 0);
	j = rrb(stack_info, 0);
	if (show && i && j)
	{
		ft_putstr_fd("rrr\n", 1);
		return (1);
	}
	return (0);
}
