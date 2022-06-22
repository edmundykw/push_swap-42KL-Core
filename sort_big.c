/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeen-wy <ekeen-wy@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 22:56:01 by ekeen-wy          #+#    #+#             */
/*   Updated: 2022/06/22 17:07:51 by ekeen-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_pivot(t_stack_info *stack_i, int idx)
{
	int	pivot;
	int	*arr;

	arr = stack_i -> array_sorted;
	if (idx > stack_i -> array_size - 1)
		idx = stack_i -> array_size - 1;
	pivot = arr[idx];
	return (pivot);
}

static void	push_to_b(t_stack_info *stack_i, int pivot)
{
	int	*arr;

	arr = stack_i -> steps;
	while (stack_i -> stack_a != NULL)
	{
		find_from_top(stack_i, stack_i -> stack_a, pivot, 'a');
		find_from_bot(stack_i, stack_i -> stack_a, pivot);
		if (arr[TOP] == 0 && arr[BOTTOM] == 0)
			break ;
		if (stack_i -> steps[TOP] < stack_i -> steps[BOTTOM])
			rotate(stack_i, 0);
		else
			rotate(stack_i, 1);
	}
}

static void	push_to_a(t_stack_info *stack_i, int i)
{
	int		num_to_push;
	int		*arr;

	arr = stack_i -> steps;
	num_to_push = stack_i -> array_sorted[i];
	find_from_top(stack_i, stack_i -> stack_b, num_to_push, 'b');
	find_from_bot(stack_i, stack_i -> stack_b, num_to_push);
	if (arr[TOP] == 0 && arr[BOTTOM] == 0)
		return ;
	if (stack_i -> steps[TOP] < stack_i -> steps[BOTTOM])
		rotate(stack_i, 2);
	else
		rotate(stack_i, 3);
}

void	sort_big(t_stack_info *stack_i, int part)
{
	int	pivot;
	int	split;
	int	idx;
	int	i;

	split = stack_i -> array_size / part;
	i = 1;
	while (stack_i -> stack_a != NULL)
	{
		idx = (split * i) - 1;
		pivot = get_pivot(stack_i, idx);
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
