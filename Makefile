# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: femorell <femorell@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/27 13:47:34 by femorell          #+#    #+#              #
#    Updated: 2023/04/28 14:51:42 by femorell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

BONUS = checker

LIBFT = libft/libft.a

FLAGS = -Wall -Werror -Wextra -g

SRCS := srcs/push_swap.c\
	srcs/stack_init.c\
	srcs/stack_utils.c\
	srcs/check.c\
	srcs/utils.c\
	srcs/parsing.c\
	srcs/sort_utils.c\
	srcs/sort_utils2.c\
	srcs/sort_utils3.c \
	srcs/get_mid.c\
	srcs/sort_a.c\
	srcs/sort_b.c\
	srcs/small_sort.c\
	srcs/small_count_sort.c

SRCS_BONUS := srcs_bonus/checker.c\
	srcs_bonus/stack_init.c\
	srcs_bonus/stack_utils.c\
	srcs_bonus/check.c\
	srcs_bonus/utils.c\
	srcs_bonus/parsing.c\
	srcs_bonus/sort_utils.c\
	srcs_bonus/sort_utils2.c\
	srcs_bonus/sort_utils3.c \
	srcs_bonus/get_next_line_bonus.c
	
OBJ = $(SRCS:.c=.o)

OBJ_B = $(SRCS_BONUS:.c=.o)

all: $(NAME)

$(NAME): libcomp comp;

bonus: libcomp $(OBJ_B)
	gcc $(FLAGS) $(OBJ_B) $(LIBFT) -o $(BONUS)

libcomp:
		@make -C libft
	
comp: $(OBJ)
	gcc $(FLAGS) $(OBJ) $(LIBFT) -o $(NAME)
            
libclean:
		@make clean -C libft
		
clean:		libclean
	rm -rf $(OBJ)
	rm -rf $(OBJ_B)

libfclean:
		@make fclean -C libft

fclean:   	clean libfclean
		rm -rf $(NAME) $(BONUS)
		
re: clean all

.PHONY: all re clean fclean bonus

.SILENT:
