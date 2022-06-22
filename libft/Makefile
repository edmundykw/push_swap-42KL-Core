# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ekeen-wy <ekeen-wy@student.42kl.edu.my>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/15 10:06:07 by ekeen-wy          #+#    #+#              #
#    Updated: 2022/06/22 17:33:23 by ekeen-wy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libft.a 

CC := gcc

CFLAGS := -Wall -Wextra -Werror -g -fsanitize=address

DEPS := libft.h

SRC := ft_isdigit.c ft_strlen.c ft_atoi.c ft_putstr_fd.c ft_lstnew.c \
	  ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
	  ft_lstclear.c


OBJ := $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(DEPS)
	@ar csr $@ $?
	@echo "libft compiled"

fclean: clean 
	@rm -f $(NAME)
	@echo "removed libft!"

clean:
	@rm -f $(OBJ)

re: fclean all

.PHONY: all clean fclean re
