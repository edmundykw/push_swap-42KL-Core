/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeen-wy <ekeen-wy@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 13:06:28 by ekeen-wy          #+#    #+#             */
/*   Updated: 2022/06/20 17:39:17 by ekeen-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack_info *stack_i)
{
	int		n1;
	int		n2;
	int		n3;

	n1 = stack_i -> stack_a -> content;
	n2 = stack_i -> stack_a -> next -> content;
	n3 = stack_i -> stack_a -> next -> next -> content;
	if (n1 > n2 && n2 < n3 && n3 > n1)
		sa(stack_i, 1);
	else if (n1 > n2 && n2 > n3 && n1 > n3)
	{
		sa(stack_i, 1);
		rra(stack_i, 1);
	}
	else if (n1 > n2 && n2 < n3 && n1 > n3)
		ra(stack_i, 1);
	else if (n1 < n2 && n2 > n3 && n1 < n3)
	{
		sa(stack_i, 1);
		ra(stack_i, 1);
	}
	else if (n1 < n2 && n2 > n3 && n1 > n3)
		rra(stack_i, 1);
	else
		return ;
}

void	sort_five(t_stack_info *stack_i, int size)
{
	size_t	i;

	i = 1;
	while (i++ < size - 2)
	{
		check_min(stack_i);
		rotate_a(stack_i);
	}
	sort_three(stack_i);
	while (stack_i -> stack_b != NULL)
		pa(stack_i, 1);
}
