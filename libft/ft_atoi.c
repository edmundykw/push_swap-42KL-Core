/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeen-wy <ekeen-wy@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 16:46:52 by ekeen-wy          #+#    #+#             */
/*   Updated: 2022/02/10 14:51:08 by ekeen-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{	
	int	sign;
	int	base_conv;

	sign = 1;
	base_conv = 0;
	if (ft_strlen(str) == 0 || *str == '\e')
		return (base_conv);
	while ((*str != '+' && *str != '-') && (*str < '0' || *str > '9'))
	{
		if ((*str >= 'a' && *str <= 'z') || (*str >= 'A' && *str <= 'Z'))
			return (base_conv);
		str++;
	}
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9' && (*str != '\0'))
	{
		base_conv = base_conv * 10 + (*str - '0');
		str++;
	}
	return (base_conv * sign);
}
