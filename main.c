/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeen-wy <ekeen-wy@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 20:07:01 by ekeen-wy          #+#    #+#             */
/*   Updated: 2022/06/20 19:05:15 by ekeen-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*create_array(int n)
{
	int	*copy;

	copy = (int *)malloc(sizeof(int) * n);
	if (copy == NULL)
		p_error(1);
	return (copy);
}

static void	init_array(t_stack_info *stack_i, int argc)
{
	stack_i->array_in = create_array(argc - 1);
	stack_i->array_sorted = create_array(argc - 1);
	stack_i->array_size = argc - 1;
}

static void	init_stack(t_stack_info *stack_i)
{
	int		temp;
	t_list	*new;

	stack_i -> stack_a = NULL;
	stack_i -> stack_b = NULL;
	stack_i -> target[ACT] = 0;
	stack_i -> target[YES] = 0;
	stack_i -> steps[TOP] = 0;
	stack_i -> steps[BOTTOM] = 0;
	temp = 0;
	while (temp < stack_i->array_size)
	{
		new = ft_lstnew(stack_i -> array_in[temp++]);
		if (new == NULL)
		{
			free_mem(stack_i);
			ft_lstclear(&stack_i -> stack_a);
			p_error(1);
		}
		ft_lstadd_back(&stack_i -> stack_a, new);
	}
}

static void	process_input(t_stack_info *stack_i, char **argv)
{
	size_t	i;

	i = 1;
	while (argv[i] != NULL)
	{
		if (isnumber(argv[i]))
			p_error(0);
		else if (ft_atoi(argv[i]) > INT_MAX || ft_atoi(argv[i]) < INT_MIN)
			p_error(0);
		else
		{
			stack_i->array_in[i - 1] = ft_atoi(argv[i]);
			stack_i->array_sorted[i - 1] = ft_atoi(argv[i]);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_stack_info	stack_i;
	size_t			i;

	if (argc == 1)
		return (0);
	if (argc < 2)
		p_error(0);
	init_array(&stack_i, argc);
	process_input(&stack_i, argv);
	if (isdup(stack_i.array_in, argc - 1))
	{
		free_mem(&stack_i);
		p_error(0);
	}
	if (bubblesort(stack_i.array_sorted, stack_i.array_size) == 0)
	{
		free_mem(&stack_i);
		return (0);
	}
	init_stack(&stack_i);
	push_swap(&stack_i);
	free_mem(&stack_i);
	ft_lstclear(&stack_i.stack_a);
}
