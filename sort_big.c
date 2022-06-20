/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeen-wy <ekeen-wy@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 22:56:01 by ekeen-wy          #+#    #+#             */
/*   Updated: 2022/06/20 15:00:04 by ekeen-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_pivot(t_stack_info *stack_i, int idx)
{
	int	pivot;
	int	*arr;

	arr = stack_i -> array_sorted;
	pivot = arr[idx];
	return (pivot);
}

static void	push_to_b(t_stack_info *stack_i, int pivot)
{
	int	*arr;
	int	i;

	arr = stack_i -> steps;
	i = 1;
	while (stack_i -> stack_a != NULL)
	{
		find_from_top(stack_i, stack_i -> stack_a, pivot);
		find_from_bot(stack_i, stack_i -> stack_a, pivot);
		if (arr[TOP] == 0 && arr[BOTTOM] == 0)
			break ;
		rotate_a(stack_i);
	}
}

static void	push_to_a(t_stack_info *stack_i, int i)
{
	int		num_to_push;
	t_list	*node;
	int		*arr;

	arr = stack_i -> steps;
	num_to_push = stack_i -> array_sorted[i];
	node = stack_i -> stack_b;
	find_from_top(stack_i, node, num_to_push);
	find_from_bot(stack_i, node, num_to_push);
	if (arr[TOP] == 0 && arr[BOTTOM] == 0)
		return ;
	rotate_b(stack_i);
}

void	sort_big(t_stack_info *stack_i, int part)
{
	int	pivot;
	int	idx;
	int	i;

	idx = stack_i -> array_size / part;
	i = 1;
	while (stack_i -> stack_a != NULL)
	{
		pivot = get_pivot(stack_i, (idx - 1) * i);
		push_to_b(stack_i, pivot);
		i++;
	}
	idx = stack_i -> array_size - 1;
	while (stack_i -> stack_b != NULL)
	{
		push_to_a(stack_i, idx);
		idx--;
	}
}
