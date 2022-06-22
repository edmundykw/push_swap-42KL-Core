/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_array.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeen-wy <ekeen-wy@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:59:35 by ekeen-wy          #+#    #+#             */
/*   Updated: 2022/06/22 15:00:10 by ekeen-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*create_array(int n)
{
	int	*copy;

	copy = (int *)malloc(sizeof(int) * n);
	if (copy == NULL)
		p_error("Malloc failed\n");
	return (copy);
}

void	init_array(t_stack_info *stack_i, int argc)
{
	stack_i -> array_in = create_array(argc - 1);
	stack_i -> array_sorted = create_array(argc - 1);
	stack_i -> array_size = argc - 1;
}
