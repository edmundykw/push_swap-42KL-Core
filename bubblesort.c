/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubblesort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeen-wy <ekeen-wy@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 14:09:38 by ekeen-wy          #+#    #+#             */
/*   Updated: 2022/06/16 19:58:41 by ekeen-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(int* i, int* j)
{
    int temp;
	
	temp = *i;
    *i = *j;
    *j = temp;
}

void	bubblesort(int *arr, size_t size)
{
    int		i;
	int		j;

	i = 0;
    while ( i < size - 1)
	{
		j = 0;
        while (j < size - 1)
		{
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
			j++;
		}
		i++;
	}
}