/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeen-wy <ekeen-wy@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 20:08:20 by ekeen-wy          #+#    #+#             */
/*   Updated: 2022/06/14 21:46:27 by ekeen-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <limits.h>
# include "libft/libft.h"
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
	t_list	*stack_a;
	t_list	*stack_b;
}	t_stack_info;

/*s_ops.c*/
void	sa(t_stack_info *stack_info, int show);
void	sb(t_stack_info *stack_info, int show);
void	ss(t_stack_info *stack_info, int show);
#endif