/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeen-wy <ekeen-wy@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 20:08:20 by ekeen-wy          #+#    #+#             */
/*   Updated: 2022/06/17 11:19:02 by ekeen-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <limits.h>
# include "libft/libft.h"
# include <stdio.h>
# define YES 1
# define NO 0

typedef struct d_linked_list {
	int						content;
	int						tail;
	struct d_linked_list	*next;
}	t_list;

typedef struct stack {
	int		counter_a;
	int		counter_b;
	int		*array_in;
	int		*array_sorted;
	int		array_size;
	t_list	*stack_a;
	t_list	*stack_b;
}	t_stack_info;

/* s_ops.c */
int		sa(t_stack_info *stack_info, int show);
int		sb(t_stack_info *stack_info, int show);
int		ss(t_stack_info *stack_info, int show);

/* p_ops.c */
void	pa(t_stack_info *stack_info, int show);
void	pb(t_stack_info *stack_info, int show);

/* r_ab_ops.c */
int		ra(t_stack_info *stack_info, int show);
int		rb(t_stack_info *stack_info, int show);
int		rr(t_stack_info *stack_info, int show);

/* rr_ab_ops.c */
int		rra(t_stack_info *stack_info, int show);
int		rrb(t_stack_info *stack_info, int show);
int		rrr(t_stack_info *stack_info, int show);

/* utils_1.c */
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstseclast(t_list *lst);
t_list	*ft_lstnew(int content);

/* utils_2.c */
void	ft_lstclear(t_list **lst);
void	free_mem(t_stack_info *stack_i);

/* error_check.c */
void	p_error(int code);
int		isnumber(char *str);
int		isdup(int *n, size_t len);

/* bubblesort.c */
int		bubblesort(int *arr, size_t size);

/* push_swap.c */
void	push_swap(t_stack_info *stack_i);
#endif