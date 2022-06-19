/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeen-wy <ekeen-wy@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 20:08:20 by ekeen-wy          #+#    #+#             */
/*   Updated: 2022/06/19 22:24:11 by ekeen-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <fcntl.h>
# include "libft/libft.h"
# include <stdio.h> /* to remove this */
# define TOP 0
# define BOTTOM 1

typedef struct stack {
	int		counter_a;
	int		counter_b;
	int		*array_in;
	int		*array_sorted;
	int		array_size;
	int		steps[2];
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
t_list	*ft_lstseclast(t_list *lst);
void	free_mem(t_stack_info *stack_i);
void	check_min(t_stack_info *stack_i);

/* utils_2.c */

/* error_check.c */
void	p_error(int code);
int		isnumber(char *str);
int		isdup(int *n, size_t len);

/* bubblesort.c */
int		bubblesort(int *arr, size_t size);

/* push_swap.c */
void	push_swap(t_stack_info *stack_i);

/* sort_small.c */
void	sort_three(t_stack_info *stack_i);
void	sort_five(t_stack_info *stack_i);

/* sort_big.c */
void	sort_big(t_stack_info *stack_i, int part);

/* stack_ops.c */
void	push_top(t_stack_info *stack_i,
			int (*f)(t_stack_info *s, int i), int j);
void	push_bot(t_stack_info *stack_i,
			int (*f)(t_stack_info *s, int i), int j);
#endif