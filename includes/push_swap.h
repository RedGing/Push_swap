/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femorell <femorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 10:23:28 by femorell          #+#    #+#             */
/*   Updated: 2023/05/02 12:09:47 by femorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"

typedef struct s_node
{
	int				data;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	int		size;
	t_node	*top;
	t_node	*bottom;
}	t_stack;

typedef struct s_cmd
{
	int	count_ra;
	int	count_rb;
	int	count_pa;
	int	count_pb;
	int	count_origin;
	int	pivot_b;
	int	pivot_s;
}	t_cmd;

typedef struct s_vars
{	
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_alloc	*alloc;
}	t_vars;

//libft/ft_split.c
int			count_words(char const *s, char c);
//srcs/stack_init.c
t_stack		*init_stack(t_alloc **alloc);
t_cmd		*init_cmd(int count, t_alloc **alloc);
t_node		*init_node(int data, t_alloc **alloc);
//srcs/parsing.c
void		parsing(char **av, t_stack **stack_a, t_alloc **alloc);
//srcs/check.c
void		check_valid(char **av, t_alloc **alloc);
void		check_range(char **av, t_alloc **alloc);
void		check_overlap(int *arr, int size, t_alloc **alloc);
//srcs/utils.c
void		print_error(t_alloc **alloc);
int			is_space(char c);
long long	ft_atoi_long(const char *str);
void		free_all(t_alloc **alloc);
//srcs/sort_a.c
void		rotate_back(t_vars **vars, t_cmd *cmd);
void		a_to_b(t_vars **vars, int count);
//srcs/sort_b.c
void		two_sort_b(t_vars **vars);
void		b_to_a(t_vars **vars, int count);
//srcs/small_count_sort.c
int			is_sorted(t_stack **stack, int count);
int			is_b_sorted(t_vars **vars, int count);
void		five_count_sort(t_vars **vars);
//srcs/small_sort.c
int			get_max(t_stack **stack, int size);
int			get_min(t_stack **stack, int size);
void		three_count_sort(t_stack **stack, t_alloc **alloc);
void		three_sort(t_stack **stack, t_alloc **alloc);
//srcs/get_mid.c
void		insertion_sort(int *list, int n);
int			get_mid(t_stack **stack, int size, t_alloc **alloc);
//srcs/sort_utils.c
void		sa(t_stack *stack_a);
void		sb(t_stack *stack_b);
void		ss(t_stack *stack_a, t_stack *stack_b);
void		pa(t_stack *stack_a, t_stack *stack_b, t_alloc **alloc);
void		pb(t_stack *stack_a, t_stack *stack_b, t_alloc **alloc);
//srcs/sort_utils2.c
void		ra(t_stack *stack_a, t_alloc **alloc);
void		rb(t_stack *stack_b, t_alloc **alloc);
void		rr(t_stack *stack_a, t_stack *stack_b, t_alloc **alloc);
//srcs/sort_utils3.c
void		rra(t_stack *stack_a, t_alloc **alloc);
void		rrb(t_stack *stack_b, t_alloc **alloc);
void		rrr(t_stack *stack_a, t_stack *stack_b, t_alloc **alloc);
//srcs/stack_utils.c
void		on_top(t_stack *stack, int data, t_alloc **alloc);
void		on_bottom(t_stack *stack, int data, t_alloc **alloc);
void		no_top(t_stack *stack);
void		no_bottom(t_stack *stack);

#endif
