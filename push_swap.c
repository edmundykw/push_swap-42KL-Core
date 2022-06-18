/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeen-wy <ekeen-wy@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 15:48:13 by ekeen-wy          #+#    #+#             */
/*   Updated: 2022/06/19 00:19:52 by ekeen-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print(t_stack_info *stack_i)
{
	t_list	*tempnode;
	t_list	*lst;

	lst = stack_i->stack_a;
	while (lst != NULL)
	{
		tempnode = lst;
		printf("%d\n", tempnode->content);
		lst = tempnode -> next;
	}
}

void	push_swap(t_stack_info *stack_i)
{
	if (stack_i->array_size == 2)
		sa(stack_i, 1);
	else if (stack_i->array_size == 3)
		sort_three(stack_i);
	else if (stack_i->array_size == 5)
		sort_five(stack_i);
}
