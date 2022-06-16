/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeen-wy <ekeen-wy@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 17:56:54 by ekeen-wy          #+#    #+#             */
/*   Updated: 2022/06/16 18:23:32 by ekeen-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	p_error(int code)
{
	if (code == 0)
	{
		ft_putstr_fd("Error\n", 2);
		//exit(EXIT_FAILURE);
	}
	else if (code == 1)
	{
		ft_putstr_fd("Malloc error\n", 2);
		//exit(EXIT_FAILURE);
	}
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