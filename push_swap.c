/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeen-wy <ekeen-wy@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 15:48:13 by ekeen-wy          #+#    #+#             */
/*   Updated: 2022/06/20 21:31:54 by ekeen-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack_info *stack_i)
{
	int	size;

	size = stack_i -> array_size;
	if (size == 2)
		sa(stack_i, 1);
	else if (size == 3)
		sort_three(stack_i);
	else if (size <= 10)
		sort_five(stack_i, stack_i -> array_size);
	else if (size <= 100)
		sort_big(stack_i, 4);
	else
		sort_big(stack_i, 10);
}
