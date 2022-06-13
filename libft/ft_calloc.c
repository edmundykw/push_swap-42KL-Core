/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeen-wy <ekeen-wy@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 12:35:29 by ekeen-wy          #+#    #+#             */
/*   Updated: 2022/03/10 15:23:20 by ekeen-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*ptr;
	unsigned long	i;
	unsigned int	j;

	i = nmemb * size;
	j = 0;
	if (i > __LONG_MAX__)
		return (NULL);
	ptr = (char *) malloc(i);
	if (ptr == NULL)
		return (NULL);
	if (nmemb == 0 || size == 0)
		return (ptr);
	while (j != i)
	{
		*(char *)(ptr + j) = 0;
		j++;
	}
	return (ptr);
}
