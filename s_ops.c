/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_ops.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeen-wy <ekeen-wy@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 18:28:46 by ekeen-wy          #+#    #+#             */
/*   Updated: 2022/06/14 22:06:45 by ekeen-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack_info *stack_info, int show)
{
	t_list	*top;
	t_list	*temp;

	top = stack_info -> stack_a;
	if (top != NULL)
	{
		if (top -> next != NULL)
		{
			temp = top -> next;
			top -> next = temp -> next;
			temp -> next = top;
			stack_info -> stack_a = temp;
		}
	}
	else
		return ;
	if (show)
		ft_putstr_fd("sa\n", 1);
}

void	sb(t_stack_info *stack_info, int show)
{
	t_list	*top;
	t_list	*temp;

	top = stack_info -> stack_b;
	if (top != NULL)
	{
		if (top -> next != NULL)
		{
			temp = top -> next;
			top -> next = temp -> next;
			temp -> next = top;
			stack_info -> stack_b = temp;
		}
	}
	else
		return ;
	if (show)
		ft_putstr_fd("sb\n", 1);
}
/* what if sa sb is empty and ss is called? */

void	ss(t_stack_info *stack_info, int show)
{
	sa(stack_info, 0);
	sb(stack_info, 0);
	if (show)
		ft_putstr_fd("ss\n", 1);
}
