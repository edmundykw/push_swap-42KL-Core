/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeen-wy <ekeen-wy@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 18:13:08 by ekeen-wy          #+#    #+#             */
/*   Updated: 2022/06/15 16:54:35 by ekeen-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* finds the last node in the linked list */

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*ptr;

	ptr = lst;
	while (ptr != NULL)
	{
		if (ptr -> next == NULL)
			return (ptr);
		ptr = ptr -> next;
	}
	return (ptr);
}

/* places the node at the end of the linked list */

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ptr;

	if (*lst == NULL)
	{
		*lst = new;
		new -> next = NULL;
	}
	else
	{
		ptr = ft_lstlast(*lst);
		ptr -> next = new;
		new -> next = NULL;
	}
}

/* places the ith node at the front of the node specified */

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new -> next = *lst;
	*lst = new;
}

/* finds the second last node in the linked list */
t_list	*ft_lstseclast(t_list *lst)
{
	t_list	*ptr;

	ptr = lst;
	while (ptr != NULL)
	{
		if (ptr -> next -> next == NULL)
			return (ptr);
		ptr = ptr -> next;
	}
	return (ptr);
}
