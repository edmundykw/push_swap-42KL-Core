/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeen-wy <ekeen-wy@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 20:07:01 by ekeen-wy          #+#    #+#             */
/*   Updated: 2022/06/22 15:17:52 by ekeen-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_stack_var(t_stack_info *stack_i)
{
	stack_i -> stack_a = NULL;
	stack_i -> stack_b = NULL;
	stack_i -> target[ACT] = 0;
	stack_i -> target[YES] = 0;
	stack_i -> steps[TOP] = 0;
	stack_i -> steps[BOTTOM] = 0;
}

static void	create_stack_a(t_stack_info *stack_i)
{
	int		temp;
	t_list	*new;

	temp = 0;
	while (temp < stack_i -> array_size)
	{
		new = ft_lstnew(stack_i -> array_in[temp++]);
		if (new == NULL)
		{
			free_mem(stack_i);
			ft_lstclear(&stack_i -> stack_a);
			p_error("Malloc failed\n");
		}
		ft_lstadd_back(&stack_i -> stack_a, new);
	}
}

static void	init_stack(t_stack_info *stack_i)
{
	init_stack_var(stack_i);
	create_stack_a(stack_i);
}

static void	process_input(t_stack_info *stack_i, int argc, char **argv)
{
	check_input(argv);
	convert_input(stack_i, argc, argv);
	if (isdup(stack_i -> array_sorted, argc - 1))
	{
		free_mem(stack_i);
		p_error("Error\n");
	}
	if (!bubblesort(stack_i -> array_sorted, stack_i -> array_size))
	{
		free_mem(stack_i);
		exit(EXIT_SUCCESS);
	}
}

int	main(int argc, char **argv)
{
	t_stack_info	stack_i;

	if (argc == 1)
		return (0);
	process_input(&stack_i, argc, argv);
	init_stack(&stack_i);
	push_swap(&stack_i);
	free_mem(&stack_i);
	ft_lstclear(&stack_i.stack_a);
}
