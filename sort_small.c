/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeen-wy <ekeen-wy@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 13:06:28 by ekeen-wy          #+#    #+#             */
/*   Updated: 2022/06/22 17:21:15 by ekeen-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_min(t_stack_info *stack_i)
{
	size_t	i;
	size_t	acts;
	t_list	*temp;

	i = 0;
	while (i < (size_t) stack_i -> array_size - 1)
	{
		temp = stack_i -> stack_a;
		stack_i -> steps[TOP] = 0;
		acts = 0;
		while (temp != NULL)
		{
			if (stack_i -> array_sorted[i] == temp -> content)
			{
				stack_i -> steps[TOP] = acts;
				i = stack_i -> array_size;
				break ;
			}
			temp = temp -> next;
			acts++;
		}
		i++;
	}
	stack_i -> steps[BOTTOM] = ft_lstsize(stack_i -> stack_a)
		- stack_i -> steps[TOP];
}

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
	int	i;

	i = 1;
	while (i++ < size - 2)
	{
		check_min(stack_i);
		if (stack_i -> steps[TOP] < stack_i -> steps[BOTTOM])
			rotate(stack_i, 0);
		else
			rotate(stack_i, 1);
	}
	sort_three(stack_i);
	while (stack_i -> stack_b != NULL)
		pa(stack_i, 1);
}
