/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeen-wy <ekeen-wy@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 20:07:01 by ekeen-wy          #+#    #+#             */
/*   Updated: 2022/06/14 13:31:51 by ekeen-wy         ###   ########.fr       */
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

static void	p_error(int code)
{
	if (code == 0)
	{
		ft_putstr_fd("Error\n", 2);
		exit(EXIT_FAILURE);
	}
	else if (code == 1)
	{
		ft_putstr_fd("Malloc error\n", 2);
		exit(EXIT_FAILURE);
	}
}

static int	isnumber(char *str)
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

static int	isdup(int *n, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	l;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j <= len)
		{
			if (n[i] == n[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

/*
Remember to fix the atoi to handle max and min integer conversions. 
I can check what I did using my printf.
*/

int	main(int argc, char **argv)
{
	int		*array_in;
	size_t	i;

	if (argc < 2)
		p_error(0);
	array_in = create_array(argc - 1);
	i = 1;
	while (argv[i] != NULL)
	{
		if (isnumber(argv[i]))
			p_error(0);
		else if (ft_atoi(argv[i]) > INT_MAX || ft_atoi(argv[i]) < INT_MIN)
			p_error(0);
		else
			array_in[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	if (isdup(array_in, argc - 1))
		p_error(0);
}
