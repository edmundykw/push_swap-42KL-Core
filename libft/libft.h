/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeen-wy <ekeen-wy@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 12:32:20 by ekeen-wy          #+#    #+#             */
/*   Updated: 2022/06/19 22:10:48 by ekeen-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# define YES 1
# define NO 0

int		ft_isdigit(int c);
size_t	ft_strlen(const char *str);
long	ft_atoi(const char *str);
void	ft_putstr_fd(char *s, int fd);

typedef struct d_linked_list {
	int						content;
	int						tail;
	struct d_linked_list	*next;
}	t_list;

t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstnew(int content);
size_t	ft_lstsize(t_list *lst);
void	ft_lstclear(t_list **lst);
#endif
