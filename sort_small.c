/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeen-wy <ekeen-wy@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 13:06:28 by ekeen-wy          #+#    #+#             */
/*   Updated: 2022/06/17 22:03:49 by ekeen-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack_info *stack_i)
{
	int	n1;
	int	n2;
	int	n3;

	n1 = stack_i->array_in[0];
	n2 = stack_i->array_in[1];
	n3 = stack_i->array_in[2];
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
	else
		rra(stack_i, 1);
}

void	sort_five(t_stack_info *stack_i)
{
	size_t	i;
	t_list	*temp_b;
	t_list	*temp_a;

	i = 1;
	while (i++ < 3)
		pb(stack_i, 1);
	temp_b = stack_i->stack_b;
	if (temp_b->content < temp_b->next->content)
		sb(stack_i, 1);
	sort_three(stack_i);
	temp_a = stack_i->stack_a;
	while (temp_b != NULL)
	{
		if (temp_b->content > temp_a->content)
			stack_i->steps[TOP] += 1;
		if (temp_a->next == NULL)
			temp_a = stack_i->stack_a;
		temp_a = temp_a->next;
	}
}
