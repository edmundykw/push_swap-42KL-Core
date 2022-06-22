/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeen-wy <ekeen-wy@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 18:13:08 by ekeen-wy          #+#    #+#             */
/*   Updated: 2022/06/22 14:16:53 by ekeen-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_mem(t_stack_info *stack_i)
{
	free(stack_i -> array_in);
	free(stack_i -> array_sorted);
}

void	check_min(t_stack_info *stack_i)
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
