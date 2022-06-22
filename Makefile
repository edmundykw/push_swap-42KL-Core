# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ekeen-wy <ekeen-wy@student.42kl.edu.my>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/20 19:22:57 by ekeen-wy          #+#    #+#              #
#    Updated: 2022/06/22 15:08:21 by ekeen-wy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_PATH = libft

LIBFT = $(LIBFT_PATH)/libft.a

NAME := push_swap

CC := gcc

CFLAGS := -Wall -Wextra -Werror -g -fsanitize=address

DEPS := push_swap.h

SRC := main.c bubblesort.c process_input.c ops_p.c push_swap.c ops_r_ab.c \
	rotate_stack.c ops_rr_ab.c ops_s.c sort_big.c sort_small.c ops_stack.c \
	utils_1.c ops_array.c

OBJ := $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(DEPS) $(LIBFT) 
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $@

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@$(MAKE) --no-print-directory -C $(LIBFT_PATH)

fclean: clean
	rm -f $(NAME)
	
clean:
	@$(MAKE) --no-print-directory fclean -C libft
	rm -f $(OBJ)

re: fclean all

.PHONY: all clean fclean re