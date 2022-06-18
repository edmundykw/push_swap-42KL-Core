/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeen-wy <ekeen-wy@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 13:06:28 by ekeen-wy          #+#    #+#             */
/*   Updated: 2022/06/18 22:02:37 by ekeen-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack_info *stack_i)
{
	t_list	*temp;
	int		n1;
	int		n2;
	int		n3;

	temp = stack_i->stack_a;
	n1 = temp->content;
	n2 = temp->next->content;
	n3 = temp->next->next->content;
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
}

void	sort_five(t_stack_info *stack_i)
{
	size_t	i;

	i = 1;
	while (i++ < 3)
	{
		check_min(stack_i);
		if (stack_i -> steps[TOP] < stack_i -> steps[BOTTOM])
			push_top(stack_i);
		else
			push_bottom(stack_i);
		pb(stack_i, 1);
		stack_i -> steps[TOP] = 0;
		stack_i -> steps[BOTTOM] = 0;
	}
	sort_three(stack_i);
	while (stack_i -> stack_b != NULL)
		pa(stack_i, 1);
}
