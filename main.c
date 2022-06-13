/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeen-wy <ekeen-wy@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 20:07:01 by ekeen-wy          #+#    #+#             */
/*   Updated: 2022/06/12 21:59:41 by ekeen-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	p_error(int code)
{
	if (code == 0)
		ft_putstr_fd("Error\n", 2);
}

static int	isnumber(char *str)
{
	size_t	i;

	i = 0;
	if (str[i] == 0)
		return (0);
	if (str[i] == '-' && str[i + 1] != '\0')
		i++;
	else
		return (0);
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char**argv)
{
	if (argc < 2)
		p_error(0);
	else if (argc < 3 && isnumber == 0)
		return ;
}
