/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeen-wy <ekeen-wy@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 20:07:01 by ekeen-wy          #+#    #+#             */
/*   Updated: 2022/06/16 23:13:16 by ekeen-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

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
	int	temp;

	stack_i->counter_a = 0;
	stack_i->counter_b = 0;
	stack_i->stack_a = NULL;
	stack_i->stack_b = NULL;
	temp = 0;
	while (temp < stack_i->array_size)
		ft_lstadd_back(&stack_i->stack_a, ft_lstnew(stack_i->array_in[temp++]));
}

/*
Check if it's already arranged then no need to run the sorting.
*/
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

int	main(int argc, char **argv)
{
	t_stack_info	stack_i;
	size_t			i;

	if (argc < 2)
	{
		p_error(0);
		ft_putstr_fd("I am the culprit\n", 1);
	}
	init_array(&stack_i, argc);
	i = 1;
	while (argv[i] != NULL)
	{
		if (isnumber(argv[i]))
		{
			p_error(0);
			ft_putstr_fd("It's me 1\n", 1);
		}
		else if (ft_atoi(argv[i]) > INT_MAX || ft_atoi(argv[i]) < INT_MIN)
		{
			p_error(0);
			ft_putstr_fd("It's me 2\n", 1);
		}
		else
		{
			stack_i.array_in[i - 1] = ft_atoi(argv[i]);
			stack_i.array_sorted[i - 1] = ft_atoi(argv[i]);
		}
		i++;
	}
	if (isdup(stack_i.array_in, argc - 1))
	{
		p_error(0);
		ft_putstr_fd("It's a dup\n", 1);
	}
	init_stack(&stack_i);
	push_swap(&stack_i);
}
