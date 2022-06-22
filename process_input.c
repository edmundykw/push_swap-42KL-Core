/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeen-wy <ekeen-wy@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 17:56:54 by ekeen-wy          #+#    #+#             */
/*   Updated: 2022/06/22 15:18:37 by ekeen-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	p_error(char *str)
{
	ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
}

int	isnumber(char *str)
{
	size_t	i;

	i = 0;
	if (str[i] == 0)
		return (1);
	if (str[i] == '-' && str[i + 1] != '\0')
		i++;
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int	isdup(int *n, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (n[i] == n[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	check_input(char **argv)
{
	size_t	i;

	i = 1;
	while (argv[i] != NULL)
	{
		if (isnumber(argv[i]))
			p_error("Error\n");
		else if (ft_atoi(argv[i]) > INT_MAX || ft_atoi(argv[i]) < INT_MIN)
			p_error("Error\n");
		i++;
	}
}

void	convert_input(t_stack_info *stack_i, int argc, char **argv)
{
	size_t	i;

	init_array(stack_i, argc);
	i = 1;
	while (argv[i] != NULL)
	{
		stack_i -> array_in[i - 1] = ft_atoi(argv[i]);
		stack_i -> array_sorted[i - 1] = ft_atoi(argv[i]);
		i++;
	}
}
