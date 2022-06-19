/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeen-wy <ekeen-wy@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 22:56:01 by ekeen-wy          #+#    #+#             */
/*   Updated: 2022/06/19 23:05:06 by ekeen-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_median(t_stack_info *stack_i, int idx)
{
	int	median;
	int	*arr;

	arr = stack_i -> array_sorted;
	median = arr[idx];
	return (median);
}

void	push_to_b(t_stack_info *stack_i, int median)
{
	size_t	i;
	t_list	*temp;

	i = 0;
	temp = stack_i -> stack_a;
	while (stack_i -> stack_a != NULL)
	{
		stack_i -> steps[TOP] += 1;
		if (temp -> content <= median)
		{
			
		}
		temp = temp -> next;
	}
}

void	sort_big(t_stack_info *stack_i, int part)
{
	int	median;
	int	idx;
	int	i;

	idx = stack_i -> array_size / part;
	i = 1;
	while (stack_i -> stack_a != NULL)
	{
		median = get_median(stack_i, (idx - 1) * i);
		i++;
	}
}
