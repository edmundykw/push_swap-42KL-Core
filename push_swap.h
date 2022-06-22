/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeen-wy <ekeen-wy@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 20:08:20 by ekeen-wy          #+#    #+#             */
/*   Updated: 2022/06/22 15:18:04 by ekeen-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# define TOP 0
# define BOTTOM 1
# define ACT 0
# define YES 1

typedef struct stack {
	int		*array_in;
	int		*array_sorted;
	int		array_size;
	int		steps[2];
	int		target[2];
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
void	free_mem(t_stack_info *stack_i);
void	check_min(t_stack_info *stack_i);

/* ops_array.c */
int		*create_array(int n);
void	init_array(t_stack_info *stack_i, int argc);

/* process_input.c */
void	p_error(char *str);
int		isnumber(char *str);
int		isdup(int *n, size_t len);
void	check_input(char **argv);
void	convert_input(t_stack_info *stack_i, int argc, char **argv);

/* bubblesort.c */
int		bubblesort(int *arr, size_t size);

/* push_swap.c */
void	push_swap(t_stack_info *stack_i);

/* sort_small.c */
void	sort_three(t_stack_info *stack_i);
void	sort_five(t_stack_info *stack_i, int size);

/* sort_big.c */
void	sort_big(t_stack_info *stack_i, int part);

/* stack_ops.c */
void	push_top(t_stack_info *stack_i,
			int (*f)(t_stack_info *s, int i), int j);
void	push_bot(t_stack_info *stack_i,
			int (*f)(t_stack_info *s, int i), int j);
void	find_from_top_a(t_stack_info *stack_i, t_list *s, int pivot);
void	find_from_top_b(t_stack_info *stack_i, t_list *s, int pivot);
void	find_from_bot(t_stack_info *stack_i, t_list *s, int pivot);

/* rotate_stack.c */
void	rotate_a(t_stack_info *stack_i);
void	rotate_b(t_stack_info *stack_i);
#endif